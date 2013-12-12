<?php

/**
 * @file:
 * Do all the standard configuration for vocabularies and taxonomy terms
 */

/**
 * Implements hook_entity_info_alter()
 */
function adapt_install_profile_entity_info_alter(&$entity_info) {
  // Define a teaser View Mode for taxonomy terms
  $entity_info['taxonomy_term']['view modes']['teaser'] = array(
    'label' => t('Teaser'),
    'custom settings' => TRUE,
  );
}
