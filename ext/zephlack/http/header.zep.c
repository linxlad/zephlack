
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Zephlack_Http_Header) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Http, Header, zephlack, http_header, zephlack_http_header_method_entry, 0);

	zend_declare_property_string(zephlack_http_header_ce, SL("version"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(zephlack_http_header_ce, SL("statusCode"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(zephlack_http_header_ce, SL("statusMessage"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(zephlack_http_header_ce, SL("status"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_http_header_ce, SL("fields"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_bool(zephlack_http_header_ce, SL("THROW_EXCEPTIONS"), 1 TSRMLS_CC);

	zend_class_implements(zephlack_http_header_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

PHP_METHOD(Zephlack_Http_Header, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content);

	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("fields"), _0 TSRMLS_CC);
	if (Z_TYPE_P(content) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "parse", NULL, content);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, parse) {

	zephir_fcall_cache_entry *_25 = NULL;
	HashTable *_21;
	HashPosition _20;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_10 = NULL, *_24 = NULL;
	zval *_2;
	zend_bool _0, _15;
	zval *content = NULL, *_1, *_3 = NULL, *status, *_5, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_11, *_12, *_13, *_14, *_16, *_17, *_18, *_19, *field = NULL, **_22, _23 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);

	ZEPHIR_SEPARATE_PARAM(content);
	ZEPHIR_INIT_VAR(status);
	array_init(status);


	_0 = ZEPHIR_IS_EMPTY(content);
	if (!(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_gettype(_1, content TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 3);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "string", 1);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "array", 1);
		zephir_array_fast_append(_2, _3);
		_0 = zephir_fast_in_array(_1, _2 TSRMLS_CC) == 0;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "parse() can only work with non-empty string or array.", "zephlack/http/header.zep", 23);
		return;
	}
	if (Z_TYPE_P(content) == IS_STRING) {
		ZEPHIR_INIT_NVAR(_3);
		zephir_fast_explode_str(_3, SL("\r\n"), content, LONG_MAX TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&content, "array_filter", &_4, _3);
		zephir_check_call_status();
	}
	zephir_array_fetch_long(&_5, content, 0, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 33 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "|HTTP/(\\d(?:\\.\\d)?)\\s+(\\d{3})\\s+(.+)|i", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(status);
	ZEPHIR_CALL_FUNCTION(&_7, "preg_match", &_8, _6, _5, status);
	zephir_check_temp_parameter(_6);
	Z_UNSET_ISREF_P(status);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		Z_SET_ISREF_P(content);
		ZEPHIR_CALL_FUNCTION(&_9, "array_shift", &_10, content);
		Z_UNSET_ISREF_P(content);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("status"), _9 TSRMLS_CC);
		zephir_array_fetch_long(&_11, status, 1, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 35 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("version"), _11 TSRMLS_CC);
		zephir_array_fetch_long(&_12, status, 2, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 36 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_13);
		ZVAL_LONG(_13, zephir_get_intval(_12));
		zephir_update_property_this(this_ptr, SL("statusCode"), _13 TSRMLS_CC);
		zephir_array_fetch_long(&_14, status, 3, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 37 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("statusMessage"), _14 TSRMLS_CC);
		_15 = 1;
		if (_15) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
			_15 = ZEPHIR_GE_LONG(_13, 400);
		}
		if (_15) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, zephlack_http_httpexception_ce);
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("statusMessage"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_18);
			ZEPHIR_CONCAT_SVSV(_18, "HTTP ", _16, ": ", _17);
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _18, _19);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "zephlack/http/header.zep", 41 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(content, &_21, &_20, 0, 0, "zephlack/http/header.zep", 55);
	for (
	  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
	  ; zephir_hash_move_forward_ex(_21, &_20)
	) {
		ZEPHIR_GET_HVALUE(field, _22);
		if (Z_TYPE_P(field) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_6);
			zephir_fast_explode_str(_6, SL(":"), field, 2  TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_23);
			ZVAL_STRING(&_23, "trim", 0);
			ZEPHIR_CALL_FUNCTION(&field, "array_map", &_24, &_23, _6);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(field TSRMLS_CC) == 2) {
			zephir_array_fetch_long(&_11, field, 0, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 52 TSRMLS_CC);
			zephir_array_fetch_long(&_12, field, 1, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 52 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfield", &_25, _11, _12);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, build) {

	HashTable *_5;
	HashPosition _4;
	zval *flags_param = NULL, *lines, *message = NULL, *_0, *_1, *_2, *_3 = NULL, *field = NULL, *value = NULL, **_6;
	int flags, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flags_param);

	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}
	ZEPHIR_INIT_VAR(lines);
	array_init(lines);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
	ZEPHIR_CALL_SELF(&message, "getmessage", NULL, _0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE(message)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("version"), PH_NOISY_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSVSV(_3, "HTTP/", _1, " ", _2, " ", message);
		zephir_array_append(&lines, _3, PH_SEPARATE, "zephlack/http/header.zep", 63);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_5, &_4, 0, 0, "zephlack/http/header.zep", 71);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(field, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, field, ": ", value);
		zephir_array_append(&lines, _3, PH_SEPARATE, "zephlack/http/header.zep", 68);
	}
	RETURN_CCTOR(lines);

}

PHP_METHOD(Zephlack_Http_Header, setField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfields", NULL, field);
		zephir_check_call_status();
	} else {
		zephir_update_property_array(this_ptr, SL("fields"), field, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, setFields) {

	zval *fields_param = NULL, *_0, *_1;
	zval *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fields_param);

	zephir_get_arrval(fields, fields_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(fields) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("fields"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, getField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0 = NULL, *_1, *_2, *_3;
	zval *field = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasfield", NULL, field);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, field, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 95 TSRMLS_CC);
		RETURN_CTOR(_2);
	} else {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephlack_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "The field \"", field, "\" is not defined.");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zephlack/http/header.zep", 97 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(Zephlack_Http_Header, getFields) {


	RETURN_MEMBER(this_ptr, "fields");

}

PHP_METHOD(Zephlack_Http_Header, hasField) {

	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, field));

}

