<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function basetheme_form_system_theme_settings_alter(&$form, &$form_state) {
  // Create own settings
  $basetheme_settings = array(
    '#type' => 'fieldset',
    '#title' => t('Basetheme settings'),

    'css_to_keep' => array(
      '#type' => 'textarea',
      '#title' => t('CSS to keep'),
      '#description' => t('Enter the CSS files you wish to keep. Enter one filename per line. CSS from your own theme cannot be stripped.'),
      '#default_value' => theme_get_setting('css_to_keep'),
      ),

    'js_overload' => array(
      '#type' => 'textfield',
      '#title' => t('Overload jQuery'),
      '#description' => t('Overload jQuery with a newer version than Drupal\'s 1.4.4. Do this at your own risk and only when absolutely necessary, as it might cause problems with Drupal core functionality'),
      '#size' => 8,
      '#maxlength' => 10,
      '#default_value' => theme_get_setting('js_overload'),
      ),

    'js_to_strip' => array(
      '#type' => 'textarea',
      '#title' => t('JS to strip'),
      '#description' => t('Enter the JS files you wish to strip. Enter one filename per line. JS from your own theme cannot be stripped.'),
      '#default_value' => theme_get_setting('js_to_strip'),
      ),
    );

  // Add settings to beginning of array
  $form = array_reverse($form);
  $form['basetheme_settings'] = $basetheme_settings;
  $form = array_reverse($form);
}
