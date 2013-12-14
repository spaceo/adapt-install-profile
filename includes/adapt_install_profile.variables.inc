<?php

/**
 * @file:
 * Sets variables and default settings for the modules defined in
 * _adapt_install_profile_variables_start() that aren't already handled.
 *
 * Should only be the modules defined in the .info file of the install profile.
 * All the rest should handle its own variable setting.
 */

/**
 * Start
 */
function _adapt_install_profile_variables_start() {
  // Import settings
  require_once(INSTALL_PROFILE_PATH . "/includes/settings/adapt_install_profile.variables.settings.inc");

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
