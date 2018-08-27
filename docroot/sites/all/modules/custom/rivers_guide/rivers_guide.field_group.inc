<?php
/**
 * @file
 * rivers_guide.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rivers_guide_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|section|default';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '0',
    'children' => array(
      0 => 'field_character',
      1 => 'field_class',
      2 => 'field_gauge',
      3 => 'field_gradient',
      4 => 'field_hot_tip',
      5 => 'field_length',
      6 => 'field_level',
      7 => 'field_maps',
      8 => 'field_portage',
      9 => 'field_put_in',
      10 => 'field_shuttle',
      11 => 'field_take_out',
      12 => 'field_time',
      13 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'info',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_info|node|section|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|section|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_character',
      1 => 'field_class',
      2 => 'field_gauge',
      3 => 'field_gradient',
      4 => 'field_hot_tip',
      5 => 'field_length',
      6 => 'field_level',
      7 => 'field_maps',
      8 => 'field_portage',
      9 => 'field_put_in',
      10 => 'field_shuttle',
      11 => 'field_take_out',
      12 => 'field_time',
      13 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_info|node|section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|section|teaser';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '-2',
    'children' => array(
      0 => 'field_character',
      1 => 'field_class',
      2 => 'field_gauge',
      3 => 'field_gradient',
      4 => 'field_hot_tip',
      5 => 'field_length',
      6 => 'field_level',
      7 => 'field_maps',
      8 => 'field_portage',
      9 => 'field_put_in',
      10 => 'field_shuttle',
      11 => 'field_take_out',
      12 => 'field_time',
    ),
    'format_type' => 'no_style',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $field_groups['group_info|node|section|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Info');

  return $field_groups;
}
