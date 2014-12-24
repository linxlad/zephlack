<?php

class HttpResponseTest extends PHPUnit_Framework_TestCase {

	protected $dummy = [
		"foo" => "bar",
		"baz" => "acme"
	];

	public function testInitBodyEmpty()
	{
		$this->setExpectedException('Nirlah\Http\HttpException');
		new Nirlah\Http\Response("");
	}

	public function testInitBodyNonString()
	{
		$this->setExpectedException('Nirlah\Http\HttpException');
		new Nirlah\Http\Response(1);
	}

	public function testInitBody()
	{
		$response = new Nirlah\Http\Response("body");
		$this->assertEquals("body", $response->body);
		$this->assertInstanceOf("Nirlah\Http\Header", $response->header);
	}

	public function testInitHeader()
	{
		// String:
		$response = new Nirlah\Http\Response("body", "HTTP/1.1 200 OK");
		$this->assertEquals(new Nirlah\Http\Header("HTTP/1.1 200 OK"), $response->header);

		// Header class:
		$header = new Nirlah\Http\Header;
		$response = new Nirlah\Http\Response("body", $header);
		$this->assertSame($header, $response->header);

		// Other:
		$this->setExpectedException('Nirlah\Http\HttpException');
		new Nirlah\Http\Response("body", 1);
	}

	/**
	 * @depends testInitBody
	 */
	public function testToObject()
	{
		$response = new Nirlah\Http\Response(json_encode($this->dummy));
		$this->assertEquals($this->dummy, $response->toArray());
	}

	/**
	 * @depends testInitBody
	 */
	public function testToArray()
	{
		$response = new Nirlah\Http\Response(json_encode($this->dummy));
		$this->assertEquals((object) $this->dummy, $response->toObject());
	}

	public function testCallHeader()
	{
		$response = new Nirlah\Http\Response("body");

		// Existing method:
		$this->assertInternalType("int", $response->count());

		// Undefined method:
		$this->setExpectedException('Nirlah\Http\HttpException');
		$response->foo();
	}

	public function testHeaderAttribute()
	{
		$response = new Nirlah\Http\Response("body", "HTTP/1.1 200 OK");

		// Existing attribure:
		$this->assertEquals(200, $response->statusCode);

		// Undefined attribure:
		$this->setExpectedException('Nirlah\Http\HttpException');
		$response->foo;
	}

}
