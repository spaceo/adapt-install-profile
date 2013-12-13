<?php

/**
 * @file:
 * Create roles & set permissions.
 *
 * Should only be for the modules defined in the .info file of the install profile.
 * All the rest should handle its own permission setting.
 *
 * Caution, any permission you want to set must also have its module enabled,
 * otherwise we'll get errors on install.
 */

function _adapt_install_profile_users_start() {
  // Create new roles
  // Admin role can't have its permissions set the normal way
  $admin = _adapt_install_profile_roles_create('administrator', array_keys(module_invoke_all('permission')), 3);
  $editor = _adapt_install_profile_roles_create('editor', _adapt_install_profile_permissions_editor(), 4);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin->rid))
    ->execute();

  // Set the administrator role.
  variable_set('user_admin_role', $admin->rid);

  // Grant permissions for anonymous & authenticated users
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, _adapt_install_profile_permissions_anon());
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, _adapt_install_profile_permissions_auth());

  // Create users
  // TODO
}

/**
 * Create new roles and grant their permissions
 */
function _adapt_install_profile_roles_create($name, $permissions = array(), $weight = 2) {
  $role = new stdClass();
  $role->name = $name;
  $role->weight = $weight;
  user_role_save($role);
  user_role_grant_permissions($role->rid, $permissions);

  return $role;
}

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
