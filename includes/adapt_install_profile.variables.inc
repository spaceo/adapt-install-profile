<?php

/**
 * @file:
 * Sets variables and default settings for the modules defined in
 * _adapt_install_profile_users_start() that aren't already handled.
 *
 * Should only be the modules defined in the .info file of the install profile.
 * All the rest should handle its own variable setting.
 */

function _adapt_install_profile_users_start() {
  // List of modules you want to set variables for.
  $modules = array(
    'pathauto',
    'system',
  );

  foreach ($modules as $modules) {
    $fn = "_set_variables_{$module}";

    if (function_exists($fn)) {
      call_user_func($fn);
    }
  }
}

/**
 * Set pathauto variables
 */
function _set_variables_pathauto() {
  if (module_exists('pathauto')) {
    // Disables the removing of the slash when creating an alias.
    variable_set('pathauto_punctuation_slash', 2);
    variable_set('pathauto_taxonomy_term_pattern', "[term:vocabulary]/[term:parents:join:/]/[term:name]");
  }
}

/**
 * Set System variables & settings
 */
function _set_variables_system() {
  // Enable seven and set it as admin theme
  theme_enable(array('seven'));
  variable_set('admin_theme', 'seven');
  variable_set('node_admin_theme', 1);

  // Disable this so we don't get the "choose timezone" on user register/edit forms
  variable_set('configurable_timezones', 0);
}
