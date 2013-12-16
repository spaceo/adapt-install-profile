<?php

/**
 * @file:
 * Settings for different roles & permissions
 *
 * If you want to define permissions for any role you wish to add in the $roles array,
 * you should define them in a adapt_install_profile_permissions_[roleName] variable
 */

// Any *new* roles you wish to add
$roles = array(
  0 => array('name' => 'administrator', 'weight' => 3),
  1 => array('name' => 'editor', 'weight' => 4),
);

// Permissions for *all* roles, including standard Drupal roles
// name in $roles array and key in $permissions array must be identical.
$permissions = array(
  'anonymous' => array(
    // Search
    'access content',
    'search content'
  ),
  'authenticated' => array(
    // Search
    'access content',
    'search content'
  ),
  'editor' => array(
    // ckeditor
    'access ckeditor link',
    // search
    'access content',
    'search content',
    // text formats
    'use text format filtered_html',
  ),
  'administrator' => array(
    // admin_menu
    'access administration menu',
    'flush caches',
    // blocks
    'administer blocks',
    // ckeditor
    'access ckeditor link',
    // contextual links
    'access contextual links',
    // dashboard
    'access dashboard',
    // googleanalytics
    //'administer google analytics',
    //'opt-in or out of tracking',
    // locale
    'translate interface',
    // menu
    'administer menu',
    // node
    'administer nodes',
    'access content overview',
    'view own unpublished content',
    'create page content',
    'edit any page content',
    'delete any page content',
    // path
    'administer url aliases',
    'create url aliases',
    // system
    'access administration pages',
    'access site in maintenance mode',
    'view the administration theme',
    // taxonomy
    'administer taxonomy',
    // text formats
    'use text format filtered_html',
  ),
);
