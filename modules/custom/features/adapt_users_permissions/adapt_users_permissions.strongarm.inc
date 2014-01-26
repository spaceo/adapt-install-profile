<?php
/**
 * @file
 * adapt_users_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function adapt_users_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'adapt_rids';
  $strongarm->value = array(
    'administrator' => '3',
    'editor' => '4',
  );
  $export['adapt_rids'] = $strongarm;

  return $export;
}
