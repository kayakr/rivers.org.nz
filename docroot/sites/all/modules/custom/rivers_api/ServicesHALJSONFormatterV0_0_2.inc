<?php
/**
 * Implement ServicesFormatterInterface to enable HAL+JSON responses.
 */
class ServicesHALJSONFormatterV0_0_2 implements ServicesFormatterInterface {

  public function render($data) {
    $data['version'] = '0.0.2';
    // json_encode doesn't give valid json with data that isn't an array/object.
    if (is_scalar($data)) {
      $data = array($data);
    }
    return str_replace('\\/', '/', json_encode($data));
  }

}

