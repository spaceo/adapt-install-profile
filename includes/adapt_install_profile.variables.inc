<?php

/**
 * @file:
 * Sets variables and default settings for the modules defined in
 * _adapt_install_profile_variables_start() that aren't already handled.
 *
 * Should only be the modules defined in the .info file of the install profile.
 * All the rest should handle its own variable setting.
 */

// Import settings
$profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
require_once($profile_base_path . "/includes/adapt_install_profile.variables.settings.inc");

/**
 * Start
 */
function _adapt_install_profile_variables_start() {
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
