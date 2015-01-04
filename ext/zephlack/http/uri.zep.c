
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zephlack_Http_Uri) {

	ZEPHIR_REGISTER_CLASS(Zephlack\\Http, Uri, zephlack, http_uri, zephlack_http_uri_method_entry, 0);

	zend_declare_property_string(zephlack_http_uri_ce, SL("_protocol"), "http", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(zephlack_http_uri_ce, SL("_secure"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(zephlack_http_uri_ce, SL("_host"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(zephlack_http_uri_ce, SL("_path"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_uri_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_uri_ce, SL("_user"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_uri_ce, SL("_pass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(zephlack_http_uri_ce, SL("_port"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Http_Uri, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *config = NULL, *component = NULL, *value = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		config = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(config) != IS_NULL) {
		if (Z_TYPE_P(config) == IS_ARRAY) {
			zephir_is_iterable(config, &_1, &_0, 0, 0, "zephlack/http/uri.zep", 22);
			for (
			  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(component, _1, _0);
				ZEPHIR_GET_HVALUE(value, _2);
				zephir_update_property_zval_zval(this_ptr, component, value TSRMLS_CC);
			}
		} else if (Z_TYPE_P(config) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "parse", NULL, config);
			zephir_check_call_status();
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "URI may recive only array or string.", "zephlack/http/uri.zep", 25);
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "build", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, parse) {

	zval *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *parts = NULL, *_0, *_1 = NULL, *_4 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);

	ZEPHIR_SEPARATE_PARAM(uri);


	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("://"), uri, 2  TSRMLS_CC);
	if (zephir_fast_count_int(parts TSRMLS_CC) > 1) {
		zephir_array_fetch_long(&_0, parts, 0, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 42 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprotocol", NULL, _0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_1);
		zephir_array_fetch_long(&_1, parts, 1, PH_NOISY, "zephlack/http/uri.zep", 43 TSRMLS_CC);
		zephir_get_strval(_2, _1);
		ZEPHIR_CPY_WRT(uri, _2);
	}
	ZEPHIR_INIT_NVAR(parts);
	zephir_fast_explode_str(parts, SL("@"), uri, 2  TSRMLS_CC);
	if (zephir_fast_count_int(parts TSRMLS_CC) > 1) {
		ZEPHIR_OBS_NVAR(_1);
		zephir_array_fetch_long(&_1, parts, 0, PH_NOISY, "zephlack/http/uri.zep", 49 TSRMLS_CC);
		zephir_get_strval(_3, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setauth", NULL, _3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch_long(&_4, parts, 1, PH_NOISY, "zephlack/http/uri.zep", 50 TSRMLS_CC);
		zephir_get_strval(_5, _4);
		ZEPHIR_CPY_WRT(uri, _5);
	}
	ZEPHIR_INIT_NVAR(parts);
	zephir_fast_explode_str(parts, SL("?"), uri, 2  TSRMLS_CC);
	if (zephir_fast_count_int(parts TSRMLS_CC) > 1) {
		ZEPHIR_OBS_NVAR(_1);
		zephir_array_fetch_long(&_1, parts, 1, PH_NOISY, "zephlack/http/uri.zep", 56 TSRMLS_CC);
		zephir_get_strval(_6, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, _6);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_4);
		zephir_array_fetch_long(&_4, parts, 0, PH_NOISY, "zephlack/http/uri.zep", 57 TSRMLS_CC);
		zephir_get_strval(_7, _4);
		ZEPHIR_CPY_WRT(uri, _7);
	}
	ZEPHIR_INIT_NVAR(parts);
	zephir_fast_explode_str(parts, SL("/"), uri, 2  TSRMLS_CC);
	if (zephir_fast_count_int(parts TSRMLS_CC) > 1) {
		zephir_array_fetch_long(&_0, parts, 1, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 63 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "/", _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, _8);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_1);
		zephir_array_fetch_long(&_1, parts, 0, PH_NOISY, "zephlack/http/uri.zep", 64 TSRMLS_CC);
		zephir_get_strval(_9, _1);
		ZEPHIR_CPY_WRT(uri, _9);
	}
	ZEPHIR_INIT_NVAR(parts);
	zephir_fast_explode_str(parts, SL(":"), uri, 2  TSRMLS_CC);
	if (zephir_fast_count_int(parts TSRMLS_CC) > 1) {
		zephir_array_fetch_long(&_0, parts, 1, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 70 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setport", NULL, _0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_1);
		zephir_array_fetch_long(&_1, parts, 0, PH_NOISY, "zephlack/http/uri.zep", 71 TSRMLS_CC);
		zephir_get_strval(_10, _1);
		ZEPHIR_CPY_WRT(uri, _10);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sethost", NULL, uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, components) {

	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	array_init_size(return_value, 11);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_protocol"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("protocol"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_secure"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("secure"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_user"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("user"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_pass"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("pass"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_host"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_port"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_path"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("path"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_params"), PH_NOISY_CC);
	zephir_array_update_string(&return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, build) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *json_param = NULL, *_0, *_1;
	zend_bool json;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &json_param);

	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, _0, _1, (json ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, resolve) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool json, isEmptyPath;
	zval *path = NULL, *query = NULL, *json_param = NULL, *protocol = NULL, *auth = NULL, *port = NULL, _0 = zval_used_for_init, *_1 = NULL, _3 = zval_used_for_init, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &path, &query, &json_param);

	if (!path) {
		ZEPHIR_CPY_WRT(path, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(path);
	}
	if (!query) {
		ZEPHIR_CPY_WRT(query, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(query);
	}
	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	ZEPHIR_CALL_METHOD(&protocol, this_ptr, "buildprotocol", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&auth, this_ptr, "buildauth", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&port, this_ptr, "buildport", NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(path) == IS_NULL) {
		ZEPHIR_OBS_NVAR(path);
		zephir_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	} else {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, -1);
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, path, &_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_1, "/")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_LONG(&_3, -1);
			ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, path, &_0, &_3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(path, _4);
		}
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property_this(&_5, this_ptr, SL("_path"), PH_NOISY_CC);
		isEmptyPath = ZEPHIR_IS_EMPTY(_5);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, path, &_0, &_3);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_4, "/")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_CALL_FUNCTION(&_6, "substr", &_2, path, &_0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(path, _6);
		} else if (!(isEmptyPath)) {
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_VSV(_8, _7, "/", path);
			ZEPHIR_CPY_WRT(path, _8);
		}
	}
	if (Z_TYPE_P(query) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&query, this_ptr, "buildquery", NULL, (json ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
	} else if (ZEPHIR_IS_EMPTY(query)) {
		ZEPHIR_INIT_NVAR(query);
		ZVAL_STRING(query, "", 1);
	} else if (Z_TYPE_P(query) == IS_STRING) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, query, &_0, &_3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_LONG(_1, '?')) {
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SV(_8, "?", query);
			ZEPHIR_CPY_WRT(query, _8);
		}
	} else if (Z_TYPE_P(query) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildquery", NULL, (json ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), query);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(query, _1);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_http_httpexception_ce, "The query must be an array or string.", "zephlack/http/uri.zep", 136);
		return;
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_host"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VVVVSVV(return_value, protocol, auth, _7, port, "/", path, query);
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, resolvePath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, path);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, resolveQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool json;
	zval *query, *json_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &query, &json_param);

	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, _0, query, (json ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Http_Uri, buildProtocol) {

	zval *protocol = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(protocol);
	ZVAL_STRING(protocol, "", 1);

	if (zephir_isset_property(this_ptr, SS("_protocol") TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_protocol"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(protocol);
		ZEPHIR_CONCAT_SV(protocol, "", _0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_secure"), PH_NOISY_CC);
		if (zephir_is_true(_1)) {
			zephir_concat_self_str(&protocol, SL("s") TSRMLS_CC);
		}
		zephir_concat_self_str(&protocol, SL("://") TSRMLS_CC);
	}
	RETURN_CCTOR(protocol);

}

PHP_METHOD(Zephlack_Http_Uri, buildAuth) {

	zval *auth = NULL, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(auth);
	ZVAL_STRING(auth, "", 1);

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_user"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0) == 0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_user"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(auth);
		ZEPHIR_CONCAT_SV(auth, "", _1);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("_pass"), PH_NOISY_CC);
		if (ZEPHIR_IS_EMPTY(_2) == 0) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_pass"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SV(_4, ":", _3);
			zephir_concat_self(&auth, _4 TSRMLS_CC);
		}
		zephir_concat_self_str(&auth, SL("@") TSRMLS_CC);
	}
	RETURN_CCTOR(auth);

}

PHP_METHOD(Zephlack_Http_Uri, buildQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *json_param = NULL, *params = NULL, *query = NULL, *key = NULL, *value = NULL, *pairs, **_2, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_7 = NULL;
	zend_bool json;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &json_param, &params);

	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}
	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(params);
	}
	ZEPHIR_INIT_VAR(query);
	ZVAL_STRING(query, "", 1);
	ZEPHIR_INIT_VAR(pairs);
	array_init(pairs);


	if (Z_TYPE_P(params) == IS_NULL) {
		ZEPHIR_OBS_NVAR(params);
		zephir_read_property_this(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	}
	if (ZEPHIR_IS_EMPTY(params) == 0) {
		ZEPHIR_INIT_NVAR(query);
		ZVAL_STRING(query, "?", 1);
		zephir_is_iterable(params, &_1, &_0, 0, 0, "zephlack/http/uri.zep", 200);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			if (json) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_json_encode(_3, &(_3), value, 0  TSRMLS_CC);
				ZEPHIR_CPY_WRT(value, _3);
			}
			if (Z_TYPE_P(key) == IS_STRING) {
				ZEPHIR_CALL_FUNCTION(&_4, "urlencode", &_5, key);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_6, "urlencode", &_5, value);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_VSV(_7, _4, "=", _6);
				zephir_array_append(&pairs, _7, PH_SEPARATE, "zephlack/http/uri.zep", 195);
			} else {
				ZEPHIR_CALL_FUNCTION(&_4, "urlencode", &_5, value);
				zephir_check_call_status();
				zephir_array_append(&pairs, _4, PH_SEPARATE, "zephlack/http/uri.zep", 197);
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		zephir_fast_join_str(_3, SL("&"), pairs TSRMLS_CC);
		zephir_concat_self(&query, _3 TSRMLS_CC);
	}
	RETURN_CCTOR(query);

}

