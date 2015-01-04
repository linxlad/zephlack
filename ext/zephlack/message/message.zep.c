
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Zephlack_Message_Message) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Message, Message, zephlack, message_message, zephlack_message_message_method_entry, 0);

	zend_declare_property_null(zephlack_message_message_ce, SL("text"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_message_ce, SL("channel"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_message_ce, SL("username"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_message_ce, SL("iconEmoji"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_message_ce, SL("iconUrl"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(zephlack_message_message_ce, SL("linkNames"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_message_ce, SL("attachments"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Message_Message, setText) {

	zval *text;

	zephir_fetch_params(0, 1, 0, &text);



	zephir_update_property_this(this_ptr, SL("text"), text TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getText) {


	RETURN_MEMBER(this_ptr, "text");

}

PHP_METHOD(Zephlack_Message_Message, setChannel) {

	zval *channel;

	zephir_fetch_params(0, 1, 0, &channel);



	zephir_update_property_this(this_ptr, SL("channel"), channel TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getChannel) {


	RETURN_MEMBER(this_ptr, "channel");

}

PHP_METHOD(Zephlack_Message_Message, setUsername) {

	zval *username;

	zephir_fetch_params(0, 1, 0, &username);



	zephir_update_property_this(this_ptr, SL("username"), username TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getUsername) {


	RETURN_MEMBER(this_ptr, "username");

}

PHP_METHOD(Zephlack_Message_Message, setIconEmoji) {

	zval *iconEmoji;

	zephir_fetch_params(0, 1, 0, &iconEmoji);



	zephir_update_property_this(this_ptr, SL("iconEmoji"), iconEmoji TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getIconEmoji) {


	RETURN_MEMBER(this_ptr, "iconEmoji");

}

PHP_METHOD(Zephlack_Message_Message, setIconUrl) {

	zval *iconUrl;

	zephir_fetch_params(0, 1, 0, &iconUrl);



	zephir_update_property_this(this_ptr, SL("iconUrl"), iconUrl TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getIconUrl) {


	RETURN_MEMBER(this_ptr, "iconUrl");

}

PHP_METHOD(Zephlack_Message_Message, setAttachments) {

	zval *attachments;

	zephir_fetch_params(0, 1, 0, &attachments);



	zephir_update_property_this(this_ptr, SL("attachments"), attachments TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_Message, getAttachments) {


	RETURN_MEMBER(this_ptr, "attachments");

}

/**
 * __construct
 *
 * @param string $text message text
 */
PHP_METHOD(Zephlack_Message_Message, __construct) {

	zval *text = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &text);

	if (!text) {
		ZEPHIR_INIT_VAR(text);
		ZVAL_STRING(text, "", 1);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("attachments"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("text"), text TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Message_Message, enableLinkNames) {

	zval *linkNames;

	zephir_fetch_params(0, 1, 0, &linkNames);



	zephir_update_property_this(this_ptr, SL("linkNames"), linkNames TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Zephlack_Message_Message, addAttachment) {

	zval *attachment;

	zephir_fetch_params(0, 1, 0, &attachment);



	if (!(zephir_instance_of_ev(attachment, zephlack_message_messageattachment_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'attachment' must be an instance of 'Zephlack\\Message\\MessageAttachment'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("attachments"), attachment TSRMLS_CC);
	RETURN_THISW();

}

