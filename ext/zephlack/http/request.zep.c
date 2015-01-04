
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Zephlack_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Http, Request, zephlack, http_request, zephlack_http_request_method_entry, 0);

	zend_declare_property_null(zephlack_http_request_ce, SL("uri"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_http_request_ce, SL("header"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(zephlack_http_request_ce, SL("curl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_request_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_request_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(zephlack_http_request_ce, SL("json"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Http_Request, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *uri_param = NULL, *_0, *_1, _2, *_3 = NULL, *_5 = NULL, *_6;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("params"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("options"), _1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "curl", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "extension_loaded", &_4, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The \"curl\" extension is required.", "zephlack/http/request.zep", 16);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "curl_init", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("curl"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, zephlack_http_header_ce);
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("header"), _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturi", NULL, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultoptions", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, setUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *baseUri, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri);



	_0 = Z_TYPE_P(baseUri) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(baseUri, zephlack_http_uri_ce TSRMLS_CC));
	}
	if (_0) {
		zephir_update_property_this(this_ptr, SL("uri"), baseUri TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zephlack_http_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, baseUri);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("uri"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, getUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "build", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, resolveUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resolvePath_param = NULL, *_0;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &resolvePath_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}


	if (ZEPHIR_IS_EMPTY(resolvePath)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "build", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "resolvepath", NULL, resolvePath);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Zephlack_Http_Request, resolveUriWithQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resolvePath_param = NULL, *uri = NULL, *_0, *_1, *_2, *_3;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &resolvePath_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		if (ZEPHIR_IS_EMPTY(resolvePath)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("json"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&uri, _1, "resolvequery", NULL, _2, _3);
			zephir_check_call_status();
		} else {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("json"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&uri, _1, "resolve", NULL, resolvePath, _2, _3);
			zephir_check_call_status();
		}
	} else {
		if (ZEPHIR_IS_EMPTY(resolvePath)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&uri, _1, "build", NULL);
			zephir_check_call_status();
		} else {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&uri, _1, "resolvepath", NULL, resolvePath);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(uri);

}

PHP_METHOD(Zephlack_Http_Request, send) {

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *header = NULL, *content = NULL, *headerSize = NULL, *body = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6 = NULL, *_8, *_9 = NULL, *_10, *_11 = NULL, _12 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(header);
	array_init(header);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&header, _1, "build", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Expect:", 1);
	zephir_array_append(&header, _2, PH_SEPARATE, "zephlack/http/request.zep", 86);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10023);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, header);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt_array", NULL, _1, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&content, "curl_exec", NULL, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "curl_errno", &_7, _5);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(_6, 0)) {
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, zephlack_http_httpexception_ce);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_9, "curl_error", NULL, _8);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "curl_errno", &_7, _10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _9, _11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zephlack/http/request.zep", 95 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("curl"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 2097163);
	ZEPHIR_CALL_FUNCTION(&headerSize, "curl_getinfo", NULL, _1, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&body, "substr", &_13, content, headerSize);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_CALL_FUNCTION(&header, "substr", &_13, content, &_12, headerSize);
	zephir_check_call_status();
	object_init_ex(return_value, zephlack_http_response_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, body, header);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resolvePath_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &resolvePath_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolveuriwithquery", NULL, resolvePath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 10002);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 80);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 10036);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool encodeParams;
	zval *resolvePath_param = NULL, *encodeParams_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &resolvePath_param, &encodeParams_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}
	if (!encodeParams_param) {
		encodeParams = 1;
	} else {
		encodeParams = zephir_get_boolval(encodeParams_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("json"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getjsonparams", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 10015);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpostparams", NULL, (encodeParams ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 10015);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolveuri", NULL, resolvePath);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10002);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 47);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10036);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, head) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resolvePath_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &resolvePath_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolveuriwithquery", NULL, resolvePath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 10002);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 80);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 10036);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "HEAD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool encodeParams;
	zval *resolvePath_param = NULL, *encodeParams_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &resolvePath_param, &encodeParams_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}
	if (!encodeParams_param) {
		encodeParams = 1;
	} else {
		encodeParams = zephir_get_boolval(encodeParams_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("json"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getjsonparams", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 10015);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpostparams", NULL, (encodeParams ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 10015);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolveuri", NULL, resolvePath);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10002);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 47);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 10036);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _2, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resolvePath_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *resolvePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &resolvePath_param);

	if (!resolvePath_param) {
		ZEPHIR_INIT_VAR(resolvePath);
		ZVAL_EMPTY_STRING(resolvePath);
	} else {
		zephir_get_strval(resolvePath, resolvePath_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolveuriwithquery", NULL, resolvePath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 10002);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 80);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 10036);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "DELETE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _1, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "send", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, setDefaultOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 19913);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 58);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 52);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 42);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 78);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 13);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 181);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (1 | 2));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 182);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, (1 | 2));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoption", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, setOption) {

	zval *option_param = NULL, *value = NULL, *_0;
	int option;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option_param, &value);

	option = zephir_get_intval(option_param);
	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, option);
	zephir_update_property_array(this_ptr, SL("options"), _0, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, getOption) {

	zval *option_param = NULL, *_0 = NULL, *_1, *_2, *_3;
	int option, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	option = zephir_get_intval(option_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, option);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, _1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
		zephir_array_fetch_long(&_3, _2, option, PH_NOISY | PH_READONLY, "zephlack/http/request.zep", 179 TSRMLS_CC);
		RETURN_CTOR(_3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The option was not set before.", "zephlack/http/request.zep", 181);
		return;
	}

}

