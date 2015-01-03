zephlack
========

[![Travis branch](https://img.shields.io/travis/joyent/node/v0.6.svg?style=flat-square)](https://travis-ci.org/linxlad/zephlack)
[![Stable](https://img.shields.io/badge/stable-1.0-blue.svg?style=flat-square)](https://packagist.org/packages/linxlad/zephlack)
[![Code Quality](https://img.shields.io/badge/code%20quality-B-brightgreen.svg?style=flat-square)](https://www.codacy.com/public/justlikephp/zephlack/dashboard)
[![Packagist](https://img.shields.io/badge/packagist-1.0-blue.svg?style=flat-square)](https://packagist.org/packages/linxlad/zephlack)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](https://github.com/linxlad/zephlack/blob/master/LICENSE.md)
[![Author](https://img.shields.io/badge/Author-%40linxlad-blue.svg?style=flat-square)](https://twitter.com/L0veByte)

Slack Messaging extension written in Zephir.

![Slack output](http://i58.tinypic.com/az6q7o.png)

Slack is a platform for team communication: everything in one place, instantly searchable, available wherever you go. You can find out more about Slack [here](https://slack.com/).

## Installation

##### zmm
Installation via zmm is recommended.

1. install zmm
	```sh
	wget https://github.com/wapmorgan/zmm/archive/master.zip && unzip master.zip && cd zmm-master
	sudo make install
	```

2. install zephir
	```sh
	sudo zmm install --zephir
	```

3. install shell
	```sh
	sudo zmm install zephlack
	```

##### Pre-built extension
Grab the latest extension from [here](https://sourceforge.net/projects/zephlack/files/zephlack.so) and place it in the following directory:
######Ubuntu
`/usr/lib/php5/20.../zephlack.so`

######CentOS
`/usr/lib64/php/modules/zephlack.so`

Add extension to your php configuration:
    
    extension=zephlack.so

#####Self build extension

_(Zephir installation required for this option. Instructions can be found [here](http://zephir-lang.com/install.html#installing-zephir))_

    git clone --depth=1 --branch=master git://github.com/linxlad/zephlack.git linxlad/zephlack
    cd zephlack
    zephir build

Add extension to your php configuration:
    
    extension=zephlack.so
    
Finally restart your web server.

## Usage

### Simple

```php
$client = new Zephlack\Client('team', 'token');
$message = new Zephlack\Message\Message('This year you are on the good list');

$message->setChannel('#channel');
$message->setIconEmoji(':santa:');
$message->setUsername('Mr Claus');

$client->setDebug(false);

/* WIll return bool or if debug is enabled will return the payload and response */
$client->notify($message);
```

### With attachments

```php
$client = new Zephlack\Client('team', 'token');
$message = new Zephlack\Message\Message('This year you are on the good list');
$attachment = new Zephlack\Message\MessageAttachment();
$field = new Zephlack\Message\MessageField();
$field
    ->setTitle('foo')
    ->setValue('bar');

$attachment->addField($field);
$message->addAttachment($attachment);

$message->setChannel('#channel');
$message->setIconEmoji(':santa:');
$message->setUsername('Mr Claus');

$client->notify($message);
```

### Message

If your message contain @username and you want him to be notified, add `$message->enableLinkNames(true)`

### Credits

**I would like to credit:**

**Polem** for the leg work on slack-notifier which this is based. Great PHP slack messaging package which can be found here [slack-notifier](https://github.com/polem/slack-notifier).

**Nirlah** for the http utility that saved me hours of work. Again a great Zephir based package which can be found here [Toolbelt](https://github.com/Nirlah/Toolbelt).


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/linxlad/zephlack/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

