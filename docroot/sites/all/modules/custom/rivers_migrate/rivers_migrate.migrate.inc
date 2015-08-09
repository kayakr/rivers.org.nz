<?php
/**
 * @file
 * Declares our migrations.
 */


/**
 * Implements hook_migrate_api().
 */
function rivers_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'rivers' => array(
        'title' => t('rivers.org.nz Migrations'),
      ),
      'migrations' => array(),
    ),
  );

  // Specify the DB connection and the source Drupal version.
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 6,
    'group_name' => 'rivers',
    'format_mappings' => array(
      '0' => 'plain_text',
      '1' => 'filtered_html',
      //'2' => 'PHP',
      '3' => 'full_html',
    ),
  );

  $api['migrations']['RiversRole'] = $common_arguments + array(
      'description' => t('Import Drupal 6 roles'),
      'class_name' => 'DrupalRole6Migration'
      //'role_mappings' => array(
      //  'Fan Club' => 'fan club member',
      //),
    );

  // Register the user migration.
  $api['migrations']['RiversUser'] = $common_arguments + array(
      'description' => t('Migration of users from Drupal 6'),
      'class_name' => 'RiversDrupalUser6Migration',
      'role_migration' => 'RiversRole',
    );

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  db_set_active('legacy');
  $vocabs = db_select('vocabulary', 'v')
    ->fields('v', array('vid', 'name', 'description', 'hierarchy'))
    //->condition('vid', array(22, 23), 'NOT IN')
    ->execute();
  db_set_active();
  $vocabulary_arguments = array();
  while ($vocab = $vocabs->fetchAssoc()) {
    $name = 'RiversVocab' . ucwords(strtolower($vocab['name']));
    $name = str_replace(array(' ', '-', '&', '.'), '', $name);
    $machine_name = str_replace(array('-', '&', '.'), '', $vocab['name']);
    $machine_name = str_replace(array('  '), ' ', $machine_name);
    $machine_name = str_replace(array(' '), '_', $machine_name);

    switch ($vocab['name']) {
      case 'Forums':
        $destination_vocabulary = 'forums';
        break;
      case 'Tags':
        $destination_vocabulary = 'tags';
        break;
      default:
        $destination_vocabulary = 'rivers_' . strtolower($machine_name);
    }

    $vocabulary_arguments[$name] = array(
      'description' => t('Migration of @vocab terms from Drupal 6', array(
        '@vocab' => $vocab['name'],
      )),
      'source_name' => $vocab['name'],
      'source_description' => $vocab['description'],
      'source_hierarchy' => $vocab['hierarchy'],
      // D5 Vocabulary ID.
      'source_vocabulary' => $vocab['vid'],
      'destination_vocabulary' => $destination_vocabulary,
    );
  }

 /*
  $vocabulary_arguments = array(
    //'Category' => array(
    //  'description' => t('Migration of Category terms from Drupal 6'),
    //  'source_vocabulary' => '3',  // D6 Vocabulary ID
    //  'destination_vocabulary' => 'equitas_category',
    //),
    'Tags' => array(
      'description' => t('Migration of Tags terms from Drupal 6'),
      'source_vocabulary' => '2',  // D6 Vocabulary ID
      'destination_vocabulary' => 'tags',
    ),
  );*/
  $common_vocabulary_arguments = $common_arguments + array(
      'class_name' => 'DrupalTerm6Migration',
      //'soft_dependencies' => array('RiversUser'),
    );
  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }

  // Migrate Files from legacy private to D7 public dir.
  // @todo: public & private files?
  $file_arguments = $common_arguments + array(
      'class_name' => 'DrupalFile6Migration',
      'description' => t('Import Drupal 6 files'),
      'user_migration' => 'RiversUser',
      'default_uid' => 1,
      'source_dir' => '', //'/Users/jonathan/Sites/drupal-6.36',
      'destination_dir' => 'public://',
    );
  $api['migrations']['RiversFile'] = $file_arguments;

  // Nodes.
  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    'RiversNodeArticle' => array(
      'class_name' => 'RiversArticleDrupalNode6Migration',
      'description' => t('Migration of article nodes from Drupal 6'),
      'source_type' => 'article',
      'destination_type' => 'article',
    ),
    'RiversNodeForumTopic' => array(
      'class_name' => 'RiversForumTopicDrupalNode6Migration',
      'description' => t('Migration of forum topic nodes from Drupal 6'),
      'source_type' => 'forum',
      'destination_type' => 'forum',
    ),
    'RiversNodePage' => array(
      'class_name' => 'RiversPageDrupalNode6Migration',
      'description' => t('Migration of page nodes from Drupal 6'),
      'source_type' => 'page',
      'destination_type' => 'page',
    ),
    'RiversNodeStory' => array(
      'class_name' => 'RiversStoryDrupalNode6Migration',
      'description' => t('Migration of story nodes from Drupal 6'),
      'source_type' => 'story',
      'destination_type' => 'rivers_story',
    ),

 //   'EquitasNodeDocumentRevision' => array(
 //     'class_name' => 'EquitasDrupalNodeRevision6Migration',
 //     'description' => t('Migration of document node revisions from Drupal 6'),
 //     'source_type' => 'document',
 //     'destination_type' => 'equitas_document',
 //   ),
  );

  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'RiversUser',
      'default_uid' => '1',
      'dependencies' => array('RiversUser', 'RiversVocabTopic', 'RiversFile'),
    );

  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  return $api;
}
