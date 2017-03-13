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
  $handler->display->display_options['title'] = 'Rivers CiviCRM Executive';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Address: City / Suburb */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['location_type'] = '0';
  $handler->display->display_options['fields']['city']['location_op'] = '0';
  $handler->display->display_options['fields']['city']['is_primary'] = 0;
  /* Field: CiviCRM Relationships: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'civicrm_relationship';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Role';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'rivers-civicrm-executive';
  $export['rivers_civicrm_executive'] = $view;

  return $export;
}
