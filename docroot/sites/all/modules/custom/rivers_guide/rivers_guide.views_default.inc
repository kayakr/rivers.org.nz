<?php
/**
 * @file
 * rivers_guide.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rivers_guide_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rivers_sections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'rivers_sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'River Guide';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_region' => 'field_region',
    'field_river_name' => 'field_river_name',
    'title' => 'title',
    'field_class' => 'field_class',
    'field_portage' => 'field_class',
  );
  $handler->display->display_options['style_options']['default'] = 'field_river_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_region' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_river_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_portage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No sections match path.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
  /* Field: Content: River Name */
  $handler->display->display_options['fields']['field_river_name']['id'] = 'field_river_name';
  $handler->display->display_options['fields']['field_river_name']['table'] = 'field_data_field_river_name';
  $handler->display->display_options['fields']['field_river_name']['field'] = 'field_river_name';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  /* Field: Content: Portage? */
  $handler->display->display_options['fields']['field_portage']['id'] = 'field_portage';
  $handler->display->display_options['fields']['field_portage']['table'] = 'field_data_field_portage';
  $handler->display->display_options['fields']['field_portage']['field'] = 'field_portage';
  $handler->display->display_options['fields']['field_portage']['alter']['text'] = ' (P)';
  $handler->display->display_options['fields']['field_portage']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_portage']['type'] = 'rivers_guide_portage_formatter';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  /* Sort criterion: Content: Region (field_region) */
  $handler->display->display_options['sorts']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['sorts']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['sorts']['field_region_value']['field'] = 'field_region_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'section' => 'section',
  );
  /* Filter criterion: Content: Region (field_region) */
  $handler->display->display_options['filters']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['filters']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_region_value']['expose']['operator_id'] = 'field_region_value_op';
  $handler->display->display_options['filters']['field_region_value']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_region_value']['expose']['operator'] = 'field_region_value_op';
  $handler->display->display_options['filters']['field_region_value']['expose']['identifier'] = 'region';
  $handler->display->display_options['filters']['field_region_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: River Name (field_river_name) */
  $handler->display->display_options['filters']['field_river_name_value']['id'] = 'field_river_name_value';
  $handler->display->display_options['filters']['field_river_name_value']['table'] = 'field_data_field_river_name';
  $handler->display->display_options['filters']['field_river_name_value']['field'] = 'field_river_name_value';
  $handler->display->display_options['filters']['field_river_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_river_name_value']['expose']['operator_id'] = 'field_river_name_value_op';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['label'] = 'River Name';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['operator'] = 'field_river_name_value_op';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['identifier'] = 'river';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Class (field_class) */
  $handler->display->display_options['filters']['field_class_value']['id'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['table'] = 'field_data_field_class';
  $handler->display->display_options['filters']['field_class_value']['field'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['filters']['field_class_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['expose']['operator_id'] = 'class_op';
  $handler->display->display_options['filters']['field_class_value']['expose']['label'] = 'Class';
  $handler->display->display_options['filters']['field_class_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['expose']['operator'] = 'field_class_value_op';
  $handler->display->display_options['filters']['field_class_value']['expose']['identifier'] = 'class';
  $handler->display->display_options['filters']['field_class_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_class_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['group_info']['label'] = 'Class (field_class)';
  $handler->display->display_options['filters']['field_class_value']['group_info']['identifier'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_class_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_value']['id'] = 'field_tags_value';
  $handler->display->display_options['filters']['field_tags_value']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_value']['field'] = 'field_tags_value';
  $handler->display->display_options['filters']['field_tags_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_value']['expose']['operator_id'] = 'field_tags_value_op';
  $handler->display->display_options['filters']['field_tags_value']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_value']['expose']['operator'] = 'field_tags_value_op';
  $handler->display->display_options['filters']['field_tags_value']['expose']['identifier'] = 'tag';
  $handler->display->display_options['filters']['field_tags_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nz';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_region']['id'] = 'field_region';
  $handler->display->display_options['fields']['field_region']['table'] = 'field_data_field_region';
  $handler->display->display_options['fields']['field_region']['field'] = 'field_region';
  /* Field: Content: River Name */
  $handler->display->display_options['fields']['field_river_name']['id'] = 'field_river_name';
  $handler->display->display_options['fields']['field_river_name']['table'] = 'field_data_field_river_name';
  $handler->display->display_options['fields']['field_river_name']['field'] = 'field_river_name';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_class']['id'] = 'field_class';
  $handler->display->display_options['fields']['field_class']['table'] = 'field_data_field_class';
  $handler->display->display_options['fields']['field_class']['field'] = 'field_class';
  /* Field: Content: Portage? */
  $handler->display->display_options['fields']['field_portage']['id'] = 'field_portage';
  $handler->display->display_options['fields']['field_portage']['table'] = 'field_data_field_portage';
  $handler->display->display_options['fields']['field_portage']['field'] = 'field_portage';
  $handler->display->display_options['fields']['field_portage']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_portage']['alter']['text'] = ' (P)';
  $handler->display->display_options['fields']['field_portage']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_portage']['type'] = 'list_key';
  /* Field: Content: Length */
  $handler->display->display_options['fields']['field_length']['id'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['table'] = 'field_data_field_length';
  $handler->display->display_options['fields']['field_length']['field'] = 'field_length';
  $handler->display->display_options['fields']['field_length']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Gradient */
  $handler->display->display_options['fields']['field_gradient']['id'] = 'field_gradient';
  $handler->display->display_options['fields']['field_gradient']['table'] = 'field_data_field_gradient';
  $handler->display->display_options['fields']['field_gradient']['field'] = 'field_gradient';
  $handler->display->display_options['fields']['field_gradient']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  /* Field: Content: Put in */
  $handler->display->display_options['fields']['field_put_in']['id'] = 'field_put_in';
  $handler->display->display_options['fields']['field_put_in']['table'] = 'field_data_field_put_in';
  $handler->display->display_options['fields']['field_put_in']['field'] = 'field_put_in';
  /* Field: Content: Take out */
  $handler->display->display_options['fields']['field_take_out']['id'] = 'field_take_out';
  $handler->display->display_options['fields']['field_take_out']['table'] = 'field_data_field_take_out';
  $handler->display->display_options['fields']['field_take_out']['field'] = 'field_take_out';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'section' => 'section',
  );
  /* Filter criterion: Content: Region (field_region) */
  $handler->display->display_options['filters']['field_region_value']['id'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['table'] = 'field_data_field_region';
  $handler->display->display_options['filters']['field_region_value']['field'] = 'field_region_value';
  $handler->display->display_options['filters']['field_region_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_region_value']['expose']['operator_id'] = 'field_region_value_op';
  $handler->display->display_options['filters']['field_region_value']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_region_value']['expose']['operator'] = 'field_region_value_op';
  $handler->display->display_options['filters']['field_region_value']['expose']['identifier'] = 'region';
  $handler->display->display_options['filters']['field_region_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: River Name (field_river_name) */
  $handler->display->display_options['filters']['field_river_name_value']['id'] = 'field_river_name_value';
  $handler->display->display_options['filters']['field_river_name_value']['table'] = 'field_data_field_river_name';
  $handler->display->display_options['filters']['field_river_name_value']['field'] = 'field_river_name_value';
  $handler->display->display_options['filters']['field_river_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_river_name_value']['expose']['operator_id'] = 'field_river_name_value_op';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['label'] = 'River Name';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['operator'] = 'field_river_name_value_op';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['identifier'] = 'river';
  $handler->display->display_options['filters']['field_river_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Class (field_class) */
  $handler->display->display_options['filters']['field_class_value']['id'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['table'] = 'field_data_field_class';
  $handler->display->display_options['filters']['field_class_value']['field'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['filters']['field_class_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['expose']['operator_id'] = 'class_op';
  $handler->display->display_options['filters']['field_class_value']['expose']['label'] = 'Class';
  $handler->display->display_options['filters']['field_class_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['expose']['operator'] = 'field_class_value_op';
  $handler->display->display_options['filters']['field_class_value']['expose']['identifier'] = 'class';
  $handler->display->display_options['filters']['field_class_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_class_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_class_value']['group_info']['label'] = 'Class (field_class)';
  $handler->display->display_options['filters']['field_class_value']['group_info']['identifier'] = 'field_class_value';
  $handler->display->display_options['filters']['field_class_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_class_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_value']['id'] = 'field_tags_value';
  $handler->display->display_options['filters']['field_tags_value']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_value']['field'] = 'field_tags_value';
  $handler->display->display_options['filters']['field_tags_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_value']['expose']['operator_id'] = 'field_tags_value_op';
  $handler->display->display_options['filters']['field_tags_value']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_value']['expose']['operator'] = 'field_tags_value_op';
  $handler->display->display_options['filters']['field_tags_value']['expose']['identifier'] = 'tag';
  $handler->display->display_options['filters']['field_tags_value']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    1 => 0,
    10 => 0,
    6 => 0,
    12 => 0,
    5 => 0,
    9 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    7 => 0,
  );
  $handler->display->display_options['path'] = 'nz-csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['rivers_sections'] = $view;

  return $export;
}
