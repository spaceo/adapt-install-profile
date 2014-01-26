<?php
/**
 * @file
 * adapt_users_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function adapt_users_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  return $roles;
}
