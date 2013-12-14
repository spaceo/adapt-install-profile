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

// Import settings
$profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
require_once($profile_base_path . "/includes/settings/adapt_install_profile.users.settings.inc");

/**
 * Start
 */
function _adapt_install_profile_users_start() {
  // Create new roles
  _adapt_install_profile_roles_create($roles);

  // Grant permissions for anonymous & authenticated users
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, _adapt_install_profile_permissions_anon());
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, _adapt_install_profile_permissions_auth());

  // Create users
  // TODO
}

/**
 * Create new roles and grant their permissions
 */
function _adapt_install_profile_roles_create($roles) {
  foreach ($roles as $role) {
    $fn = '_adapt_install_profile_permissions_' . $role['name'];

    if (function_exists($fn)) {
      $permissions = call_user_func($fn);
    }
    else {
      $permissions = array();
    }

    $newrole = new stdClass();
    $newrole->name = $role['name'];
    $newrole->weight = $role['weight'];
    user_role_save($newrole);

    // Special love for the admin role
    if ($role['name'] == 'administrator') {
      // Assign user 1 the "administrator" role.
      db_insert('users_roles')
      ->fields(array('uid' => 1, 'rid' => $newrole->rid))
      ->execute();

      // Set the administrator role.
      variable_set('user_admin_role', $newrole->rid);

      // Todo: set permissions for admin role
      // Somehow it won't work through user_role_grant_permissions()
    }
    else {
      user_role_grant_permissions($newrole->rid, $permissions);
    }
  }
}
