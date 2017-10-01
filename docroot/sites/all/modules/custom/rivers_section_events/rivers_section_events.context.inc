<?php
/**
 * @file
 * rivers_section_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rivers_section_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_blocks';
  $context->description = 'Show upcoming events for Section';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'section' => 'section',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-section_events-block' => array(
          'module' => 'views',
          'delta' => 'section_events-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show upcoming events for Section');
  $export['section_blocks'] = $context;

  return $export;
}
