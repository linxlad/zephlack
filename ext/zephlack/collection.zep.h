
extern zend_class_entry *zephlack_collection_ce;

ZEPHIR_INIT_CLASS(Zephlack_Collection);

PHP_METHOD(Zephlack_Collection, __construct);
PHP_METHOD(Zephlack_Collection, all);
PHP_METHOD(Zephlack_Collection, keys);
PHP_METHOD(Zephlack_Collection, get);
PHP_METHOD(Zephlack_Collection, set);
PHP_METHOD(Zephlack_Collection, forget);
PHP_METHOD(Zephlack_Collection, has);
PHP_METHOD(Zephlack_Collection, contains);
PHP_METHOD(Zephlack_Collection, isEmpty);
PHP_METHOD(Zephlack_Collection, add);
PHP_METHOD(Zephlack_Collection, insert);
PHP_METHOD(Zephlack_Collection, merge);
PHP_METHOD(Zephlack_Collection, first);
PHP_METHOD(Zephlack_Collection, last);
PHP_METHOD(Zephlack_Collection, pullFirst);
PHP_METHOD(Zephlack_Collection, pullLast);
PHP_METHOD(Zephlack_Collection, pull);
PHP_METHOD(Zephlack_Collection, random);
PHP_METHOD(Zephlack_Collection, lists);
PHP_METHOD(Zephlack_Collection, count);
PHP_METHOD(Zephlack_Collection, inverse);
PHP_METHOD(Zephlack_Collection, shuffle);
PHP_METHOD(Zephlack_Collection, implode);
PHP_METHOD(Zephlack_Collection, implodeBy);
PHP_METHOD(Zephlack_Collection, map);
PHP_METHOD(Zephlack_Collection, walk);
PHP_METHOD(Zephlack_Collection, filter);
PHP_METHOD(Zephlack_Collection, getIterator);
PHP_METHOD(Zephlack_Collection, offsetGet);
PHP_METHOD(Zephlack_Collection, offsetSet);
PHP_METHOD(Zephlack_Collection, offsetExists);
PHP_METHOD(Zephlack_Collection, offsetUnset);
PHP_METHOD(Zephlack_Collection, __get);
PHP_METHOD(Zephlack_Collection, __set);
PHP_METHOD(Zephlack_Collection, __isset);
PHP_METHOD(Zephlack_Collection, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, items)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_forget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_add, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_insert, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_merge, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_pull, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_random, 0, 0, 0)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_lists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_implode, 0, 0, 1)
	ZEND_ARG_INFO(0, glue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_implodeby, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, glue)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_map, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_walk, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_INFO(0, userData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zephlack_collection___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zephlack_collection_method_entry) {
	PHP_ME(Zephlack_Collection, __construct, arginfo_zephlack_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zephlack_Collection, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, get, arginfo_zephlack_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, set, arginfo_zephlack_collection_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, forget, arginfo_zephlack_collection_forget, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, has, arginfo_zephlack_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, contains, arginfo_zephlack_collection_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, add, arginfo_zephlack_collection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, insert, arginfo_zephlack_collection_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, merge, arginfo_zephlack_collection_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, pullFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, pullLast, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, pull, arginfo_zephlack_collection_pull, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, random, arginfo_zephlack_collection_random, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, lists, arginfo_zephlack_collection_lists, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, inverse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, shuffle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, implode, arginfo_zephlack_collection_implode, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, implodeBy, arginfo_zephlack_collection_implodeby, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, map, arginfo_zephlack_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, walk, arginfo_zephlack_collection_walk, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, filter, arginfo_zephlack_collection_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, offsetGet, arginfo_zephlack_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, offsetSet, arginfo_zephlack_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, offsetExists, arginfo_zephlack_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, offsetUnset, arginfo_zephlack_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, __get, arginfo_zephlack_collection___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, __set, arginfo_zephlack_collection___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, __isset, arginfo_zephlack_collection___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zephlack_Collection, __unset, arginfo_zephlack_collection___unset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
