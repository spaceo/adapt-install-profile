<?php

/**
 * @file:
 * Variables
 */

$admin_theme = 'seven';

// Define all variables per module
$variables = array(
  'pathauto' => array(
    // Disables the removing of the slash when creating an alias.
    'pathauto_punctuation_slash' => 2,
    'pathauto_taxonomy_term_pattern' => '[term:vocabulary]/[term:parents:join:/]/[term:name]',
    ),

  // System variables also includes general settings that are not tied to the system module, per se
  'system' => array(
    'admin_theme' => $admin_theme,
    'node_admin_theme' => 1,
    // Disable this so we don't get the "choose timezone" on user register/edit forms
    'configurable_timezones' => 0,
    ),
  );

