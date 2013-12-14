<?php

/**
 * @file:
 * Settings for different roles & permissions
 *
 * If you want to define permissions for any role you wish to add in the $roles array,
 * you should define them in a _adapt_install_profile_permissions_[roleName] function
 */

$roles = array(
  0 => array('name' => 'administrator', 'weight' => 3),
  1 => array('name' => 'editor', 'weight' => 4),
  );

/**
 * Define permissions for Anonymous User
 */
function _adapt_install_profile_permissions_anon() {
  return array(
    'access content',
    'search content'
    );
}

/**
 * Define permissions for Authenticated User
 */
function _adapt_install_profile_permissions_auth() {
  return array(
    'access content',
    'search content'
    );
}

/**
 * Define permissions for Editor
 */
function _adapt_install_profile_permissions_editor() {
  return array(
    'access content',
    'search content'
    );
}

/**
 * Define permissions for Administrator
 */
function _adapt_install_profile_permissions_administrator() {
  return array(
    // admin_menu
    'access administration menu',
    'flush caches',
    // blocks
    'administer blocks',
    // contextual links
    'access contextual links',
    // dashboard
    'access dashboard',
    // googleanalytics
    'administer google analytics',
    'opt-in or out of tracking',
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
    );
}
