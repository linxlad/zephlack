
extern zend_class_entry *zephlack_http_request_ce;

ZEPHIR_INIT_CLASS(Zephlack_Http_Request);

PHP_METHOD(Zephlack_Http_Request, __construct);
PHP_METHOD(Zephlack_Http_Request, __destruct);
PHP_METHOD(Zephlack_Http_Request, setUri);
PHP_METHOD(Zephlack_Http_Request, getUri);
PHP_METHOD(Zephlack_Http_Request, resolveUri);
PHP_METHOD(Zephlack_Http_Request, resolveUriWithQuery);
PHP_METHOD(Zephlack_Http_Request, send);
PHP_METHOD(Zephlack_Http_Request, get);
PHP_METHOD(Zephlack_Http_Request, post);
PHP_METHOD(Zephlack_Http_Request, head);
PHP_METHOD(Zephlack_Http_Request, put);
PHP_METHOD(Zephlack_Http_Request, delete);
PHP_METHOD(Zephlack_Http_Request, setDefaultOptions);
PHP_METHOD(Zephlack_Http_Request, setOption);
PHP_METHOD(Zephlack_Http_Request, getOption);
PHP_METHOD(Zephlack_Http_Request, hasOption);
PHP_METHOD(Zephlack_Http_Request, getPostParams);
PHP_METHOD(Zephlack_Http_Request, getJsonParams);
PHP_METHOD(Zephlack_Http_Request, setParams);
PHP_METHOD(Zephlack_Http_Request, setParam);
PHP_METHOD(Zephlack_Http_Request, getParam);
PHP_METHOD(Zephlack_Http_Request, getParams);
PHP_METHOD(Zephlack_Http_Request, hasParam);
PHP_METHOD(Zephlack_Http_Request, unsetParam);
PHP_METHOD(Zephlack_Http_Request, clearParams);
PHP_METHOD(Zephlack_Http_Request, __set);
PHP_METHOD(Zephlack_Http_Request, __get);
PHP_METHOD(Zephlack_Http_Request, __isset);
PHP_METHOD(Zephlack_Http_Request, __unset);
PHP_METHOD(Zephlack_Http_Request, setHeader);
PHP_METHOD(Zephlack_Http_Request, setHeaders);
PHP_METHOD(Zephlack_Http_Request, getHeader);
PHP_METHOD(Zephlack_Http_Request, hasHeader);
PHP_METHOD(Zephlack_Http_Request, unsetHeader);
PHP_METHOD(Zephlack_Http_Request, clearHeaders);
PHP_METHOD(Zephlack_Http_Request, useJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_resolveuri, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_resolveuriwithquery, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_get, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_post, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
	ZEND_ARG_INFO(0, encodeParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_head, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_put, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
	ZEND_ARG_INFO(0, encodeParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, resolvePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_setoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_hasoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_getpostparams, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_setparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_hasparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_unsetparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request___set, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request___get, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_setheader, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_request_unsetheader, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_http_request_method_entry) {
	PHP_ME(Zephlack_Http_Request, __construct, arginfo_zephlack_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Http_Request, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Zephlack_Http_Request, setUri, arginfo_zephlack_http_request_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, resolveUri, arginfo_zephlack_http_request_resolveuri, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, resolveUriWithQuery, arginfo_zephlack_http_request_resolveuriwithquery, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, send, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, get, arginfo_zephlack_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, post, arginfo_zephlack_http_request_post, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, head, arginfo_zephlack_http_request_head, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, put, arginfo_zephlack_http_request_put, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, delete, arginfo_zephlack_http_request_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, setDefaultOptions, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, setOption, arginfo_zephlack_http_request_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getOption, arginfo_zephlack_http_request_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, hasOption, arginfo_zephlack_http_request_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getPostParams, arginfo_zephlack_http_request_getpostparams, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, getJsonParams, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Request, setParams, arginfo_zephlack_http_request_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, setParam, arginfo_zephlack_http_request_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getParam, arginfo_zephlack_http_request_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, hasParam, arginfo_zephlack_http_request_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, unsetParam, arginfo_zephlack_http_request_unsetparam, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, clearParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, __set, arginfo_zephlack_http_request___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, __get, arginfo_zephlack_http_request___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, __isset, arginfo_zephlack_http_request___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, __unset, arginfo_zephlack_http_request___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, setHeader, arginfo_zephlack_http_request_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, setHeaders, arginfo_zephlack_http_request_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, getHeader, arginfo_zephlack_http_request_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, hasHeader, arginfo_zephlack_http_request_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, unsetHeader, arginfo_zephlack_http_request_unsetheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, clearHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Request, useJson, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
