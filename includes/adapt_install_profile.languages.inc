<?php

/**
 * @file:
 * Set up all the languages stuff
 */

/**
 * Start
 */
function _adapt_install_profile_languages_start() {
  // Import settings
  $profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
  require($profile_base_path . "/includes/settings/adapt_install_profile.languages.settings.inc");

  // Set default language
  _adapt_install_profile_set_default_language($default_language);
}

/**
 * Set default language
 */
function _adapt_install_profile_set_default_language($default_language) {
  // If $default_language is not enabled, do so now
  if (!array_key_exists($default_language['langcode'], language_list())) {
    locale_add_language($default_language['langcode'], $default_language['name'], $default_language['native'], $default_language['direction'], $default_language['domain'], $default_language['prefix'], TRUE, TRUE);

    // TODO : Upload .po file

    cache_clear_all();
  }

  // because we use a different default language we have to change the path
  // prefix for the default lang and English language.
  db_update('languages')
  ->fields(array(
    'prefix' => "",
    ))
  ->condition('language', $default_language['langcode'])
  ->execute();

  db_update('languages')
  ->fields(array(
    'prefix' => "en",
    'enabled' => (int) FALSE,
    ))
  ->condition('language', 'en')
  ->execute();
}
