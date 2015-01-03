<?php

namespace Zephlack\Tests\Http;

class HttpHeaderTest extends PHPUnit_Framework_TestCase {

	protected $statusOK = "HTTP/1.1 200 OK";
	protected $statusError = "HTTP/1.1 404 Not Found";
	protected $fields = "foo: bar\r\nbaz: acme";

	public function testParseStatus()
	{
		$header = new Zephlack\Http\Header;
		$header->parse($this->statusOK);
		$this->assertEquals(1.1, $header->version);
		$this->assertEquals(200, $header->statusCode);
		$this->assertEquals("OK", $header->statusMessage);
		$this->assertEquals($this->statusOK, $header->status);
	}

	public function testParseFields()
	{
		$header = new Zephlack\Http\Header;
		$header->parse($this->fields);
		$this->assertEquals("bar", $header->foo);
		$this->assertEquals("acme", $header->baz);
	}

	public function testUndefinedField()
	{
		$header = new Zephlack\Http\Header;
		$this->setExpectedException('Zephlack\Http\HttpException');
		$header->foo;
	}

	/**
	 * @depends testParseStatus
	 * @depends testParseFields
	 * @depends testUndefinedField
	 */
	public function testParse()
	{
		$header = new Zephlack\Http\Header($this->statusOK."\r\n".$this->fields);
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
		$header = new Zephlack\Http\Header([$this->statusOK, "foo: bar", "baz: acme"]);
		$this->assertEquals(1.1, $header->version);
		$this->assertEquals(200, $header->statusCode);
		$this->assertEquals("OK", $header->statusMessage);
		$this->assertEquals($this->statusOK, $header->status);
		$this->assertEquals("bar", $header->foo);
		$this->assertEquals("acme", $header->baz);
	}

	public function testUnsupportedParse()
	{
		$this->setExpectedException('Zephlack\Http\HttpException');
		$header = new Zephlack\Http\Header(123);
		$header->foo = "bar";
	}

	/**
	 * @depends testParseStatus
	 */
	public function testHttpError()
	{
		$this->setExpectedException('Zephlack\Http\HttpException');
		new Zephlack\Http\Header($this->statusError);
	}

	/**
	 * @depends testParseFields
	 */
	public function testCount()
	{
		$header = new Zephlack\Http\Header($this->fields);
		$this->assertCount(2, $header);
	}

	/**
	 * @depends testCount
	 */
	public function testFieldsAccess()
	{
		$header = new Zephlack\Http\Header;
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
		$header = new Zephlack\Http\Header;
		$header->version = 1.1;
		$header->statusCode = 200;
		$header->statusMessage = "OK";
		$this->assertEquals(["HTTP/1.1 200 OK"], $header->build());
		$header->foo = "bar";
		$this->assertEquals(["HTTP/1.1 200 OK","foo: bar"], $header->build());
	}

}
