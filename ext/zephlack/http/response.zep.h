
extern zend_class_entry *zephlack_http_response_ce;

ZEPHIR_INIT_CLASS(Zephlack_Http_Response);

PHP_METHOD(Zephlack_Http_Response, __construct);
PHP_METHOD(Zephlack_Http_Response, parseHeader);
PHP_METHOD(Zephlack_Http_Response, toObject);
PHP_METHOD(Zephlack_Http_Response, toArray);
PHP_METHOD(Zephlack_Http_Response, validateBody);
PHP_METHOD(Zephlack_Http_Response, decodeJson);
PHP_METHOD(Zephlack_Http_Response, __get);
PHP_METHOD(Zephlack_Http_Response, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_response___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_response_parseheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_response_decodejson, 0, 0, 1)
	ZEND_ARG_INFO(0, json)
	ZEND_ARG_INFO(0, toArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_response___get, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_response___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_http_response_method_entry) {
	PHP_ME(Zephlack_Http_Response, __construct, arginfo_zephlack_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Http_Response, parseHeader, arginfo_zephlack_http_response_parseheader, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Response, toObject, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Response, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Response, validateBody, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Response, decodeJson, arginfo_zephlack_http_response_decodejson, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Zephlack_Http_Response, __get, arginfo_zephlack_http_response___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Response, __call, arginfo_zephlack_http_response___call, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
