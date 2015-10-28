<?php
/**
 * @file
 * rivers_guide.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function rivers_guide_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_section-comment_body'.
  $fields['comment-comment_node_section-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_section',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Comment',
      'required' => TRUE,
      'settings' => array(
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 5,
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-gauge-body'.
  $fields['node-gauge-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'gauge',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'trim_length' => 600,
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => -4,
      ),
    ),
  );

  // Exported field: 'node-gauge-field_site_id'.
  $fields['node-gauge-field_site_id'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_site_id',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '1000000',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'gauge',
    ),
    'field_instance' => array(
      'bundle' => 'gauge',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_site_id',
      'label' => 'Site Id',
      'required' => FALSE,
      'settings' => array(
        'max' => '1000000',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => '0',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '0',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-section-body'.
  $fields['node-section-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'trim_length' => 600,
          ),
          'trim_length' => 600,
          'type' => 'text_summary_or_trimmed',
          'weight' => 11,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 0,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-section-field_alternate_name'.
  $fields['node-section-field_alternate_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_alternate_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '200',
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'An alternate name for the Section (e.g. for Lower Taipo, an alternate name is Taipo Gorge).',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_alternate_name',
      'label' => 'Alternate Name',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_character'.
  $fields['node-section-field_character'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_character',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Summarise the nature of the section.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_character',
      'label' => 'Character',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '8',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_class'.
  $fields['node-section-field_class'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_class',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '0',
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
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Use river scale I to IV for typical flows. A range of difficulty is indicated with a hyphen. Use brackets for out-of-character rapids, e.g. III (IV).',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '-10',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-10',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_class',
      'label' => 'Class',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-10',
      'widget' => array(
        'active' => '0',
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '-10',
      ),
      'widget_type' => 'optionwidgets_select',
    ),
  );

  // Exported field: 'node-section-field_credits'.
  $fields['node-section-field_credits'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_credits',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'A comma-separated list of people who made significant contributions to this material.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '7',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_credits',
      'label' => 'Credits',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '7',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '10',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_downstream_of'.
  $fields['node-section-field_downstream_of'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_downstream_of',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'node_reference',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(),
      ),
      'deleted' => '0',
      'description' => 'If this Section ends above another Section, specify the downstream Section here.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '3',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_downstream_of',
      'label' => 'Upstream of',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => '0',
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => '8',
      ),
      'widget_type' => 'nodereference_autocomplete',
    ),
  );

  // Exported field: 'node-section-field_gauge'.
  $fields['node-section-field_gauge'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_gauge',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'URL of flow info, flow phone number, NIWA gauge id',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-7',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_gauge',
      'label' => 'Gauge',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '-6',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-7',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_gauge_niwa'.
  $fields['node-section-field_gauge_niwa'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_gauge_niwa',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'node_reference',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'nid' => '0',
          'error_field' => 'field_gauge_niwa][nids',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '4',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_gauge_niwa',
      'label' => 'Gauge (NIWA)',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => '0',
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '11',
      ),
      'widget_type' => 'nodereference_select',
    ),
  );

  // Exported field: 'node-section-field_gradient'.
  $fields['node-section-field_gradient'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_gradient',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'decimal_separator' => '.',
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'm/km',
      ),
      'translatable' => '0',
      'type' => 'number_float',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Average gradient in metres per kilometre.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-5',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-2',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_gradient',
      'label' => 'Gradient',
      'required' => FALSE,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'm/km',
        'user_register_form' => FALSE,
      ),
      'weight' => '-2',
      'widget' => array(
        'active' => '0',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '-5',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-section-field_history'.
  $fields['node-section-field_history'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_history',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '',
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text_long',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '9',
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_history',
      'label' => 'History',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '8',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '7',
      ),
      'widget_type' => 'text_textarea',
    ),
  );

  // Exported field: 'node-section-field_hot_tip'.
  $fields['node-section-field_hot_tip'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_hot_tip',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_hot_tip',
      'label' => 'Hot tip',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '10',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_length'.
  $fields['node-section-field_length'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_length',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'decimal_separator' => '.',
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'km',
      ),
      'translatable' => '0',
      'type' => 'number_float',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'In kilometres.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-6',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-4',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_decimal',
          'weight' => '-4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_length',
      'label' => 'Length',
      'required' => FALSE,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => 'km',
        'user_register_form' => FALSE,
      ),
      'weight' => '-4',
      'widget' => array(
        'active' => '0',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '-6',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-section-field_level'.
  $fields['node-section-field_level'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_level',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '1',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-8',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-8',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-8',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_level',
      'label' => 'Level',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'weight' => '-8',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-8',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_maps'.
  $fields['node-section-field_maps'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_maps',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '20',
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'e.g. NZ Topo T19',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_maps',
      'label' => 'Maps',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '6',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '0',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_nzww'.
  $fields['node-section-field_nzww'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_nzww',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_php' => '',
        'max' => '284',
        'min' => '0',
        'prefix' => 'p',
        'suffix' => '',
      ),
      'translatable' => '0',
      'type' => 'number_integer',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Is this Section in NZ Whitewater 4th Edition, 2006? If so, enter the page number.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '6',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 0,
            'thousand_separator' => '',
          ),
          'type' => 'number_integer',
          'weight' => '6',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_nzww',
      'label' => 'NZ Whitewater 4th Edition 2006',
      'required' => FALSE,
      'settings' => array(
        'max' => '284',
        'min' => '0',
        'prefix' => 'p',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'weight' => '6',
      'widget' => array(
        'active' => '0',
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '9',
      ),
      'widget_type' => 'number',
    ),
  );

  // Exported field: 'node-section-field_portage'.
  $fields['node-section-field_portage'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_portage',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'No',
          1 => 'Yes',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => 'Yes',
        ),
      ),
      'deleted' => '0',
      'description' => 'Is there a mandatory portage under normal conditions? ',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '-9',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-10',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-10',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_portage',
      'label' => 'Portage?',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-10',
      'widget' => array(
        'active' => '0',
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => '-9',
      ),
      'widget_type' => 'optionwidgets_onoff',
    ),
  );

  // Exported field: 'node-section-field_put_in'.
  $fields['node-section-field_put_in'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_put_in',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Brief description, e.g. Poutu intake.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-3',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_put_in',
      'label' => 'Put in',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '2',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-3',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_region'.
  $fields['node-section-field_region'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_region',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => NULL,
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_region',
      'label' => 'Region',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'node-section-field_river_name'.
  $fields['node-section-field_river_name'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_river_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => '50',
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-3',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-3',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_river_name',
      'label' => 'River Name',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '-3',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '1',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_shuttle'.
  $fields['node-section-field_shuttle'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_shuttle',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'Length in km (add km), or reference helicopter operators.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-1',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '5',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_shuttle',
      'label' => 'Shuttle',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '5',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-1',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_tags'.
  $fields['node-section-field_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_tags',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => NULL,
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_tags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-section-field_take_out'.
  $fields['node-section-field_take_out'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_take_out',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-2',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '4',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_take_out',
      'label' => 'Take out',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '4',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-2',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-field_time'.
  $fields['node-section-field_time'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_time',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'allowed_values' => '',
        'allowed_values_php' => '',
        'max_length' => 255,
        'text_processing' => '0',
      ),
      'translatable' => '0',
      'type' => 'text',
      'type_name' => 'section',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'deleted' => '0',
      'description' => 'e.g. 2-4 hours, 1-2 days.',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '-4',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_time',
      'label' => 'Time',
      'required' => FALSE,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'weight' => '0',
      'widget' => array(
        'active' => '0',
        'module' => 'text',
        'settings' => array(
          'rows' => '1',
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => '-4',
      ),
      'widget_type' => 'text_textfield',
    ),
  );

  // Exported field: 'node-section-taxonomyextra'.
  $fields['node-section-taxonomyextra'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'taxonomyextra',
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Debris left over after upgrade from Drupal 6',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '10',
        ),
        'teaser' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 10,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'taxonomyextra',
      'label' => 'Taxonomy upgrade extras',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '12',
      ),
    ),
  );

  // Exported field: 'node-section-upload'.
  $fields['node-section-upload'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'upload',
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'file',
      'settings' => array(
        'default_file' => 0,
        'display_default' => '1',
        'display_field' => 1,
        'uri_scheme' => 'private',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'section',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => '11',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_table',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => NULL,
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'upload',
      'label' => 'File attachments',
      'required' => 0,
      'settings' => array(
        'description_field' => 1,
        'file_directory' => '',
        'file_extensions' => 'jpg jpeg gif png txt html doc xls pdf ppt pps odt ods odp kml kmz eps ai fh9 wmf rtf tif tiff fh10 fh11 hqx',
        'max_filesize' => '5 MB',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'file',
        'settings' => array(
          'progress_indicator' => 'throbber',
        ),
        'type' => 'file_generic',
        'weight' => '13',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A comma-separated list of people who made significant contributions to this material.');
  t('Alternate Name');
  t('An alternate name for the Section (e.g. for Lower Taipo, an alternate name is Taipo Gorge).');
  t('Average gradient in metres per kilometre.');
  t('Body');
  t('Brief description, e.g. Poutu intake.');
  t('Character');
  t('Class');
  t('Comment');
  t('Credits');
  t('Debris left over after upgrade from Drupal 6');
  t('File attachments');
  t('Gauge');
  t('Gauge (NIWA)');
  t('Gradient');
  t('History');
  t('Hot tip');
  t('If this Section ends above another Section, specify the downstream Section here.');
  t('In kilometres.');
  t('Is there a mandatory portage under normal conditions? ');
  t('Is this Section in NZ Whitewater 4th Edition, 2006? If so, enter the page number.');
  t('Length');
  t('Length in km (add km), or reference helicopter operators.');
  t('Level');
  t('Maps');
  t('NZ Whitewater 4th Edition 2006');
  t('Portage?');
  t('Put in');
  t('Region');
  t('River Name');
  t('Shuttle');
  t('Site Id');
  t('Summarise the nature of the section.');
  t('Tags');
  t('Take out');
  t('Taxonomy upgrade extras');
  t('Time');
  t('URL of flow info, flow phone number, NIWA gauge id');
  t('Upstream of');
  t('Use river scale I to IV for typical flows. A range of difficulty is indicated with a hyphen. Use brackets for out-of-character rapids, e.g. III (IV).');
  t('e.g. 2-4 hours, 1-2 days.');
  t('e.g. NZ Topo T19');

  return $fields;
}
