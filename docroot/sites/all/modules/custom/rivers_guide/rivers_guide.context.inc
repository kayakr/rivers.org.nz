<?php
/**
 * @file
 * rivers_guide.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rivers_guide_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rivers_guide__editor';
  $context->description = 'Show blocks on Rivers Guide Section edit';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/section' => 'node/add/section',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'rivers_guide-rivers_guide_editor_intro' => array(
          'module' => 'rivers_guide',
          'delta' => 'rivers_guide_editor_intro',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show blocks on Rivers Guide Section edit');
  $export['rivers_guide__editor'] = $context;

  return $export;
}
