<?php

/**
 * @file:
 * Adjust text formats and configure Wysiwyg settings
 */

/**
 * Start
 */
function _adapt_install_profile_wysiwyg_start() {
  // Import settings
  $profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
  require($profile_base_path . "/includes/wysiwyg/settings.inc");

  // Save text formats
  _adapt_install_profile_save_text_formats($text_formats);

  // Set Wysiwyg settings
  _adapt_install_profile_set_wysiwyg_settings($wysiwyg_settings);

  // Set variables
  _adapt_install_profile_set_variables($wysiwyg_options);

  // Set permissions
  _adapt_install_profile_set_permissions($wysiwyg_permissions);
}

/**
 * Save text formats
 */
function _adapt_install_profile_save_text_formats($formats) {
  foreach ($formats as $format) {
    filter_format_save($format);
  }
}

/**
 * Set wysiwyg settings per text format
 */
function _adapt_install_profile_set_wysiwyg_settings($settings) {
  foreach ($settings as $format => $array) {
    $fields = array(
      'format' => $format,
      'editor' => $array['editor'],
      'settings' => serialize($array['settings']),
      );

    db_insert('wysiwyg')
    ->fields($fields)
    ->execute();
  }

  wysiwyg_profile_cache_clear();
}
