<?php
/**
 * @file
 * rivers_civicrm_clubs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rivers_civicrm_clubs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rivers_membership_clubs';
  $view->description = 'List of clubs';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'Rivers Membership Clubs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New Zealand Canoe & Kayak Clubs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'display_name' => 'display_name',
    'street_address' => 'street_address',
    'city' => 'city',
    'email' => 'email',
    'url' => 'url',
  );
  $handler->display->display_options['row_options']['separator'] = ',';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'If your favourite club is not listed here, or if you would like to change the contact details for your club, please contact <a href="mailto:membership@rivers.org.nz">Whitewater NZ Membership Officer</a>.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['label'] = '';
  $handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Address: Full Street Address */
  $handler->display->display_options['fields']['street_address']['id'] = 'street_address';
  $handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['street_address']['field'] = 'street_address';
  $handler->display->display_options['fields']['street_address']['label'] = '';
  $handler->display->display_options['fields']['street_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['street_address']['location_type'] = '3';
  $handler->display->display_options['fields']['street_address']['location_op'] = '0';
  $handler->display->display_options['fields']['street_address']['is_primary'] = 0;
  /* Field: CiviCRM Address: City / Suburb */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['city']['location_type'] = '0';
  $handler->display->display_options['fields']['city']['location_op'] = '0';
  $handler->display->display_options['fields']['city']['is_primary'] = 0;
  /* Field: CiviCRM Email: Email Address */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  $handler->display->display_options['fields']['email']['label'] = '';
  $handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['email']['location_type'] = '3';
  $handler->display->display_options['fields']['email']['location_op'] = '1';
  $handler->display->display_options['fields']['email']['is_primary'] = 0;
  /* Field: CiviCRM Website: Website URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'civicrm_website';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['location_type'] = '0';
  $handler->display->display_options['fields']['url']['location_op'] = '0';
  $handler->display->display_options['fields']['url']['is_primary'] = 0;
  $handler->display->display_options['fields']['url']['website_type'] = '0';
  /* Field: CiviCRM Address: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_address';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  /* Sort criterion: CiviCRM Contacts: Display Name */
  $handler->display->display_options['sorts']['display_name']['id'] = 'display_name';
  $handler->display->display_options['sorts']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['sorts']['display_name']['field'] = 'display_name';
  /* Filter criterion: CiviCRM Member: Membership Type */
  $handler->display->display_options['filters']['membership_type']['id'] = 'membership_type';
  $handler->display->display_options['filters']['membership_type']['table'] = 'civicrm_membership';
  $handler->display->display_options['filters']['membership_type']['field'] = 'membership_type';
  $handler->display->display_options['filters']['membership_type']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: CiviCRM Contacts: Contact Type */
  $handler->display->display_options['filters']['contact_type']['id'] = 'contact_type';
  $handler->display->display_options['filters']['contact_type']['table'] = 'civicrm_contact';
  $handler->display->display_options['filters']['contact_type']['field'] = 'contact_type';
  $handler->display->display_options['filters']['contact_type']['value'] = array(
    'Organization' => 'Organization',
  );
  /* Filter criterion: CiviCRM Address: Contact ID */
  $handler->display->display_options['filters']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['table'] = 'civicrm_address';
  $handler->display->display_options['filters']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id']['operator'] = 'not empty';
  /* Filter criterion: CiviCRM Address: Contact ID */
  $handler->display->display_options['filters']['contact_id_1']['id'] = 'contact_id_1';
  $handler->display->display_options['filters']['contact_id_1']['table'] = 'civicrm_address';
  $handler->display->display_options['filters']['contact_id_1']['field'] = 'contact_id';
  $handler->display->display_options['filters']['contact_id_1']['operator'] = '!=';
  $handler->display->display_options['filters']['contact_id_1']['value'] = '9387';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'membership/clubs';
  $export['rivers_membership_clubs'] = $view;

  return $export;
}
