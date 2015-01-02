zephlack
========

Slack Messaging extension written in Zephir.

![Slack output](http://i58.tinypic.com/az6q7o.png)

Slack is a platform for team communication: everything in one place, instantly searchable, available wherever you go. You can find out more about Slack [here](https://slack.com/)

## Installation
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
