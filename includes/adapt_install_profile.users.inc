<?php

function _adapt_install_profile_users_start() {
  // Create new roles
  $roles = array(
    _adapt_install_profile_roles_create('superuser', _adapt_install_profile_permissions_superuser(), 3),
    _adapt_install_profile_roles_create('editor', _adapt_install_profile_permissions_editor(), 4),
    );

  // Grant permissions for anonymous & authenticated users
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, _adapt_install_profile_permissions_anon());
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, _adapt_install_profile_permissions_auth());
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
 * Define permissions for Superuser
 */
function _adapt_install_profile_permissions_superuser() {
  return array(
    'access administration menu',
    'flush caches',
    'access content',
    'search content',
    'access contextual links',
    'access dashboard',
    'use text format full_html',
    'access content overview',
    'view own unpublished content',
    'create page content',
    'edit any page content',
    'delete any page content',
    'access administration pages',
    'access site in maintenance mode',
    'view the administration theme',
    );
}
