
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


ZEPHIR_INIT_CLASS(Zephlack_Message_MessageField) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Message, MessageField, zephlack, message_messagefield, zephlack_message_messagefield_method_entry, 0);

	zend_declare_property_null(zephlack_message_messagefield_ce, SL("title"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_message_messagefield_ce, SL("value"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Message_MessageField, setTitle) {

	zval *title;

	zephir_fetch_params(0, 1, 0, &title);



	zephir_update_property_this(this_ptr, SL("title"), title TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageField, getTitle) {


	RETURN_MEMBER(this_ptr, "title");

}

PHP_METHOD(Zephlack_Message_MessageField, setValue) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(this_ptr, SL("value"), value TSRMLS_CC);

}

PHP_METHOD(Zephlack_Message_MessageField, getValue) {


	RETURN_MEMBER(this_ptr, "value");

}

