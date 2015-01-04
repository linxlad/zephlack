
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zephlack_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Http, Response, zephlack, http_response, zephlack_http_response_method_entry, 0);

	zend_declare_property_null(zephlack_http_response_ce, SL("header"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_response_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Http_Response, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *body, *header = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &body, &header);

	if (!header) {
		header = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(body)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The response's body must be defined.", "zephlack/http/response.zep", 12);
		return;
	} else if (Z_TYPE_P(body) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The response's body must be a string.", "zephlack/http/response.zep", 14);
		return;
	} else {
		zephir_update_property_this(this_ptr, SL("body"), body TSRMLS_CC);
	}
	if (Z_TYPE_P(header) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zephlack_http_header_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("header"), _0 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseheader", NULL, header);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Response, parseHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *header, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header);



	_0 = Z_TYPE_P(header) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(header, zephlack_http_header_ce TSRMLS_CC));
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("header"), header TSRMLS_CC);
	} else if (Z_TYPE_P(header) == IS_STRING) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephlack_http_header_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, header);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("header"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The header may only be a Header class or string.", "zephlack/http/response.zep", 34);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Response, toObject) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatebody", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_SELF("decodejson", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Response, toArray) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatebody", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("body"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_RETURN_CALL_SELF("decodejson", NULL, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Response, validateBody) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("body"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The response's body is not defined.", "zephlack/http/response.zep", 53);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Response, decodeJson) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool toArray;
	zval *json_param = NULL, *toArray_param = NULL, *parsed, *_0 = NULL, *_1, *_2 = NULL;
	zval *json = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &json_param, &toArray_param);

	zephir_get_strval(json, json_param);
	if (!toArray_param) {
		toArray = 0;
	} else {
		toArray = zephir_get_boolval(toArray_param);
	}


	ZEPHIR_INIT_VAR(parsed);
	zephir_json_decode(parsed, &(parsed), json, zephir_get_intval((toArray ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)))  TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_0, 0)) {
		RETURN_CCTOR(parsed);
	} else {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephlack_http_httpexception_ce);
		ZEPHIR_CALL_FUNCTION(&_2, "json_last_error_msg", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zephlack/http/response.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(Zephlack_Http_Response, __get) {

	zval *attribute_param = NULL, *_0, *_1;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	zephir_get_strval(attribute, attribute_param);


	if (ZEPHIR_IS_STRING(attribute, "body")) {
		RETURN_MM_MEMBER(this_ptr, "body");
	} else if (ZEPHIR_IS_STRING(attribute, "header")) {
		RETURN_MM_MEMBER(this_ptr, "header");
	} else {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("header"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, _0, attribute, PH_NOISY_CC);
		RETURN_CCTOR(_1);
	}

}

PHP_METHOD(Zephlack_Http_Response, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *method_param = NULL, *args_param = NULL, *_0, *_1, *_3;
	zval *method = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(method, method_param);
	zephir_get_arrval(args, args_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	if ((zephir_method_exists(_0, method TSRMLS_CC)  == SUCCESS) == 0) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephlack_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "The header has no method \"", method, "\".");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zephlack/http/response.zep", 83 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_3, Z_STRVAL_P(method), NULL, args);
	zephir_check_call_status();
	RETURN_MM();

}

