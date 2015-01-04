
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Zephlack_Collection) {

	ZEPHIR_REGISTER_CLASS(Zephlack, Collection, zephlack, collection, zephlack_collection_method_entry, 0);

	zend_declare_property_null(zephlack_collection_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zephlack_collection_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(zephlack_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zephlack_collection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

PHP_METHOD(Zephlack_Collection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *items = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &items);

	if (!items) {
		items = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	if (Z_TYPE_P(items) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, items);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Collection, all) {


	RETURN_MEMBER(this_ptr, "items");

}

PHP_METHOD(Zephlack_Collection, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

PHP_METHOD(Zephlack_Collection, get) {

	zval *key, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, key, PH_NOISY | PH_READONLY, "zephlack/collection.zep", 26 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Zephlack_Collection, set) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("items"), key, value TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Zephlack_Collection, forget) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	RETURN_THISW();

}

PHP_METHOD(Zephlack_Collection, has) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Zephlack_Collection, contains) {

	zval *value, *_0;

	zephir_fetch_params(0, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_BOOL(zephir_fast_in_array(value, _0 TSRMLS_CC));

}

PHP_METHOD(Zephlack_Collection, isEmpty) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(_0));

}

PHP_METHOD(Zephlack_Collection, add) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_array_append(this_ptr, SL("items"), value TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Zephlack_Collection, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_1, _0, value);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Zephlack_Collection, merge) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *collection, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	_0 = Z_TYPE_P(collection) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(collection, zephlack_collection_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, collection, "all", NULL);
		zephir_check_call_status();
		zephir_fast_array_merge(_1, &(_2), &(_3) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("items"), _1 TSRMLS_CC);
	} else if (Z_TYPE_P(collection) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_fast_array_merge(_1, &(_2), &(collection) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("items"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Collection can merge only array or another Collection.", "zephlack/collection.zep", 75);
		return;
	}
	RETURN_THIS();

}

PHP_METHOD(Zephlack_Collection, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, pullFirst) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, pullLast) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pop", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, pull) {

	zval *key, *value, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(value);
	array_init_size(value, 2);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch(&_1, _0, key, PH_NOISY, "zephlack/collection.zep", 107 TSRMLS_CC);
	zephir_array_fast_append(value, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_unset(&_2, key, PH_SEPARATE);
	zephir_array_fetch_long(&_3, value, 0, PH_NOISY | PH_READONLY, "zephlack/collection.zep", 109 TSRMLS_CC);
	RETURN_CTOR(_3);

}

PHP_METHOD(Zephlack_Collection, random) {

	HashTable *_6;
	HashPosition _5;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *amount_param = NULL, *keys = NULL, *_0, _1, *_3, *_4, *values, *key = NULL, **_7;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &amount_param);

	if (!amount_param) {
		amount = 1;
	} else {
		amount = zephir_get_intval(amount_param);
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, amount);
	ZEPHIR_CALL_FUNCTION(&keys, "array_rand", &_2, _0, &_1);
	zephir_check_call_status();
	if (amount == 1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, keys, PH_NOISY | PH_READONLY, "zephlack/collection.zep", 117 TSRMLS_CC);
		RETURN_CTOR(_4);
	}
	zephir_is_iterable(keys, &_6, &_5, 0, 0, "zephlack/collection.zep", 125);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(key, _7);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, key, PH_NOISY | PH_READONLY, "zephlack/collection.zep", 123 TSRMLS_CC);
		zephir_array_update_zval(&values, key, &_4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(values);

}

PHP_METHOD(Zephlack_Collection, lists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *key, *index = NULL, *items = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &index);

	if (!index) {
		index = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&items, "array_column", &_1, _0, key, index);
	zephir_check_call_status();
	if (Z_TYPE_P(index) != IS_NULL) {
		Z_SET_ISREF_P(items);
		ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_2, items);
		Z_UNSET_ISREF_P(items);
		zephir_check_call_status();
	}
	RETURN_CCTOR(items);

}

PHP_METHOD(Zephlack_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

PHP_METHOD(Zephlack_Collection, inverse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_reverse", &_2, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("items"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Zephlack_Collection, shuffle) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "shuffle", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Zephlack_Collection, implode) {

	zval *glue_param = NULL, *_0;
	zval *glue = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &glue_param);

	zephir_get_strval(glue, glue_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_fast_join(return_value, glue, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, implodeBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *glue = NULL;
	zval *key, *glue_param = NULL, *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &glue_param, &index);

	zephir_get_strval(glue, glue_param);
	if (!index) {
		index = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "lists", NULL, key, index);
	zephir_check_call_status();
	zephir_fast_join(return_value, glue, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *func, *mapped = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&mapped, "array_map", &_1, func, _0);
	zephir_check_call_status();
	object_init_ex(return_value, zephlack_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, mapped);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, walk) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *func, *userData = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &func, &userData);

	if (!userData) {
		userData = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_walk", &_1, _0, func, userData);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Zephlack_Collection, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *func, *filtered = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&filtered, "array_filter", &_1, _0, func);
	zephir_check_call_status();
	object_init_ex(return_value, zephlack_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, filtered);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Collection, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "forget", NULL, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Collection, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Zephlack_Collection, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Zephlack_Collection, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "forget", NULL, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

