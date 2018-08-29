<?php
/**
 * Implement ServicesFormatterInterface to enable HAL+JSON responses.
 */
class ServicesHALJSONFormatterV2 implements ServicesFormatterInterface {

  public function render($data) {
    $data['version'] = '2.0';
    // json_encode doesn't give valid json with data that isn't an array/object.
    if (is_scalar($data)) {
      $data = array($data);
    }
    return str_replace('\\/', '/', json_encode($data));
  }

}