PHP_METHOD(Zephlack_Http_Header, unsetField) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0 = NULL, *_1;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasfield", NULL, field);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
		zephir_array_unset(&_1, field, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, clearFields) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("fields"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fields"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

PHP_METHOD(Zephlack_Http_Header, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value);

	zephir_get_strval(field, field_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfield", NULL, field, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfield", NULL, field);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Header, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasfield", NULL, field);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Header, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "unsetfield", NULL, field);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Header, getMessage) {

	zval *code_param = NULL, *messages = NULL, *_0;
	int code;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code_param);

	code = zephir_get_intval(code_param);
	ZEPHIR_INIT_VAR(messages);
	array_init(messages);


	ZEPHIR_INIT_NVAR(messages);
	array_init_size(messages, 52);
	add_index_stringl(messages, 100, SL("Continue"), 1);
	add_index_stringl(messages, 101, SL("Switching Protocols"), 1);
	add_index_stringl(messages, 200, SL("OK"), 1);
	add_index_stringl(messages, 201, SL("Created"), 1);
	add_index_stringl(messages, 202, SL("Accepted"), 1);
	add_index_stringl(messages, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(messages, 204, SL("No Content"), 1);
	add_index_stringl(messages, 205, SL("Reset Content"), 1);
	add_index_stringl(messages, 206, SL("Partial Content"), 1);
	add_index_stringl(messages, 300, SL("Multiple Choices"), 1);
	add_index_stringl(messages, 301, SL("Moved Permanently"), 1);
	add_index_stringl(messages, 302, SL("Found"), 1);
	add_index_stringl(messages, 303, SL("See Other"), 1);
	add_index_stringl(messages, 304, SL("Not Modified"), 1);
	add_index_stringl(messages, 305, SL("Use Proxy"), 1);
	add_index_stringl(messages, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(messages, 400, SL("Bad Request"), 1);
	add_index_stringl(messages, 401, SL("Unauthorized"), 1);
	add_index_stringl(messages, 402, SL("Payment Required"), 1);
	add_index_stringl(messages, 403, SL("Forbidden"), 1);
	add_index_stringl(messages, 404, SL("Not Found"), 1);
	add_index_stringl(messages, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(messages, 406, SL("Not Acceptable"), 1);
	add_index_stringl(messages, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(messages, 408, SL("Request Timeout"), 1);
	add_index_stringl(messages, 409, SL("Conflict"), 1);
	add_index_stringl(messages, 410, SL("Gone"), 1);
	add_index_stringl(messages, 411, SL("Length Required"), 1);
	add_index_stringl(messages, 412, SL("Precondition Failed"), 1);
	add_index_stringl(messages, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(messages, 414, SL("Request-URI Too Long"), 1);
	add_index_stringl(messages, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(messages, 416, SL("Requested Range Not Satisfiable"), 1);
	add_index_stringl(messages, 417, SL("Expectation Failed"), 1);
	add_index_stringl(messages, 500, SL("Internal Server Error"), 1);
	add_index_stringl(messages, 501, SL("Not Implemented"), 1);
	add_index_stringl(messages, 502, SL("Bad Gateway"), 1);
	add_index_stringl(messages, 503, SL("Service Unavailable"), 1);
	add_index_stringl(messages, 504, SL("Gateway Timeout"), 1);
	add_index_stringl(messages, 505, SL("HTTP Version Not Supported"), 1);
	add_index_stringl(messages, 509, SL("Bandwidth Limit Exceede"), 1);
	if (zephir_array_isset_long(messages, code)) {
		zephir_array_fetch_long(&_0, messages, code, PH_NOISY | PH_READONLY, "zephlack/http/header.zep", 204 TSRMLS_CC);
		RETURN_CTOR(_0);
	} else {
		RETURN_MM_BOOL(0);
	}

}

