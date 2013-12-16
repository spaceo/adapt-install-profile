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
  require($profile_base_path . "/includes/languages/settings.inc");

  // Set default language
  _adapt_install_profile_set_default_language($default_language);
}