PHP_METHOD(Zephlack_Http_Uri, buildPort) {

	zval *port = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(port);
	ZVAL_STRING(port, "", 1);

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_port"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0) == 0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_port"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(port);
		ZEPHIR_CONCAT_SV(port, ":", _1);
	}
	RETURN_CCTOR(port);

}

PHP_METHOD(Zephlack_Http_Uri, validateComponentExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL, *list = NULL, *_0 = NULL;
	zval *component = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &component_param);

	zephir_get_strval(component, component_param);
	ZEPHIR_INIT_VAR(list);
	array_init(list);


	ZEPHIR_INIT_NVAR(list);
	array_init_size(list, 11);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "protocol", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "secure", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "host", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "path", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "params", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "user", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "pass", 1);
	zephir_array_fast_append(list, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "port", 1);
	zephir_array_fast_append(list, _0);
	if (zephir_fast_in_array(component, list TSRMLS_CC) == 0) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, zephlack_http_httpexception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "The component \"", component, "\" is not a part of the uri.");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "zephlack/http/uri.zep", 223 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, __get) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL, *_0 = NULL, *_1 = NULL, *_3, *_5;
	zval *component = NULL, *method = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &component_param);

	zephir_get_strval(component, component_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatecomponentexists", NULL, component);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "ucfirst", &_2, component);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "get", _1);
	zephir_get_strval(method, _3);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, Z_STRVAL_P(method), NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "_", component);
	ZEPHIR_CPY_WRT(component, _4);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, this_ptr, component, PH_NOISY_CC);
	RETURN_CCTOR(_5);

}

