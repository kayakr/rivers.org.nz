<?php
/**
 * @file
 * rivers_site.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function rivers_site_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rivers_footer';
  $context->description = 'Footer blocks for rivers.org.nz';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-rivers-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-rivers-footer-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'rivers_site-rivers_copyright' => array(
          'module' => 'rivers_site',
          'delta' => 'rivers_copyright',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Footer blocks for rivers.org.nz');
  $export['rivers_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rivers_homepage';
  $context->description = 'Homepage blocks other than top bar, footer';
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
        'views-rivers_news-latest_news' => array(
          'module' => 'views',
          'delta' => 'rivers_news-latest_news',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-rivers_calendar-block_2' => array(
          'module' => 'views',
          'delta' => 'rivers_calendar-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage blocks other than top bar, footer');
  $export['rivers_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'rivers_top_bar';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'navigation',
          'weight' => '-16',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'navigation',
          'weight' => '-15',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['rivers_top_bar'] = $context;

  return $export;
}
