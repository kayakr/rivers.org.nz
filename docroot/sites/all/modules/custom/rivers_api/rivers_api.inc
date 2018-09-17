<?php
/**
 * @file
 * Implement service resource callbacks.
 */

function rivers_api_licence() {
  return 'https://creativecommons.org/licenses/by-sa/3.0/nz/';
}

function rivers_api_attribution() {
  return t('<a href="https://rivers.org.nz/nz">Whitewater NZ River Guide</a> licensed per <a href="https://creativecommons.org/licenses/by-sa/3.0/nz/">Creative Commons CC-BY-SA</a>.');
}

/**
 * Callback for retrieving a Section resource.
 *
 * @todo: what if node is unpublished?
 *
 * @param int $nid section_id
 * @return array $request
 */
function _rivers_api_section_retrieve($nid, $parameters) {

  $node = node_load($nid);

  // Check node is a Section.
  // Also catches no node exists for $nid.
  if ($node->type != 'section') {
    return services_error(t('No such section with id: @id.', array('@id' => $nid)), 404);
  }

  // Maps internal node attributes to attributes to be exposed via API.
  $output = _rivers_api_map_node_to_section($node, $parameters);
  $output['licence'] = rivers_api_licence();
  $output['licence_attribution'] = rivers_api_attribution();

  return $output;
}

/**
 * Return Sections according to filter parameters.
 */
function _rivers_api_section_index($page, $page_size = 20, $parameters) {
  // for now, if we get parameter 'args', it implies a further path has been specified, e.g. canterbury/ashley
  if (isset($_GET['args'])) {
    return services_error(t('Path filters @args not accepted on section index.', array('@args' => $_GET['args'])), 406);
  }

  // @todo: can't rely on parameters being validated against definition!
  // page should be int, but 'b' is allowed through to here.
  if (!is_numeric($page)) {
    $page = 0;
  }
  else {
    $page = (int)$page;
  }

  // Defaults defined in rivers_api_services_resources() apply here.
  // e.g. page_size = 10;
  $nodes = array();
  $output = array();

  // Get total number of sections via count.
  $query_total = new EntityFieldQuery();
  $query_total->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'section')
    ->propertyCondition('status', 1);
  $total = $query_total->count()->execute();

  // Get the sections for the current page.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'section')
    ->propertyCondition('status', 1)
    ->range((int)$page * $page_size, (int)$page_size);
  // @todo: what are sort default, options?
  //->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  if (count($nodes)) {
    foreach ($nodes as $nid => $node) {
      watchdog('rivers_api', 'Loading nid=@nid', array('@nid' => $nid));
      $output['sections'][] = _rivers_api_map_node_to_section($node, $parameters);
    }
  }

  // Meta information.
  $output['count'] = count($nodes);
  $output['page'] = $page;
  $output['page_size'] = (int)$page_size;
  $output['total'] = (int)$total;

  // HAL+JSON
  // @todo: only output next link if more nodes exists. Need to do full count...
  if ($page > 0) {
    $output['_links'] = array(
      'self' => array(
        'href' => url('nz', array('query' => array('page' => $page))),
        'url' => url('nz', array('absolute' => TRUE)),
      ),
      'prev' => array(
         'href' => url('nz', array('query' => array('page' => $page - 1))),
      )
    );
  }
  else {
    $output['_links'] = array(
      'self' => array(
        'href' => url('nz'),
        'url' => url('nz', array('absolute' => TRUE)),
      ),
    );
  }

  // @todo: api docs
  $output['licence'] = rivers_api_licence();
  $output['licence_attribution'] = rivers_api_attribution();

  return $output;
}

/**
 * We don't want to expose all attributes to the world.
 */
function _rivers_api_map_node_to_section($node, $parameters) {
  $endpoint_path = '/' . _rivers_api_endpoint_path();

  // Wrap place in Entity wrapper to ease access to fields.
  $object = entity_metadata_wrapper('node', $node);

  $section = array();
  $section['@id'] = url('node/' . $node->nid, array('absolute' => TRUE));
  $section['id'] = $node->nid;
  $section['vid'] = $node->vid; // version.

  $section['region'] = $object->field_region->value();
  $section['river_name'] = $object->field_river_name->value(array('sanitize' => TRUE));
  //$section['name'] = $node->title;
  $section['name'] = $object->title->value(array('sanitize' => TRUE));

  $section['name_alternate'] = $object->field_alternate_name->value(array('sanitize' => TRUE));

  // https://www.computerminds.co.uk/articles/rendering-drupal-7-fields-right-way
  $field_class = field_get_items('node', $node, 'field_class');

  $class_value = field_view_value('node', $node, 'field_class', $field_class[0]);
  $section['class'] = drupal_render($class_value);
  $section['portage'] = $object->field_portage->value();
  $section['class_numeric'] = $object->field_class->value();

  $section['character'] = $object->field_character->value(array('sanitize' => TRUE));

  if (isset($node->body[LANGUAGE_NONE][0])) {
    $section['description'] = $object->body->value->value(array('sanitize' => TRUE));
  }

  $section['credits'] = $object->field_credits->value(array('sanitize' => TRUE));
  $section['gradient'] = $object->field_gradient->value(array('sanitize' => TRUE));
  $section['gradient_unit'] = 'm/km';
  $section['length'] = $object->field_length->value(array('sanitize' => TRUE));
  $section['length_unit'] = 'km';

  // field_gauge
  // field_gauge_niwa

  $section['hot_tip'] = $object->field_hot_tip->value(array('sanitize' => TRUE));
  $section['level'] = $object->field_level->value(array('sanitize' => TRUE));
  $section['maps'] = $object->field_maps->value(array('sanitize' => TRUE));
  $section['level'] = $object->field_level->value(array('sanitize' => TRUE));
  // NZ Whitewater 4th Edition 2006.
  $section['nzww_2006'] = $object->field_nzww->value(array('sanitize' => TRUE));
  // field_portage (above)
  // field_river_name (above)
  // field_region (above)
  $section['shuttle'] = $object->field_shuttle->value(array('sanitize' => TRUE));
  $section['time'] = $object->field_time->value(array('sanitize' => TRUE));
  // field_tags
  $section['tags'] = $object->field_tags->value();
  $section['put_in'] = $object->field_put_in->value(array('sanitize' => TRUE));
  $section['take_out'] = $object->field_take_out->value(array('sanitize' => TRUE));
  // field_upstream_of (below, in _links).
  // field_poi

  //$wrapper = _wrapper_debug($object);

  if ($object->field_history->value()) {
    $section['history'] = $object->field_history->value->value(array('sanitize' => TRUE));
  }

  // Properties.
  $section['created'] = date('c', $object->created->value());
  $section['changed'] = date('c', $object->changed->value());

  // HAL+JSON.
  $section['_links'] = array(
    'self' => array(
      'href' => url('node/' . $node->nid),
      'url' => url('node/' . $node->nid, array('absolute' => TRUE)),
    ),
  );

  if ($object->field_upstream_of->value()) {
    $section['_links']['upstream_of'] = _rivers_api_map_node_to_section($object->field_upstream_of->value());
  }

  return $section;
}

function _wrapper_debug($w) {
  $values = array();
  foreach ($w->getPropertyInfo() as $key => $val) {
    $values[$key] = $w->$key->value();
  }
  return $values;
}
