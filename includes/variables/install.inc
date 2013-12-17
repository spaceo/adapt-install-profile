<?php

/**
 * @file:
 * Sets variables and default settings for the modules used in this install
 * profile that aren't already handled by plugins.
 *
 * Should only be the modules defined in the .info file of the install profile.
 * All the rest should handle its own variable setting.
 */

/**
 * Start
 */
function _adapt_install_profile_variables_start() {
  // Import settings
  $profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
  require($profile_base_path . "/includes/variables/settings.inc");

  // Enable admin theme
  theme_enable(array($admin_theme));

  foreach ($variables as $module => $variable_array) {
    if (!module_exists($module)) {
      continue;
    }

    foreach ($variable_array as $variable => $value) {
      variable_set($variable, $value);
    }
  }
}