PHP_METHOD(Zephlack_Http_Uri, __set) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL, *value, *_0 = NULL, *_1 = NULL, *_3;
	zval *component = NULL, *method = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &component_param, &value);

	zephir_get_strval(component, component_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatecomponentexists", NULL, component);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "ucfirst", &_2, component);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "set", _1);
	zephir_get_strval(method, _3);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(method), NULL, value);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "_", component);
		ZEPHIR_CPY_WRT(component, _4);
		zephir_update_property_zval_zval(this_ptr, component, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL;
	zval *component = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &component_param);

	zephir_get_strval(component, component_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatecomponentexists", NULL, component);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_", component);
	ZEPHIR_CPY_WRT(component, _0);
	zephir_update_property_zval(this_ptr, Z_STRVAL_P(component), Z_STRLEN_P(component), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL, *_1;
	zval *component = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &component_param);

	zephir_get_strval(component, component_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatecomponentexists", NULL, component);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_", component);
	ZEPHIR_CPY_WRT(component, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, component, PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_1) == 0);

}

PHP_METHOD(Zephlack_Http_Uri, setProtocol) {

	zval *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value = NULL, _0 = zval_used_for_init, *_1 = NULL, _3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, value, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_1, "s")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, -1);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, value, &_0, &_3);
		zephir_check_call_status();
		zephir_get_strval(_5, _4);
		ZEPHIR_CPY_WRT(value, _5);
		zephir_update_property_this(this_ptr, SL("_secure"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_protocol"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, getProtocol) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_secure"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_protocol"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VS(return_value, _1, "s");
		return;
	} else {
		RETURN_MEMBER(this_ptr, "_protocol");
	}

}

