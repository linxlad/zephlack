
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


ZEPHIR_INIT_CLASS(Zephlack_Message_MessageAttachment) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Message, MessageAttachment, zephlack, message_messageattachment, zephlack_message_messageattachment_method_entry, 0);

	zend_declare_property_null(zephlack_message_messageattachment_ce, SL("fallback"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_messageattachment_ce, SL("text"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_messageattachment_ce, SL("pretext"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_messageattachment_ce, SL("color"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_messageattachment_ce, SL("fields"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Message_MessageAttachment, setFallback) {

	zval *fallback;

	zephir_fetch_params(0, 1, 0, &fallback);



	zephir_update_property_this(this_ptr, SL("fallback"), fallback TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageAttachment, getFallback) {


	RETURN_MEMBER(this_ptr, "fallback");

}

PHP_METHOD(Zephlack_Message_MessageAttachment, setText) {

	zval *text;

	zephir_fetch_params(0, 1, 0, &text);



	zephir_update_property_this(this_ptr, SL("text"), text TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageAttachment, getText) {


	RETURN_MEMBER(this_ptr, "text");

}

PHP_METHOD(Zephlack_Message_MessageAttachment, setPretext) {

	zval *pretext;

	zephir_fetch_params(0, 1, 0, &pretext);



	zephir_update_property_this(this_ptr, SL("pretext"), pretext TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageAttachment, getPretext) {


	RETURN_MEMBER(this_ptr, "pretext");

}

PHP_METHOD(Zephlack_Message_MessageAttachment, setColor) {

	zval *color;

	zephir_fetch_params(0, 1, 0, &color);



	zephir_update_property_this(this_ptr, SL("color"), color TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageAttachment, getColor) {


	RETURN_MEMBER(this_ptr, "color");

}

PHP_METHOD(Zephlack_Message_MessageAttachment, setFields) {

	zval *fields;

	zephir_fetch_params(0, 1, 0, &fields);



	zephir_update_property_this(this_ptr, SL("fields"), fields TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageAttachment, getFields) {


	RETURN_MEMBER(this_ptr, "fields");

}

PHP_METHOD(Zephlack_Message_MessageAttachment, addField) {

	zval *field;

	zephir_fetch_params(0, 1, 0, &field);



	if (!(zephir_instance_of_ev(field, zephlack_message_messagefield_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'field' must be an instance of 'Zephlack\\Message\\MessageField'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("fields"), field TSRMLS_CC);
	RETURN_THISW();

}

