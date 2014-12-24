<?php

class HttpHeaderTest extends PHPUnit_Framework_TestCase {

	protected $statusOK = "HTTP/1.1 200 OK";
	protected $statusError = "HTTP/1.1 404 Not Found";
	protected $fields = "foo: bar\r\nbaz: acme";

	public function testParseStatus()
	{
		$header = new Nirlah\Http\Header;
		$header->parse($this->statusOK);
		$this->assertEquals(1.1, $header->version);
		$this->assertEquals(200, $header->statusCode);
		$this->assertEquals("OK", $header->statusMessage);
		$this->assertEquals($this->statusOK, $header->status);
	}

	public function testParseFields()
	{
		$header = new Nirlah\Http\Header;
		$header->parse($this->fields);
		$this->assertEquals("bar", $header->foo);
		$this->assertEquals("acme", $header->baz);
	}

	public function testUndefinedField()
	{
		$header = new Nirlah\Http\Header;
		$this->setExpectedException('Nirlah\Http\HttpException');
		$header->foo;
	}

	/**
	 * @depends testParseStatus
	 * @depends testParseFields
	 * @depends testUndefinedField
	 */
	public function testParse()
	{
		$header = new Nirlah\Http\Header($this->statusOK."\r\n".$this->fields);
		$this->assertEquals(1.1, $header->version);
		$this->assertEquals(200, $header->statusCode);
		$this->assertEquals("OK", $header->statusMessage);
		$this->assertEquals($this->statusOK, $header->status);
		$this->assertEquals("bar", $header->foo);
		$this->assertEquals("acme", $header->baz);
	}

	/**
	 * @depends testParseStatus
	 * @depends testParseFields
	 * @depends testUndefinedField
	 */
	public function testParseArray()
	{
		$header = new Nirlah\Http\Header([$this->statusOK, "foo: bar", "baz: acme"]);
		$this->assertEquals(1.1, $header->version);
		$this->assertEquals(200, $header->statusCode);
		$this->assertEquals("OK", $header->statusMessage);
		$this->assertEquals($this->statusOK, $header->status);
		$this->assertEquals("bar", $header->foo);
		$this->assertEquals("acme", $header->baz);
	}

	public function testUnsupportedParse()
	{
		$this->setExpectedException('Nirlah\Http\HttpException');
		$header = new Nirlah\Http\Header(123);
	}

	/**
	 * @depends testParseStatus
	 */
	public function testHttpError()
	{
		$this->setExpectedException('Nirlah\Http\HttpException');
		new Nirlah\Http\Header($this->statusError);
	}

	/**
	 * @depends testParseFields
	 */
	public function testCount()
	{
		$header = new Nirlah\Http\Header($this->fields);
		$this->assertCount(2, $header);
	}

	/**
	 * @depends testCount
	 */
	public function testFieldsAccess()
	{
		$header = new Nirlah\Http\Header;
		$this->assertFalse(isset($header->foo));
		$header->foo = "bar";
		$this->assertTrue(isset($header->foo));
		unset($header->foo);
		$this->assertFalse(isset($header->foo));
	}

	/**
	 * @depends testFieldsAccess
	 */
	public function testBuild()
	{
		$header = new Nirlah\Http\Header;
		$header->version = 1.1;
		$header->statusCode = 200;
		$header->statusMessage = "OK";
		$this->assertEquals(["HTTP/1.1 200 OK"], $header->build());
		$header->foo = "bar";
		$this->assertEquals(["HTTP/1.1 200 OK","foo: bar"], $header->build());
	}

}
