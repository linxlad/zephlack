<?php

class Neo4jConnectionsTest extends PHPUnit_Framework_TestCase {

	protected $settings = [
		'host' => 'domain.com',
		'port' => 6363,
		'secure' => true
	];

	protected $uri = "https://domain.com:6363/db/data";

	public function testInstatiateDefault()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$this->assertInstanceOf("Nirlah\Http\Request", $manager->getDefault());
	}

	public function testInstatiateCustom()
	{
		$manager = new Nirlah\Neo4j\Connections($this->settings);
		$connection = $manager->getDefault();
		$this->assertInstanceOf("Nirlah\Http\Request", $connection);
		$this->assertEquals($this->uri, $connection->getUri());
	}

	public function testInstatiateUnsuppoerted()
	{
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		new Nirlah\Neo4j\Connections("connection");
	}

	public function testMutating()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$manager->foo = $this->settings;
		$this->assertInstanceOf("Nirlah\Http\Request", $manager->foo);
		$this->assertEquals($this->uri, $manager->foo->getUri());

		// Not array:
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		$manager->bar = "connection";
	}

	public function testSetDefaultSettings()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$manager->setDefault($this->settings);
		$this->assertEquals($this->uri, $manager->getDefault()->getUri());
	}

	/**
	 * @depends testMutating
	 */
	public function testSetDefaultName()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$manager->foo = $this->settings;
		$manager->setDefault("foo");
		$this->assertEquals($this->uri, $manager->getDefault()->getUri());
	}

	public function testSetUnsupportedDefault()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		$manager->setDefault(true);
	}

	public function testSetUnknownDefault()
	{
		$manager = new Nirlah\Neo4j\Connections;
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		$manager->setDefault("foo");
	}

}