PHP_METHOD(Zephlack_Http_Uri, setHost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *uri = NULL, _0 = zval_used_for_init, *_1 = NULL, _3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);

	ZEPHIR_SEPARATE_PARAM(uri);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, uri, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_1, "/")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, -1);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, uri, &_0, &_3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, _4);
	}
	zephir_update_property_this(this_ptr, SL("_host"), uri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value = NULL, _0 = zval_used_for_init, *_1 = NULL, _3 = zval_used_for_init, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_CALL_FUNCTION(&_1, "substr", &_2, value, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_1, "/")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, -1);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, value, &_0, &_3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _4);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "substr", &_2, value, &_0, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_4, "/")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_CALL_FUNCTION(&_5, "substr", &_2, value, &_0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _5);
	}
	zephir_update_property_this(this_ptr, SL("_path"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, setParams) {

	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *query = NULL, *pairs, *pair = NULL, *params, _0 = zval_used_for_init, _1, *_2 = NULL, *_4 = NULL, **_7, *_8 = NULL, *parts = NULL, *_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);
	ZEPHIR_INIT_VAR(params);
	array_init(params);


	if (Z_TYPE_P(query) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_params"), query TSRMLS_CC);
	} else {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, query, &_0, &_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_2, "?")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_CALL_FUNCTION(&_4, "substr", &_3, query, &_0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(query, _4);
		}
		ZEPHIR_INIT_VAR(pairs);
		zephir_fast_explode_str(pairs, SL("&"), query, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(pairs, &_6, &_5, 0, 0, "zephlack/http/uri.zep", 328);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(pair, _7);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "=", 0);
			ZEPHIR_INIT_NVAR(_8);
			zephir_fast_strpos(_8, pair, &_0, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				ZEPHIR_INIT_NVAR(parts);
				zephir_fast_explode_str(parts, SL("="), pair, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_9, parts, 1, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 323 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_10);
				zephir_array_fetch_long(&_10, parts, 0, PH_NOISY, "zephlack/http/uri.zep", 323 TSRMLS_CC);
				zephir_array_update_zval(&params, _10, &_9, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&params, pair, PH_SEPARATE, "zephlack/http/uri.zep", 325);
			}
		}
		zephir_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, setAuth) {

	zval *auth_param = NULL, *parts, *_0, *_1;
	zval *auth = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &auth_param);

	zephir_get_strval(auth, auth_param);


	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL(":"), auth, 2  TSRMLS_CC);
	zephir_array_fetch_long(&_0, parts, 0, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 336 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_user"), _0 TSRMLS_CC);
	zephir_array_fetch_long(&_1, parts, 1, PH_NOISY | PH_READONLY, "zephlack/http/uri.zep", 337 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_pass"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Http_Uri, setPort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *port, *match, *_0, *_1 = NULL, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);

	ZEPHIR_INIT_VAR(match);
	array_init(match);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/(\\d+)/", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(match);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, port, match);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(match);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch_long(&_3, match, 1, PH_NOISY, "zephlack/http/uri.zep", 344 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, zephir_get_intval(_3));
		zephir_update_property_this(this_ptr, SL("_port"), _4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

