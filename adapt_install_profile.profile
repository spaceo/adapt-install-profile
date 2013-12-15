<?php

// @var CONST
// Define path to Install Profile
$profile_base_path = drupal_get_path('profile', 'adapt_install_profile');
define('INSTALL_PROFILE_PATH', $profile_base_path);

/**
 * Implements hook_menu().
 */
function adapt_install_profile_menu() {
  $items = array();

  $items['admin/adapt-install-profile-settings'] = array(
    'title' => 'Adapt Install Profile settings',
    'description' => 'Adapt Install Profile settings',
    'page callback' => 'drupal_get_form',
    // This page should only be available for the super user
    'page arguments' => array('adapt_install_profile_settings_form'),
    'access callback' => '_adapt_install_profile_is_super_user',
    'type' => MENU_CALLBACK,
    );

  return $items;
}

/**
 * Implements hook_form_install_configure_form_alter().
 */
function adapt_install_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Import variable settings
  require(INSTALL_PROFILE_PATH . "/includes/variables/settings.inc");
  
  $form['site_information']['site_name']['#default_value'] = $site_name;
  $form['site_information']['site_mail']['#default_value'] = $site_mail;
  $form['server_settings']['site_default_country']['#default_value'] = $site_default_country;
}

/**
 * Implements hook_install_tasks_alter()
 */
function adapt_install_profile_install_tasks_alter(&$tasks, $install_state) {
  // Overwrite this with our own function where we'll add stuff.
  $tasks['install_finished']['function'] = '_adapt_install_profile_install_finished';
  $tasks['install_select_locale']['function'] = '_adapt_install_profile_select_locale';
}

/**
 * Implements hook_form().
 * This is the Basic Settings form
 */
function adapt_install_profile_settings_form($node, &$form_state) {
  // Import language settings
  require(INSTALL_PROFILE_PATH . "/includes/languages/settings.inc");

  // Build the languages array.
  // The default language object is stored in the language_default variable.
  $langs = drupal_map_assoc(array(
    'da',
    'en'
    ));
  $default_lang = variable_get('language_default', (object) array('language' => $default_language['langcode']));
  $enabled_langs = @array_keys(reset(language_list('enabled')));

  // Build the form.
  $form = array();

  $form['languages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Languages'),
    '#collapsible' => FALSE,
    );

  $form['languages']['active_languages'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Which languages would you like to enable?'),
    '#options' => array_diff($langs, $enabled_langs),
    '#description' => t('<strong>Enabled language(s):</strong><br />@langs<br /><br /><strong>Default language:</strong><br />@def_lang', array(
      '@langs' => implode(', ', $enabled_langs),
      '@def_lang' => $default_lang->language,
      )),
    );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    );

  return $form;
}

/**
 * Form submit handler for Basic Settings form.
 */
function adapt_install_profile_settings_form_submit($node, &$form_state) {
  // Handle the languages section
  _adapt_install_profile_settings_language_submit_handler($form_state['values']['active_languages']);

  // More stuff to follow

  $form_state['redirect'] = '';

  // clear all caches after settings completion
  cache_clear_all();
}

/**
 * Handles the languages part of the Basic Settings submit.
 */
function _adapt_install_profile_settings_language_submit_handler($languages) {
  // Language counter is used to define if i18n needs to be enabled
  // and to set the language_count variable.
  $enabled_count = 1;
  foreach ($languages as $langcode => $name) {
    if ($name === 0) {
      continue;
    }

    // Enable the language
    if (!array_key_exists($langcode, language_list())) {
      locale_add_language($langcode);
    } else {
      // Update an existing language, can be done with a simple query
      // @see locale_languages_overview_form_submit
      db_update('languages')
      ->fields(array(
        'enabled' => 1,
        ))
      ->condition('language', $langcode)
      ->execute();
    }
    // And update the language counter
    $enabled_count++;
  }

  variable_set('language_count', $enabled_count);
  // Changing the language settings impacts the interface.
  cache_clear_all();
  module_invoke_all('multilingual_settings_changed');
}

/**
 * hook_install_tasks_alter() callback
 *
 * Execute finish tasks and redirect to settings form
 * Most stuff is copied from https://api.drupal.org/api/drupal/includes%21install.core.inc/function/install_finished/7
 */
function _adapt_install_profile_install_finished(&$install_state) {
  drupal_set_title(st('@drupal installation complete', array('@drupal' => drupal_install_profile_distribution_name())), PASS_THROUGH);
  $messages = drupal_set_message();
  $output = '<p>' . st('Congratulations, you installed @drupal!', array('@drupal' => drupal_install_profile_distribution_name())) . '</p>';

  if (isset($messages['error'])) {
    $output .= "<p>" . st('Review the messages above before visiting <a href="@url">your new site</a>.', array('@url' => url(''))) . "</p>";
  } else {
    $output .= "<p>" . st('<a href="@url">Visit your new site</a>.', array('@url' => url(''))) . "</p>";
    $output .= "<p>" . st('<a href="@url">Go to the settings page</a>.', array('@url' => url('admin/adapt-install-profile-settings'))) . "</p>";
  }

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the installation profile are registered correctly.
  drupal_flush_all_caches();

  // Remember the profile which was used.
  variable_set('install_profile', drupal_get_profile());

  // Installation profiles are always loaded last
  db_update('system')->fields(array('weight' => 1000))->condition('type', 'module')->condition('name', drupal_get_profile())->execute();

  // Cache a fully-built schema.
  drupal_get_schema(NULL, TRUE);

  // Run cron to populate update status tables (if available) so that users
  // will be warned if they've installed an out of date Drupal version.
  // Will also trigger indexing of profile-supplied content or feeds.
  drupal_cron_run();

  return $output;
}

/**
 * hook_install_tasks_alter callback
 *
 * Don't show the language selection form, select our own default language
 */
function _adapt_install_profile_select_locale(&$install_state) {
  // Import language settings
  require(INSTALL_PROFILE_PATH . "/includes/languages/settings.inc");

  $install_state['parameters']['locale'] = $default_language['langcode'];

  return;
}

/**
 * Determine if current user is Super User, e.a. uid 1.
 */
function _adapt_install_profile_is_super_user() {
  global $user;

  if ($user->uid == 1) {
    return TRUE;
  }

  return FALSE;
}

/**
 *
 */
