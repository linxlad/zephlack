PHP_ARG_ENABLE(zephlack, whether to enable zephlack, [ --enable-zephlack   Enable Zephlack])

if test "$PHP_ZEPHLACK" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, ZEPHLACK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_ZEPHLACK, 1, [Whether you have Zephlack])
	zephlack_sources="zephlack.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c zephlack/message/message.zep.c
	zephlack/message/messageattachment.zep.c
	zephlack/message/messageexception.zep.c
	zephlack/message/messagefield.zep.c
	zephlack/message/messageinterface.zep.c
	zephlack/client.zep.c
	zephlack/clientexception.zep.c
	zephlack/collection.zep.c
	zephlack/http/header.zep.c
	zephlack/http/httpexception.zep.c
	zephlack/http/request.zep.c
	zephlack/http/response.zep.c
	zephlack/http/uri.zep.c "
	PHP_NEW_EXTENSION(zephlack, $zephlack_sources, $ext_shared,, )
	PHP_SUBST(ZEPHLACK_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([zephlack], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([zephlack], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/zephlack], [php_ZEPHLACK.h])

fi
