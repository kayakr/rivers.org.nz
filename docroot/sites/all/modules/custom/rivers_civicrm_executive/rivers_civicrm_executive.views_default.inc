<?php
/**
 * @file
 * rivers_civicrm_executive.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rivers_civicrm_executive_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rivers_civicrm_executive';
  $view->description = 'List of Executive members from CiviCRM';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'Rivers CiviCRM Executive';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Whitewater NZ Board';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'description' => 'description',
    'display_name' => 'display_name',
    'city' => 'city',
    'text_link' => 'text_link',
    'text_link_1' => 'text_link_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'text_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'text_link_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'As elected at the 2018 AGM.

The Board of the Whitewater NZ are recreational kayakers who contribute their time and energy to the sport they love. They welcome contact with fellow paddlers, so feel free to get in touch.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = 'At AGM 2017 a revised <a href="/constitution">constitution</a> was adopted, changing the governance structure of Whitewater NZ from an Executive Committee to a Board structure.';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: CiviCRM Address: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  /* Field: CiviCRM Relationships: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'civicrm_relationship';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Role';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = 'Email';
  $handler->display->display_options['fields']['email']['location_type'] = '1';
  $handler->display->display_options['fields']['email']['location_op'] = '0';
  $handler->display->display_options['fields']['email']['is_primary'] = 1;
  /* Field: CiviCRM Address: City / Suburb */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['location_type'] = '0';
  $handler->display->display_options['fields']['city']['location_op'] = '0';
  $handler->display->display_options['fields']['city']['is_primary'] = 0;
  /* Field: CiviCRM Contacts: Text Link */
  $handler->display->display_options['fields']['text_link']['id'] = 'text_link';
  $handler->display->display_options['fields']['text_link']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['text_link']['field'] = 'text_link';
  $handler->display->display_options['fields']['text_link']['label'] = 'Ops';
  $handler->display->display_options['fields']['text_link']['link_to_civicrm_contact'] = 'edit';
  $handler->display->display_options['fields']['text_link']['link_text'] = 'Edit';
  /* Field: CiviCRM Contacts: Text Link */
  $handler->display->display_options['fields']['text_link_1']['id'] = 'text_link_1';
  $handler->display->display_options['fields']['text_link_1']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['text_link_1']['field'] = 'text_link';
  $handler->display->display_options['fields']['text_link_1']['link_text'] = 'View';
  /* Sort criterion: CiviCRM Note: Note */
  $handler->display->display_options['sorts']['note']['id'] = 'note';
  $handler->display->display_options['sorts']['note']['table'] = 'civicrm_note';
  $handler->display->display_options['sorts']['note']['field'] = 'note';
  /* Filter criterion: CiviCRM Relationships: Is Relationship Active */
  $handler->display->display_options['filters']['is_active']['id'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['table'] = 'civicrm_relationship';
  $handler->display->display_options['filters']['is_active']['field'] = 'is_active';
  $handler->display->display_options['filters']['is_active']['value'] = '1';
  /* Filter criterion: CiviCRM Relationships: Relationship Type A-to-B */
  $handler->display->display_options['filters']['relationship_type']['id'] = 'relationship_type';
  $handler->display->display_options['filters']['relationship_type']['table'] = 'civicrm_relationship';
  $handler->display->display_options['filters']['relationship_type']['field'] = 'relationship_type';
  $handler->display->display_options['filters']['relationship_type']['value'] = array(
    10 => '10',
  );
  /* Filter criterion: CiviCRM Relationships: End Date */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'civicrm_relationship';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['operator'] = '>=';
  $handler->display->display_options['filters']['end_date']['value']['value'] = 'now';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  /* Filter criterion: CiviCRM Email: Is Primary Email */
  $handler->display->display_options['filters']['is_primary']['id'] = 'is_primary';
  $handler->display->display_options['filters']['is_primary']['table'] = 'civicrm_email';
  $handler->display->display_options['filters']['is_primary']['field'] = 'is_primary';
  $handler->display->display_options['filters']['is_primary']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'about/board';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Whitewater NZ Executive';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['rivers_civicrm_executive'] = $view;

  return $export;
}
