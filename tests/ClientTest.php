<?php

class ClientTestTest extends PHPUnit_Framework_TestCase {

	public function testInitWithUriAndToken()
	{
		$client = new Zephlack\Client('team', 'abcdefg');
		$this->assertEquals("https://team.slack.com", $client->getUrl());
		$this->assertEquals('abcdefg', $client->getToken());
	}

	public function testInitWithEmptyTeam()
	{
		try {
			$client = new Zephlack\Client('', 'abcdefg');
		} catch (Exception $e) {
			// Check the exception thrown is an instance clientException
			$this->assertInstanceOf('Zephlack\clientException', $e);
			// Check for correct exception message
			$this->assertEquals($e->getMessage(), 'Team name is required.');
		}
	}

	public function testInitWithEmptyToken()
	{
		try {
			$client = new Zephlack\Client('tracksy', '');
		} catch (Exception $e) {
			// Check the exception thrown is an instance clientException
			$this->assertInstanceOf('Zephlack\clientException', $e);
			// Check for correct exception message
			$this->assertEquals($e->getMessage(), 'API token name is required.');
		}
	}
}
