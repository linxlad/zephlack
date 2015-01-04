
extern zend_class_entry *zephlack_http_header_ce;

ZEPHIR_INIT_CLASS(Zephlack_Http_Header);

PHP_METHOD(Zephlack_Http_Header, __construct);
PHP_METHOD(Zephlack_Http_Header, parse);
PHP_METHOD(Zephlack_Http_Header, build);
PHP_METHOD(Zephlack_Http_Header, setField);
PHP_METHOD(Zephlack_Http_Header, setFields);
PHP_METHOD(Zephlack_Http_Header, getField);
PHP_METHOD(Zephlack_Http_Header, getFields);
PHP_METHOD(Zephlack_Http_Header, hasField);
PHP_METHOD(Zephlack_Http_Header, unsetField);
PHP_METHOD(Zephlack_Http_Header, clearFields);
PHP_METHOD(Zephlack_Http_Header, count);
PHP_METHOD(Zephlack_Http_Header, __set);
PHP_METHOD(Zephlack_Http_Header, __get);
PHP_METHOD(Zephlack_Http_Header, __isset);
PHP_METHOD(Zephlack_Http_Header, __unset);
PHP_METHOD(Zephlack_Http_Header, getMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_build, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_setfields, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_getfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_hasfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_unsetfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header___set, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header___get, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_http_header_getmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_http_header_method_entry) {
	PHP_ME(Zephlack_Http_Header, __construct, arginfo_zephlack_http_header___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Http_Header, parse, arginfo_zephlack_http_header_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, build, arginfo_zephlack_http_header_build, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, setField, arginfo_zephlack_http_header_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, setFields, arginfo_zephlack_http_header_setfields, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, getField, arginfo_zephlack_http_header_getfield, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, hasField, arginfo_zephlack_http_header_hasfield, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, unsetField, arginfo_zephlack_http_header_unsetfield, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, clearFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, __set, arginfo_zephlack_http_header___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, __get, arginfo_zephlack_http_header___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, __isset, arginfo_zephlack_http_header___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, __unset, arginfo_zephlack_http_header___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Http_Header, getMessage, arginfo_zephlack_http_header_getmessage, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
  PHP_FE_END
};
