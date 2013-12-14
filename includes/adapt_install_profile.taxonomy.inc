<?php

/**
 * @file:
 * Do all the standard configuration for vocabularies and taxonomy terms
 */

// Import settings
$profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
require_once($profile_base_path . "/includes/settings/adapt_install_profile.taxonomy.settings.inc");

/**
 * Implements hook_entity_info_alter()
 */
function adapt_install_profile_entity_info_alter(&$entity_info) {
  // Define a teaser View Mode for taxonomy terms
  // Probably not a good place for this because this only gets run once
  $entity_info['taxonomy_term']['view modes']['teaser'] = array(
    'label' => t('Teaser'),
    'custom settings' => TRUE,
  );
}
