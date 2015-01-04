
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "zephlack.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *zephlack_message_messageinterface_ce;
zend_class_entry *zephlack_http_request_ce;
zend_class_entry *zephlack_client_ce;
zend_class_entry *zephlack_clientexception_ce;
zend_class_entry *zephlack_collection_ce;
zend_class_entry *zephlack_http_header_ce;
zend_class_entry *zephlack_http_httpexception_ce;
zend_class_entry *zephlack_http_response_ce;
zend_class_entry *zephlack_http_uri_ce;
zend_class_entry *zephlack_message_message_ce;
zend_class_entry *zephlack_message_messageattachment_ce;
zend_class_entry *zephlack_message_messageexception_ce;
zend_class_entry *zephlack_message_messagefield_ce;

ZEND_DECLARE_MODULE_GLOBALS(zephlack)

static PHP_MINIT_FUNCTION(zephlack)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Zephlack_Message_MessageInterface);
	ZEPHIR_INIT(Zephlack_Http_Request);
	ZEPHIR_INIT(Zephlack_Client);
	ZEPHIR_INIT(Zephlack_Collection);
	ZEPHIR_INIT(Zephlack_Http_Header);
	ZEPHIR_INIT(Zephlack_Http_HttpException);
	ZEPHIR_INIT(Zephlack_Http_Response);
	ZEPHIR_INIT(Zephlack_Http_Uri);
	ZEPHIR_INIT(Zephlack_Message_Message);
	ZEPHIR_INIT(Zephlack_Message_MessageAttachment);
	ZEPHIR_INIT(Zephlack_Message_MessageField);
	ZEPHIR_INIT(Zephlack_Message_messageException);
	ZEPHIR_INIT(Zephlack_clientException);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zephlack)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephlack_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(zephlack)
{

	zend_zephlack_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zephlack)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(zephlack)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZEPHLACK_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZEPHLACK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZEPHLACK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZEPHLACK_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZEPHLACK_ZEPVERSION);
	php_info_print_table_end();

	php_info_print_table_start();
	php_info_print_table_header(3, "Component", "Version", "Description");
	php_info_print_table_row(3, "Collection", "1.0.0", "Feature rich collection object.");
	php_info_print_table_row(3, "Http", "1.0.0", "Curl based HTTP client");
	php_info_print_table_end();

}

static PHP_GINIT_FUNCTION(zephlack)
{
	php_zephir_init_globals(zephlack_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(zephlack)
{

}

zend_module_entry zephlack_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ZEPHLACK_EXTNAME,
	NULL,
	PHP_MINIT(zephlack),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zephlack),
#else
	NULL,
#endif
	PHP_RINIT(zephlack),
	PHP_RSHUTDOWN(zephlack),
	PHP_MINFO(zephlack),
	PHP_ZEPHLACK_VERSION,
	ZEND_MODULE_GLOBALS(zephlack),
	PHP_GINIT(zephlack),
	PHP_GSHUTDOWN(zephlack),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZEPHLACK
ZEND_GET_MODULE(zephlack)
#endif
