
extern zend_class_entry *zephlack_http_uri_ce;

ZEPHIR_INIT_CLASS(Zephlack_Http_Uri);

PHP_METHOD(Zephlack_Http_Uri, __construct);
PHP_METHOD(Zephlack_Http_Uri, __toString);
PHP_METHOD(Zephlack_Http_Uri, parse);
PHP_METHOD(Zephlack_Http_Uri, components);
PHP_METHOD(Zephlack_Http_Uri, build);
PHP_METHOD(Zephlack_Http_Uri, resolve);
PHP_METHOD(Zephlack_Http_Uri, resolvePath);
PHP_METHOD(Zephlack_Http_Uri, resolveQuery);
PHP_METHOD(Zephlack_Http_Uri, buildProtocol);
PHP_METHOD(Zephlack_Http_Uri, buildAuth);
PHP_METHOD(Zephlack_Http_Uri, buildQuery);
PHP_METHOD(Zephlack_Http_Uri, buildPort);
PHP_METHOD(Zephlack_Http_Uri, validateComponentExists);
PHP_METHOD(Zephlack_Http_Uri, __get);
PHP_METHOD(Zephlack_Http_Uri, __set);
PHP_METHOD(Zephlack_Http_Uri, __unset);
PHP_METHOD(Zephlack_Http_Uri, __isset);
PHP_METHOD(Zephlack_Http_Uri, setProtocol);
PHP_METHOD(Zephlack_Http_Uri, getProtocol);
PHP_METHOD(Zephlack_Http_Uri, setHost);
PHP_METHOD(Zephlack_Http_Uri, setPath);
PHP_METHOD(Zephlack_Http_Uri, setParams);
PHP_METHOD(Zephlack_Http_Uri, setAuth);
PHP_METHOD(Zephlack_Http_Uri, setPort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_build, 0, 0, 0)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_resolvepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_resolvequery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_buildquery, 0, 0, 0)
	ZEND_ARG_INFO(0, json)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_validatecomponentexists, 0, 0, 1)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri___get, 0, 0, 1)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri___set, 0, 0, 2)
	ZEND_ARG_INFO(0, component)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_setprotocol, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_setauth, 0, 0, 1)
	ZEND_ARG_INFO(0, auth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_uri_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_http_uri_method_entry) {
	PHP_ME(Zephlack_Http_Uri, __construct, arginfo_zephlack_http_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Http_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, parse, arginfo_zephlack_http_uri_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, components, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, build, arginfo_zephlack_http_uri_build, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, resolve, arginfo_zephlack_http_uri_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, resolvePath, arginfo_zephlack_http_uri_resolvepath, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, resolveQuery, arginfo_zephlack_http_uri_resolvequery, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, buildProtocol, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, buildAuth, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, buildQuery, arginfo_zephlack_http_uri_buildquery, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, buildPort, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, validateComponentExists, arginfo_zephlack_http_uri_validatecomponentexists, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, __get, arginfo_zephlack_http_uri___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, __set, arginfo_zephlack_http_uri___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, __unset, arginfo_zephlack_http_uri___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, __isset, arginfo_zephlack_http_uri___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Uri, setProtocol, arginfo_zephlack_http_uri_setprotocol, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, getProtocol, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, setHost, arginfo_zephlack_http_uri_sethost, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, setPath, arginfo_zephlack_http_uri_setpath, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, setParams, arginfo_zephlack_http_uri_setparams, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, setAuth, arginfo_zephlack_http_uri_setauth, ZEND_ACC_PROTECTED)
	PHP_ME(Zephlack_Http_Uri, setPort, arginfo_zephlack_http_uri_setport, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
