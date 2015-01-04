
extern zend_class_entry *zephlack_message_messageattachment_ce;

ZEPHIR_INIT_CLASS(Zephlack_Message_MessageAttachment);

PHP_METHOD(Zephlack_Message_MessageAttachment, setFallback);
PHP_METHOD(Zephlack_Message_MessageAttachment, getFallback);
PHP_METHOD(Zephlack_Message_MessageAttachment, setText);
PHP_METHOD(Zephlack_Message_MessageAttachment, getText);
PHP_METHOD(Zephlack_Message_MessageAttachment, setPretext);
PHP_METHOD(Zephlack_Message_MessageAttachment, getPretext);
PHP_METHOD(Zephlack_Message_MessageAttachment, setColor);
PHP_METHOD(Zephlack_Message_MessageAttachment, getColor);
PHP_METHOD(Zephlack_Message_MessageAttachment, setFields);
PHP_METHOD(Zephlack_Message_MessageAttachment, getFields);
PHP_METHOD(Zephlack_Message_MessageAttachment, addField);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_setfallback, 0, 0, 1)
	ZEND_ARG_INFO(0, fallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_settext, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_setpretext, 0, 0, 1)
	ZEND_ARG_INFO(0, pretext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_setcolor, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_setfields, 0, 0, 1)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_messageattachment_addfield, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, field, Zephlack\\Message\\MessageField, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_message_messageattachment_method_entry) {
	PHP_ME(Zephlack_Message_MessageAttachment, setFallback, arginfo_zephlack_message_messageattachment_setfallback, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, getFallback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, setText, arginfo_zephlack_message_messageattachment_settext, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, getText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, setPretext, arginfo_zephlack_message_messageattachment_setpretext, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, getPretext, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, setColor, arginfo_zephlack_message_messageattachment_setcolor, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, getColor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, setFields, arginfo_zephlack_message_messageattachment_setfields, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_MessageAttachment, addField, arginfo_zephlack_message_messageattachment_addfield, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
