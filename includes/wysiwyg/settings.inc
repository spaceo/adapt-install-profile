<?php

/**
 * @file:
 * Settings for wysiwyg
 */

// Define all text formats and their filters
$text_formats = array(
  'filtered_html' => (object) array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // CkEditor Link
      'ckeditor_link_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
        ),
      // URL filter.
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        ),
       // HTML filter.
      'filter_html' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a><em><strong><cite><blockquote><code><ul><ol><li><dl><dt><dd><img><h1><h2><h3><h4><p><span><br><table><tr><td><tbody><iframe>'
          )
        ),
       // Line break filter.
      'filter_autop' => array(
        'weight' => 3,
        'status' => 1,
        ),
       // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        ),
      ),
    ),
  );

// Define Wysiwyg settings per text format
$wysiwyg_settings = array(
  'filtered_html' => array(
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 1,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Image' => 1,
          'Superscript' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'Format' => 1,
          'Table' => 1,
          'Iframe' => 1,
          ),
        'drupal_path' => array(
          'Link' => 1,
          ),
        ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4,div',
      'css_setting' => 'self',
      'css_path' => '%t/css/editor.css',
      'css_classes' => '',
      )
),
);
