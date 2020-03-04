<?php

/**
 * @file
 * rivers_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rivers_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rivers_blocks_d7';
  $context->description = 'Show blocks for D7 site';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'rivers_blocks-whitewater_nz' => array(
          'module' => 'rivers_blocks',
          'delta' => 'whitewater_nz',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show blocks for D7 site');
  $export['rivers_blocks_d7'] = $context;

  return $export;
}