PHP_METHOD(Zephlack_Http_Request, hasOption) {

	zval *option_param = NULL, *_0;
	int option;

	zephir_fetch_params(0, 1, 0, &option_param);

	option = zephir_get_intval(option_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset_long(_0, option));

}

PHP_METHOD(Zephlack_Http_Request, getPostParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *useEncoding_param = NULL, *params = NULL, *param = NULL, *_0, **_3, *_5 = NULL, *_6 = NULL;
	zend_bool useEncoding, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &useEncoding_param);

	useEncoding = zephir_get_boolval(useEncoding_param);
	ZEPHIR_INIT_VAR(params);
	array_init(params);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(params, _0);
	zephir_is_iterable(params, &_2, &_1, 0, 0, "zephlack/http/request.zep", 205);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(param, _3);
		_4 = Z_TYPE_P(param) == IS_STRING;
		if (_4) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "/^@/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, _5, param);
			zephir_check_temp_parameter(_5);
			zephir_check_call_status();
			_4 = zephir_is_true(_6);
		}
		if (_4) {
			useEncoding = 0;
			break;
		}
	}
	if (useEncoding) {
		ZEPHIR_CALL_FUNCTION(&_6, "http_build_query", &_8, params);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(params, _6);
	}
	RETURN_CCTOR(params);

}

PHP_METHOD(Zephlack_Http_Request, getJsonParams) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	zephir_json_encode(return_value, &(return_value), _0, 0  TSRMLS_CC);
	return;

}

PHP_METHOD(Zephlack_Http_Request, setParams) {

	zval *params_param = NULL, *_0, *_1;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(params) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("params"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, setParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &param, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(param) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, param);
		zephir_check_call_status();
	} else {
		zephir_update_property_array(this_ptr, SL("params"), param, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, getParam) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL, *_0 = NULL, *_1, *_2, *_3;
	zval *param = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasparam", NULL, param);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, param, PH_NOISY | PH_READONLY, "zephlack/http/request.zep", 234 TSRMLS_CC);
		RETURN_CTOR(_2);
	} else {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephlack_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "The parameter \"", param, "\" is not defined.");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zephlack/http/request.zep", 236 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(Zephlack_Http_Request, getParams) {


	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Zephlack_Http_Request, hasParam) {

	zval *param_param = NULL, *_0;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, param));

}

PHP_METHOD(Zephlack_Http_Request, unsetParam) {

	zval *param_param = NULL, *_0;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	zephir_array_unset(&_0, param, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, clearParams) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("params"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL, *value;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &param_param, &value);

	zephir_get_strval(param, param_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparam", NULL, param, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparam", NULL, param);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasparam", NULL, param);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_param);

	zephir_get_strval(param, param_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "unsetparam", NULL, param);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, setHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field, *value = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheaders", NULL, field);
		zephir_check_call_status();
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0, "setfield", NULL, field, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, setHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields_param = NULL, *_0;
	zval *fields = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fields_param);

	zephir_get_arrval(fields, fields_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setfields", NULL, fields);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getfield", NULL, field);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, hasHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "hasfield", NULL, field);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Request, unsetHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "unsetfield", NULL, field);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, clearHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "clearfields", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Request, useJson) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	add_assoc_stringl_ex(_0, SS("Content-Type"), SL("application/json"), 1);
	add_assoc_stringl_ex(_0, SS("Accept"), SL("application/json; charset=UTF-8"), 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheaders", NULL, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("json"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

