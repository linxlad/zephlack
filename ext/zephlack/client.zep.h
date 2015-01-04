
extern zend_class_entry *zephlack_client_ce;

ZEPHIR_INIT_CLASS(Zephlack_Client);

PHP_METHOD(Zephlack_Client, setDebug);
PHP_METHOD(Zephlack_Client, getDebug);
PHP_METHOD(Zephlack_Client, __construct);
PHP_METHOD(Zephlack_Client, getUrl);
PHP_METHOD(Zephlack_Client, getToken);
PHP_METHOD(Zephlack_Client, encode);
PHP_METHOD(Zephlack_Client, isOK);
PHP_METHOD(Zephlack_Client, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_client_setdebug, 0, 0, 1)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_client___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, team)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_client_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_client_isok, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_client_notify, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Zephlack\\Message\\Message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_client_method_entry) {
	PHP_ME(Zephlack_Client, setDebug, arginfo_zephlack_client_setdebug, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Client, getDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Client, __construct, arginfo_zephlack_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Client, getUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Client, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Client, encode, arginfo_zephlack_client_encode, ZEND_ACC_PRIVATE)
	PHP_ME(Zephlack_Client, isOK, arginfo_zephlack_client_isok, ZEND_ACC_PRIVATE)
	PHP_ME(Zephlack_Client, notify, arginfo_zephlack_client_notify, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
