<?php

namespace Zephlack\Tests\Messages;

class MessageTest extends PHPUnit_Framework_TestCase {

	public function testInitWithText()
	{
		$message = new Zephlack\Message\Message('Hello world');
		$this->assertEquals("Hello world", $message->getText());
	}

	public function testChannelAssignment()
	{
		$message = new Zephlack\Message\Message('Hello world');
		$message->setChannel('#test');
		$this->assertEquals("#test", $message->getChannel());
	}

	public function testIconEmojiAssignment()
	{
		$message = new Zephlack\Message\Message('Hello world');
		$message->setIconEmoji(':ghost:');
		$this->assertEquals(":ghost:", $message->geticonEmoji());
	}

	public function testUsernameAssignment()
	{
		$message = new Zephlack\Message\Message('Hello world');
		$message->setUsername('slack-php');
		$this->assertEquals("slack-php", $message->getUsername());
	}

	public function testEnablingLinkedNames()
	{
		$message = new Zephlack\Message\Message('Hello world');
		$message->enableLinkNames(true);
		$this->assertNotFalse(true);
	}
}
