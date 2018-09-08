<?php
/**
 * @file
 * Implement service resource callbacks.
 */

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
  $output['licence'] = t('http://creativecommons.org/licenses/by-sa/3.0/nz/');

  return $output;
}

/**
 * Return Sections according to filter parameters.
 */
function _rivers_api_section_index($page, $page_size, $parameters) {
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
      $nodes[$nid] = _rivers_api_map_node_to_section($node, $parameters);
    }
  }

  // Meta information.
  $nodes['count'] = count($nodes);
  $nodes['page'] = $page;
  $nodes['page_size'] = $page_size;

  // HAL+JSON
  // @todo: only output next link if more nodes exists. Need to do full count...
  if ($page > 0) {
    $nodes['_links'] = array(
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
    $nodes['_links'] = array(
      'self' => array(
        'href' => url('nz'),
        'url' => url('nz', array('absolute' => TRUE)),
      ),
    );
  }

  // @todo: api docs
  $nodes['licence'] = t('http://creativecommons.org/licenses/by-sa/3.0/nz/');

  return $nodes;
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
  $section['name'] = $node->title;
  $section['name_alternate'] = $object->field_alternate_name->value();

  // https://www.computerminds.co.uk/articles/rendering-drupal-7-fields-right-way
  $field_class = field_get_items('node', $node, 'field_class');

  $class_value = field_view_value('node', $node, 'field_class', $field_class[0]);
  $section['class'] = drupal_render($class_value);

  $section['class_numeric'] = $object->field_class->value();

  $section['character'] = $object->field_character->value();

  if (isset($node->body[LANGUAGE_NONE][0])) {
    $section['description'] = $object->body->value->value();
  }

  $section['credits'] = $object->field_credits->value();
  $section['gradient'] = $object->field_gradient->value();
  $section['gradient_unit'] = 'm/km';
  $section['length'] = $object->field_length->value();
  $section['length_unit'] = 'km';

  //$place['type'] = $object->field_type->value(); // field_view_field('node', $node, 'field_place_type');
  //$place['height'] = $object->field_height->value();
  //$place['description'] = $object->field_description->value->value(); //->value; // Safe value.

  // HAL+JSON.
  $section['_links'] = array(
    'self' => array(
      'href' => url('node/' . $node->nid),
      'url' => url('node/' . $node->nid, array('absolute' => TRUE)),
    ),
  );

  return $section;
}


