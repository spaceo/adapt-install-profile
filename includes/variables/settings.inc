<?php

/**
 * @file:
 * Variables
 */

$admin_theme = 'seven';
$site_mail = 'info@adapt.dk';
$site_name = 'Adapt Install Profile';
$site_default_country = 'DK';

// Define all variables per module
$variables = array(
  'jquery_update' => array(
    'jquery_update_compression_type' => 'none',
    'jquery_update_jquery_cdn' => 'google',
    'jquery_update_jquery_version' => '1.7',
    ),

  'pathauto' => array(
    // Disables the removing of the slash when creating an alias.
    'pathauto_punctuation_slash' => 2,
    'pathauto_taxonomy_term_pattern' => '[term:vocabulary]/[term:parents:join:/]/[term:name]',
    ),

  // System variables also includes general settings that are not tied to the system module, per se
  'system' => array(
    'admin_theme' => $admin_theme,
    // Disable this so we don't get the "choose timezone" on user register/edit forms
    'configurable_timezones' => 0,
    'node_admin_theme' => 1,
    // Register only for admins
    'user_register' => 0,
    ),
  );

