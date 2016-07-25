<?php
/**
 * @file
 * rivers_guide.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function rivers_guide_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'comment_body'.
  $field_bases['comment_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'comment',
    ),
    'field_name' => 'comment_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_alternate_name'.
  $field_bases['field_alternate_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_alternate_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 200,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_character'.
  $field_bases['field_character'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_character',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_class'.
  $field_bases['field_class'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_class',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 'I',
        '1.25' => 'I+',
        '1.5' => 'I-II',
        '1.6' => 'I-II+',
        '1.75' => 'II-',
        2 => 'II',
        '2.15' => 'II-II+',
        '2.2' => 'II (III)',
        '2.22' => 'II (IV)',
        '2.25' => 'II+',
        '2.3' => 'II+ (III)',
        '2.5' => 'II-III',
        '2.55' => 'II-III (IV)',
        '2.6' => 'II-III+',
        '2.7' => 'II-III+ (IV)',
        '2.75' => 'III-',
        '2.9' => 'II-IV',
        3 => 'III',
        '3.1' => 'III-III+',
        '3.2' => 'III (IV)',
        '3.22' => 'III (IV+)',
        '3.25' => 'III+',
        '3.26' => 'III+ (IV-)',
        '3.3' => 'III+ (IV)',
        '3.5' => 'III-IV',
        '3.55' => 'III-IV (V)',
        '3.6' => 'III+-IV-',
        '3.65' => 'III+-IV',
        '3.7' => 'III-IV+',
        '3.75' => 'IV-',
        4 => 'IV',
        '4.02' => 'IV (IV+)',
        '4.05' => 'III, IV-IV+',
        '4.1' => 'IV-IV+',
        '4.2' => 'IV (V)',
        '4.25' => 'IV+',
        '4.27' => 'IV+ (V-)',
        '4.3' => 'IV+ (V)',
        '4.5' => 'IV-V',
        '4.55' => 'IV-V (VI-)',
        '4.6' => 'IV+-V',
        '4.61' => 'IV-V+',
        '4.75' => 'V-',
        '4.9' => 'IV-VI',
        5 => 'V',
        '5.1' => 'V (VI)',
        '5.2' => 'V-V+',
        '5.25' => 'V+',
        '5.5' => 'V-VI',
        '5.75' => 'VI-',
        6 => 'VI',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_credits'.
  $field_bases['field_credits'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_credits',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_downstream_of'.
  $field_bases['field_downstream_of'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_downstream_of',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'book' => 0,
        'event' => 0,
        'forum' => 0,
        'gauge' => 0,
        'image' => 0,
        'page' => 0,
        'section' => 'section',
        'story' => 0,
        'submission' => 0,
        'submission_template' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(
          0 => '',
        ),
        'display_name' => 'default',
        'view_name' => 'list_of_sections',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_gauge'.
  $field_bases['field_gauge'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gauge',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_gauge_niwa'.
  $field_bases['field_gauge_niwa'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gauge_niwa',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'book' => 0,
        'event' => 0,
        'forum' => 0,
        'gauge' => 'gauge',
        'image' => 0,
        'page' => 0,
        'section' => 0,
        'story' => 0,
      ),
      'view' => array(
        'args' => array(
          0 => '',
        ),
        'display_name' => 'default',
        'view_name' => '--',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_geojson'.
  $field_bases['field_geojson'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_geojson',
    'indexes' => array(
      'bbox' => array(
        0 => 'top',
        1 => 'bottom',
        2 => 'left',
        3 => 'right',
      ),
      'bottom' => array(
        0 => 'bottom',
      ),
      'centroid' => array(
        0 => 'lat',
        1 => 'lon',
      ),
      'geohash' => array(
        0 => 'geohash',
      ),
      'lat' => array(
        0 => 'lat',
      ),
      'left' => array(
        0 => 'left',
      ),
      'lon' => array(
        0 => 'lon',
      ),
      'right' => array(
        0 => 'right',
      ),
      'top' => array(
        0 => 'top',
      ),
    ),
    'locked' => 0,
    'module' => 'geofield',
    'settings' => array(
      'backend' => 'default',
      'srid' => 4326,
    ),
    'translatable' => 0,
    'type' => 'geofield',
  );

  // Exported field_base: 'field_gradient'.
  $field_bases['field_gradient'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gradient',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'decimal_separator' => '.',
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'm/km',
    ),
    'translatable' => 0,
    'type' => 'number_float',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_history'.
  $field_bases['field_history'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_history',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_hot_tip'.
  $field_bases['field_hot_tip'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hot_tip',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_length'.
  $field_bases['field_length'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_length',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'decimal_separator' => '.',
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => 'km',
    ),
    'translatable' => 0,
    'type' => 'number_float',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_level'.
  $field_bases['field_level'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_level',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_location'.
  $field_bases['field_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_location',
    'indexes' => array(
      'bbox' => array(
        0 => 'top',
        1 => 'bottom',
        2 => 'left',
        3 => 'right',
      ),
      'bottom' => array(
        0 => 'bottom',
      ),
      'centroid' => array(
        0 => 'lat',
        1 => 'lon',
      ),
      'geohash' => array(
        0 => 'geohash',
      ),
      'lat' => array(
        0 => 'lat',
      ),
      'left' => array(
        0 => 'left',
      ),
      'lon' => array(
        0 => 'lon',
      ),
      'right' => array(
        0 => 'right',
      ),
      'top' => array(
        0 => 'top',
      ),
    ),
    'locked' => 0,
    'module' => 'geofield',
    'settings' => array(
      'backend' => 'default',
      'srid' => 4326,
    ),
    'translatable' => 0,
    'type' => 'geofield',
  );

  // Exported field_base: 'field_map_region'.
  $field_bases['field_map_region'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_region',
    'indexes' => array(
      'bbox' => array(
        0 => 'top',
        1 => 'bottom',
        2 => 'left',
        3 => 'right',
      ),
      'bottom' => array(
        0 => 'bottom',
      ),
      'centroid' => array(
        0 => 'lat',
        1 => 'lon',
      ),
      'geohash' => array(
        0 => 'geohash',
      ),
      'lat' => array(
        0 => 'lat',
      ),
      'left' => array(
        0 => 'left',
      ),
      'lon' => array(
        0 => 'lon',
      ),
      'right' => array(
        0 => 'right',
      ),
      'top' => array(
        0 => 'top',
      ),
    ),
    'locked' => 0,
    'module' => 'geofield',
    'settings' => array(
      'backend' => 'default',
      'srid' => 4326,
    ),
    'translatable' => 0,
    'type' => 'geofield',
  );

  // Exported field_base: 'field_maps'.
  $field_bases['field_maps'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_maps',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 20,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_nzww'.
  $field_bases['field_nzww'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_nzww',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'max' => 284,
      'min' => 0,
      'prefix' => 'p',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'number_integer',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_portage'.
  $field_bases['field_portage'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portage',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_put_in'.
  $field_bases['field_put_in'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_put_in',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_region'.
  $field_bases['field_region'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_region',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Auckland' => 'Auckland',
        'Bay of Plenty' => 'Bay of Plenty',
        'Canterbury' => 'Canterbury',
        'Gisborne' => 'Gisborne',
        'Hawke\'s Bay' => 'Hawke\'s Bay',
        'Manawatu' => 'Manawatu',
        'Marlborough' => 'Marlborough',
        'Northland' => 'Northland',
        'Otago' => 'Otago',
        'Southland' => 'Southland',
        'Taranaki' => 'Taranaki',
        'Tasman' => 'Tasman',
        'Waikato' => 'Waikato',
        'Wanganui' => 'Wanganui',
        'Wellington' => 'Wellington',
        'West Coast' => 'West Coast',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_river_name'.
  $field_bases['field_river_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_river_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 50,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_shuttle'.
  $field_bases['field_shuttle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_shuttle',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_site_id'.
  $field_bases['field_site_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_site_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'max' => 1000000,
      'min' => '',
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'number_integer',
    'type_name' => 'gauge',
  );

  // Exported field_base: 'field_tags'.
  $field_bases['field_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tags',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Helicopter' => 'Helicopter',
        'Moderate' => 'Moderate',
        'Multiday' => 'Multiday',
        'Rain' => 'Rain',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_take_out'.
  $field_bases['field_take_out'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_take_out',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_time'.
  $field_bases['field_time'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_time',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'section',
  );

  // Exported field_base: 'field_upstream_of'.
  $field_bases['field_upstream_of'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_upstream_of',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'article' => 0,
        'forum' => 0,
        'gauge' => 0,
        'media_release' => 0,
        'page' => 0,
        'rivers_event' => 0,
        'rivers_issue' => 0,
        'rivers_story' => 0,
        'rivers_submission' => 0,
        'section' => 'section',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'taxonomyextra'.
  $field_bases['taxonomyextra'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'taxonomyextra',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'vocabulary_5',
          'parent' => 0,
        ),
        1 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_4',
        ),
        2 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_9',
        ),
        3 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_7',
        ),
        4 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_6',
        ),
        5 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_1',
        ),
        6 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_11',
        ),
        7 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_8',
        ),
        8 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_13',
        ),
        9 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_14',
        ),
        10 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_12',
        ),
        11 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_3',
        ),
        12 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_2',
        ),
        13 => array(
          'parent' => 0,
          'vocabulary' => 'vocabulary_10',
        ),
      ),
      'required' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'upload'.
  $field_bases['upload'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'upload',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'default_file' => 0,
      'display_default' => 1,
      'display_field' => 1,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
