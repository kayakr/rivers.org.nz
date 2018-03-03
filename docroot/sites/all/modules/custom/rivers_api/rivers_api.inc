<?php
/**
 * @file
 * Implement service resource callbacks.
 */

/**
 * Callback for listing places.
 * @todo: Apply filter criteria.
 *
 * @param object $data
 * @return object $request
 */
/*function _climbnz_api_places(){

  // toDo:  make these key/value available via administration interface

  $discovery['changeset'] = "2012-11-26 00:18";
  $discovery['contact'] = "Bundesstadt Bonn, Amt 10-11, Berliner Platz 2, 53111 Bonn, fon: +49 228 77369";
  $discovery['key_service'] = "You can request a key here: not yet";
  $discovery['endpoints']['specification'] = "http://wiki.open311.org/GeoReport_v2";
  $discovery['endpoints']['endpoint']['url'] = "http://anliegen.bonn.de/georeport/v2";
  $discovery['endpoints']['endpoint']['changeset'] = "2012-11-26 00:18";
  $discovery['endpoints']['endpoint']['type'] = "production";
  $discovery['endpoints']['endpoint']['formats'] = array('format' => 'text/xml','format' =>'application/json');

  return $discovery;
}*/

/**
 * Callback for retrieving a Place resource.
 *
 * @param int $nid service_request_id
 * @return array $request
 */
function _rivers_api_place_retrieve($nid, $parameters) {
  flog_it(__FUNCTION__ . ': nid=' . $nid);
  // added optional parameters achieving this:
  // http://lists.open311.org/groups/discuss/messages/topic/AaxmrRLUHToO7jCQdjAXy
  $node = node_load($nid);
  //$status = _tax_map_status($node->field_status['und'][0]["tid"]);

  //$output = $node;
  // Maps internal node attributes to attributes to be exposed via API.
  //$output[] = _node_map_request($node, $status, $parameters);
  $output = _rivers_api_map_node_to_section($node, $parameters);
  return $output;
}

/**
 * Return Sections according to filter parameters.
 * @todo: use a view?
 */
function _rivers_api_section_index($page, $parameters) {
  $nodes = array();
  $page_size = 10;
xdebug_break();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'section')
    ->propertyCondition('status', 1)
    ->range(0, $page_size);
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
  xdebug_break();
  return $nodes;
}

/**
 * We don't want to expose all attributes to the world.
 */
function _rivers_api_map_node_to_section($node, $parameters) {
  $endpoint_path = '/' . _rivers_api_endpoint_path();

  // Wrap place in Entity wrapper to ease access to fields.
  $object = entity_metadata_wrapper('node', $node);

  $place = array();
  $place['id'] = $node->nid;
  $place['vid'] = $node->vid; // version.
  $place['name'] = $node->title;
  // https://www.computerminds.co.uk/articles/rendering-drupal-7-fields-right-way
  $field_class = field_get_items('node', $node, 'field_class');
  xdebug_break();
  $place['class'] = drupal_render(field_view_value('node', $node, 'field_class', $field_class[0]));

  $place['class_b'] = $object->field_class->value();


  //$place['type'] = $object->field_type->value(); // field_view_field('node', $node, 'field_place_type');
  //$place['height'] = $object->field_height->value();
  //$place['description'] = $object->field_description->value->value(); //->value; // Safe value.

  // JSON HAL.
  $place['_links'] = array(
    'self' => array(
      'href' => $endpoint_path . '/place/' . $node->nid,
      'url' => url('node/' . $node->nid, array('absolute' => TRUE)),
    ), // , array('absolute' => TRUE)
  );
/*
  // A Place will have a parent (except top place: NZ).
  $parent = nodehierarchy_get_node_parent($node->nid);
  if (!empty($parent)) {
    //$place['_links']['parent']['href'] = $endpoint_path . '/place/' . $parent->nid;
    //$place['_links']['parent']['url'] = url('node/' . $parent->nid);
    $place['_links']['parent'] = _climbnz_api_map_node_to_place_summary($parent);
  }
  // HAL embedded.
  if (!empty($parent)) {
    $place['_embedded']['parent'] = _climbnz_api_map_node_to_place($parent, $parameters);
  }

  // A Place could have multiple Parents.
  // Order of parents is not meaningful... (or does primary parent get output first)?
  $node_parents = nodehierarchy_get_node_parents($node->nid);
  //flog_it(__FUNCTION__ . ': node_parents=' . print_r($node_parents, TRUE));
  $parents = array();
  if (count($node_parents)) {
    foreach ($node_parents as $key => $parent) {
      if (!empty($parent)) {
        //flog_it(__FUNCTION__ . ': parent nid=' . $parent->nid . ', title=' . $parent->title);
        $parents[$key] = _climbnz_api_map_node_to_place_summary($parent, $parameters);
      }
    }
  }
  if (!empty($parents)) {
    $place['_links']['parents'] = $parents;
  }

  // Children Places.
  /*
  $child_places_data = climbnz_places_by_place($node->nid);
  $child_places = array();
  if (count($child_places_data)) {
    foreach ($child_places_data as $key => $child_place) {
      $child_place_data = _climbnz_api_map_node_to_place_summary($child_place->_field_data['nid']['entity']);
      $child_places[$key] = $child_place_data;
    }
    if (!empty($child_places)) {
      $place['_links']['children'] = $child_places;
    }
  }
  */
/*
  // Ancestors. The primary lineage of a Place up to top place (NZ).
  // Note that array order is meaningful.
  $ancestor_nids = nodehierarchy_get_node_primary_ancestor_nids($node->nid);
  //flog_it(__FUNCTION__ . ': ancestor_nids=' . print_r($ancestor_nids, TRUE));
  $ancestors = array();
  if (!empty($ancestor_nids)) {
    foreach ($ancestor_nids as $key => $ancestor_nid) {
      $ancestor = node_load($ancestor_nid);
      $ancestors[$key] = _climbnz_api_map_node_to_place_summary($ancestor);
    };
  }
  if (!empty($ancestors)) {
    $place['_links']['ancestors'] = $ancestors;
  }

  // @todo: Get Routes for this Place.
  /*
   * $routes_data = climbnz_routes_by_place($node->nid);
  $routes = array();
  if (count($routes_data)) {
    foreach ($routes_data as $key => $route) {
      $route_data = _climbnz_api_map_node_to_route_summary($route->_field_data['nid']['entity']);
      $routes[$key] = $route_data;
    }
    if (!empty($routes)) {
      $place['_links']['routes'] = $routes;
    }
  }
  */

  return $place;
}


