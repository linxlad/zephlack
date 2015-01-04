
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zephlack_Message_MessageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zephlack\\Message, MessageInterface, zephlack, message_messageinterface, NULL);

	return SUCCESS;

}

