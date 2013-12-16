<?php

/**
 * @file:
 * Settings for content types
 */

// Definition of Content Types
$content_types = array(
  'page' => array(
    'type' => 'page',
    'name' => st('Page'),
    'base' => 'node_content',
    'description' => st("Use <em>basic pages</em> for your static content, such as an 'About us' page."),
    'custom' => 1,
    'modified' => 1,
    'locked' => 0,
    ),
  );

// Options (variables) for Content Types.
$content_types_options = array(
  // Default "Basic page" to not be promoted and have comments disabled.
  'node_options_page' => array('status'),
  // Don't display date and author information for "Basic page" nodes by default.
  'node_submitted_page' => FALSE
  );
