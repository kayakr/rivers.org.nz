<?php

class RiversServicesParserJSONv1 implements ServicesParserInterface {
  public function parse(ServicesContextInterface $context) {
    //xdebug_break();
    $requestBody = $context->getRequestBody();
    if ($requestBody) {
      $data = json_decode($requestBody, TRUE);
      if ($data === NULL) {
        return services_error(t('Invalid JSON.'), 400);
      }
      return $data;
    }
    return $requestBody;
  }
}
