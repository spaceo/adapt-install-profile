<?php

/**
 * @file:
 * Set up all the languages stuff
 */

function _adapt_install_profile_languages_start() {
  // If Danish is not enabled, do so now
  if (!array_key_exists('da', language_list())) {
    locale_add_language("da", "Danish", "Dansk", LANGUAGE_LTR, '', '', TRUE, TRUE);

    // TODO : Upload .po file

    cache_clear_all();
  }

  // because we use Danish as default language we have to change the path
  // prefix for the Danish and English languages.
  db_update('languages')
  ->fields(array(
    'prefix' => "",
    ))
  ->condition('language', 'da')
  ->execute();

  db_update('languages')
  ->fields(array(
    'prefix' => "en",
    'enabled' => (int) FALSE,
    ))
  ->condition('language', 'en')
  ->execute();
}
