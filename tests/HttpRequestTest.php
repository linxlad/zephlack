<?php

class HttpRequestTest extends PHPUnit_Framework_TestCase {

	public function testInitWithHeaderAndUri()
	{
		$request = new Nirlah\Http\Request;
		$this->assertInstanceOf('Nirlah\Http\Header', $request->header);
		$this->assertInstanceOf('Nirlah\Http\Uri', $request->uri);
	}

	public function testUri()
	{
		$request = new Nirlah\Http\Request("http://www.domain.com/");
		$this->assertEquals("http://www.domain.com/", $request->getUri());

		$uri = new Nirlah\Http\Uri("https://www.test.co.il/foo");
		$request->setUri($uri);
		$this->assertSame($uri, $request->uri);

		$request->setUri("http://user:pass@go.com:4625/");
		$this->assertEquals("http://user:pass@go.com:4625/", $request->getUri());
	}

	public function testOptions()
	{
		$request = new Nirlah\Http\Request;
		$this->assertFalse($request->hasOption(CURLOPT_FORBID_REUSE));
		$request->setOption(CURLOPT_FORBID_REUSE, true);
		$this->assertTrue($request->hasOption(CURLOPT_FORBID_REUSE));
		$this->assertEquals(true, $request->getOption(CURLOPT_FORBID_REUSE));
	}

	public function testParams()
	{
		$request = new Nirlah\Http\Request;
		$this->assertFalse(isset($request->foo));
		$request->foo = "bar";
		$this->assertTrue(isset($request->foo));
		$this->assertEquals("bar", $request->foo);
		unset($request->foo);
		$this->assertFalse(isset($request->foo));

		// Multi-set:
		$request->setParams(["foo"=>"bar", "baz"=>"acme"]);
		$this->assertEquals("bar", $request->foo);
		$this->assertEquals("acme", $request->baz);
		$request->clearParams();
		$this->assertFalse(isset($request->foo));
		$this->assertFalse(isset($request->baz));
	}

	public function testHeaders()
	{
		$request = new Nirlah\Http\Request;
		$this->assertFalse($request->hasHeader("foo"));
		$request->setHeader("foo", "bar");
		$this->assertTrue($request->hasHeader("foo"));
		$this->assertEquals("bar", $request->getHeader("foo"));
		$request->unsetHeader("foo");
		$this->assertFalse($request->hasHeader("foo"));

		// Multi-set:
		$request->setHeaders(["foo"=>"bar", "baz"=>"acme"]);
		$this->assertEquals("bar", $request->getHeader("foo"));
		$this->assertEquals("acme", $request->getHeader("baz"));
		$request->clearHeaders();
		$this->assertFalse($request->hasHeader("foo"));
		$this->assertFalse($request->hasHeader("baz"));
	}

}
