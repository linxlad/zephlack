
extern zend_class_entry *zephlack_message_message_ce;

ZEPHIR_INIT_CLASS(Zephlack_Message_Message);

PHP_METHOD(Zephlack_Message_Message, setText);
PHP_METHOD(Zephlack_Message_Message, getText);
PHP_METHOD(Zephlack_Message_Message, setChannel);
PHP_METHOD(Zephlack_Message_Message, getChannel);
PHP_METHOD(Zephlack_Message_Message, setUsername);
PHP_METHOD(Zephlack_Message_Message, getUsername);
PHP_METHOD(Zephlack_Message_Message, setIconEmoji);
PHP_METHOD(Zephlack_Message_Message, getIconEmoji);
PHP_METHOD(Zephlack_Message_Message, setIconUrl);
PHP_METHOD(Zephlack_Message_Message, getIconUrl);
PHP_METHOD(Zephlack_Message_Message, setAttachments);
PHP_METHOD(Zephlack_Message_Message, getAttachments);
PHP_METHOD(Zephlack_Message_Message, __construct);
PHP_METHOD(Zephlack_Message_Message, enableLinkNames);
PHP_METHOD(Zephlack_Message_Message, addAttachment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_settext, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_setchannel, 0, 0, 1)
	ZEND_ARG_INFO(0, channel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_setusername, 0, 0, 1)
	ZEND_ARG_INFO(0, username)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_seticonemoji, 0, 0, 1)
	ZEND_ARG_INFO(0, iconEmoji)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_seticonurl, 0, 0, 1)
	ZEND_ARG_INFO(0, iconUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_setattachments, 0, 0, 1)
	ZEND_ARG_INFO(0, attachments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_enablelinknames, 0, 0, 1)
	ZEND_ARG_INFO(0, linkNames)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_message_message_addattachment, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, attachment, Zephlack\\Message\\MessageAttachment, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_message_message_method_entry) {
	PHP_ME(Zephlack_Message_Message, setText, arginfo_zephlack_message_message_settext, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, setChannel, arginfo_zephlack_message_message_setchannel, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getChannel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, setUsername, arginfo_zephlack_message_message_setusername, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getUsername, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, setIconEmoji, arginfo_zephlack_message_message_seticonemoji, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getIconEmoji, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, setIconUrl, arginfo_zephlack_message_message_seticonurl, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getIconUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, setAttachments, arginfo_zephlack_message_message_setattachments, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, getAttachments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, __construct, arginfo_zephlack_message_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Message_Message, enableLinkNames, arginfo_zephlack_message_message_enablelinknames, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Message_Message, addAttachment, arginfo_zephlack_message_message_addattachment, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
