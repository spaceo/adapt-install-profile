<?php

/**
 * @file:
 * Do all the standard configuration for existing content types, define new
 * content types.
 */

// Import settings
$profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
require_once($profile_base_path . "/includes/settings/adapt_install_profile.content_types.settings.inc");
