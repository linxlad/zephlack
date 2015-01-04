
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Zephlack_Client) {

	ZEPHIR_REGISTER_CLASS_EX(Zephlack, Client, zephlack, client, zephlack_http_request_ce, zephlack_client_method_entry, 0);

	zend_declare_property_string(zephlack_client_ce, SL("url"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(zephlack_client_ce, SL("token"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(zephlack_client_ce, SL("debug"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Zephlack_Client, setDebug) {

	zval *debug;

	zephir_fetch_params(0, 1, 0, &debug);



	zephir_update_property_this(this_ptr, SL("debug"), debug TSRMLS_CC);

}

PHP_METHOD(Zephlack_Client, getDebug) {


	RETURN_MEMBER(this_ptr, "debug");

}

PHP_METHOD(Zephlack_Client, __construct) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *team = NULL, *token = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &team, &token);

	if (!team) {
		team = ZEPHIR_GLOBAL(global_null);
	}
	if (!token) {
		token = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(team)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_clientexception_ce, "Team name is required.", "zephlack/client.zep", 19);
		return;
	}
	if (ZEPHIR_IS_EMPTY(token)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zephlack_clientexception_ce, "API token name is required.", "zephlack/client.zep", 23);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "https://", team, ".slack.com");
	zephir_update_property_this(this_ptr, SL("url"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("token"), token TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("url"), PH_NOISY_CC);
	ZEPHIR_CALL_PARENT(NULL, zephlack_client_ce, this_ptr, "__construct", &_1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	zephir_array_update_string(&_3, SL("token"), &token, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Client, getUrl) {


	RETURN_MEMBER(this_ptr, "url");

}

PHP_METHOD(Zephlack_Client, getToken) {


	RETURN_MEMBER(this_ptr, "token");

}

PHP_METHOD(Zephlack_Client, encode) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_json_encode(return_value, &(return_value), value, 0  TSRMLS_CC);
	return;

}

PHP_METHOD(Zephlack_Client, isOK) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response, *code = NULL, *message = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "statusCode", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&code, response, "__get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "statusMessage", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&message, response, "__get", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_LONG(code, 200);
	if (_1) {
		_1 = ZEPHIR_IS_STRING(message, "OK");
	}
	if (_1) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Zephlack_Client, notify) {

	zval *_11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_13 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *message, *payload = NULL, *response = NULL, *messageArray, *data, *key = NULL, *value = NULL, *valid = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_10, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);

	ZEPHIR_INIT_VAR(data);
	array_init(data);


	if (!(zephir_instance_of_ev(message, zephlack_message_message_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'message' must be an instance of 'Zephlack\\Message\\Message'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(messageArray);
	ZEPHIR_INIT_VAR(_0);
	zephir_json_encode(_0, &(_0), message, 0  TSRMLS_CC);
	zephir_json_decode(messageArray, &(messageArray), _0, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	zephir_is_iterable(messageArray, &_2, &_1, 0, 0, "zephlack/client.zep", 71);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_NVAR(_4);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "/([a-z])([A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "$1_$2", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", &_8, _5, _6, key);
		zephir_check_temp_parameter(_5);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		zephir_fast_strtolower(_4, _7);
		zephir_array_update_zval(&data, _4, &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "encode", &_9, data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "geturl", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_VS(_10, _7, "/services/hooks/incoming-webhook");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturi", NULL, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	array_init_size(_11, 2);
	zephir_array_update_string(&_11, SL("payload"), &payload, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "post", NULL);
	zephir_check_call_status();
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_12)) {
		array_init_size(return_value, 3);
		zephir_array_update_string(&return_value, SL("payload"), &data, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&return_value, SL("response"), &response, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&valid, this_ptr, "isok", &_13, response);
	zephir_check_call_status();
	RETURN_CCTOR(valid);

}

