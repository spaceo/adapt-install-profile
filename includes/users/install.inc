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

/**
 * Start
 */
function _adapt_install_profile_users_start() {
  // Import settings
  $profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
  require($profile_base_path . "/includes/users/settings.inc");

  // Create new roles
  _adapt_install_profile_create_roles($roles, $permissions);

  // Set permissions
  _adapt_install_profile_set_permissions($general_permissions);

  // Create users
  // TODO
}

/**
 * Create new roles
 */
function _adapt_install_profile_create_roles($roles) {
  $rids = variable_get('adapt_rids', array());

  foreach ($roles as $role) {
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
    }

    // Set role id for later use, we'll need it when setting permissions in other
    // install plugins
    $rids[$newrole->name] = $newrole->rid;
  }

  variable_set('adapt_rids', $rids);
}

