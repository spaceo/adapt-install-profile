<?php

/**
 * @file:
 * Do all the standard configuration for existing content types, define new
 * content types.
 */

/**
 * Start
 */
function _adapt_install_profile_content_types_start() {
  // Import settings
  $profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
  require($profile_base_path . "/includes/content_types/settings.inc");

  // Save content types
  _adapt_install_profile_create_content_types($content_types);

  // Set options for content types
  _adapt_install_profile_set_content_types_options($content_types_options);
}

/**
 * Create content types
 */
function _adapt_install_profile_create_content_types($types) {
  foreach ($types as $type) {
    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type);
  }
}

/**
 * Set content types options
 */
function _adapt_install_profile_set_content_types_options($options) {
  foreach ($options as $variable => $value) {
    variable_set($variable, $value);
  }
}
