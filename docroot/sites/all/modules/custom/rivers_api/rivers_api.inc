<?php
/**
 * @file
 * Implement service resource callbacks.
 */

/**
 * Callback for retrieving a Section resource.
 *
 * @todo: what id node is unpublished?
 *
 * @param int $nid section_id
 * @return array $request
 */
function _rivers_api_section_retrieve($nid, $parameters) {

  $node = node_load($nid);

  // Check loaded node is a Section.
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
function _rivers_api_section_index($page, $parameters) {
  // @todo: can't rely on parameters being validated against definition!
  // page should be int, but 'b' is allowed through to here.
  if (!is_numeric($page)) {
    $page = 0;
  }

  $nodes = array();
  $page_size = 10;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'section')
    ->propertyCondition('status', 1)
    ->range((int)$page * $page_size, $page_size);
  // @todo: what are sort default, options?
  //->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();

  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
  }

  if (count($nodes)) {
    foreach ($nodes as $nid => $node) {
      $nodes[$nid] = _rivers_api_map_node_to_section($node, $parameters);
    }
  }

  // Meta information.
  $nodes['page'] = (int)$page;
  $nodes['page_size'] = $page_size;
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

  $section['class'] = drupal_render(field_view_value('node', $node, 'field_class', $field_class[0]));

  $section['class_numeric'] = $object->field_class->value();

  $section['character'] = $object->field_character->value();

  //$place['type'] = $object->field_type->value(); // field_view_field('node', $node, 'field_place_type');
  //$place['height'] = $object->field_height->value();
  //$place['description'] = $object->field_description->value->value(); //->value; // Safe value.

  // JSON HAL.
  $section['_links'] = array(
    'self' => array(
      'href' => $endpoint_path . '/section/' . $node->nid,
      'url' => url('node/' . $node->nid, array('absolute' => TRUE)),
    ),
  );

  return $section;
}


