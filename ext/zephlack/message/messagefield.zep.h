
extern zend_class_entry *zephlack_message_messagefield_ce;

ZEPHIR_INIT_CLASS(Zephlack_Message_MessageField);

PHP_METHOD(Zephlack_Message_MessageField, setTitle);
PHP_METHOD(Zephlack_Message_MessageField, getTitle);
PHP_METHOD(Zephlack_Message_MessageField, setValue);
PHP_METHOD(Zephlack_Message_MessageField, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messagefield_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messagefield_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_message_messagefield_method_entry) {
	PHP_ME(Zephlack_Message_MessageField, setTitle, arginfo_zephlack_message_messagefield_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageField, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageField, setValue, arginfo_zephlack_message_messagefield_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageField, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
