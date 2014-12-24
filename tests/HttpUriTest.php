<?php

class HttpUriTest extends PHPUnit_Framework_TestCase {

	protected $demoUri = "https://user:pass@host.com:4625/this/is/path?key=value&foo=bar&baz";
	protected $demoComponents = [
		"protocol" => "http",
		"secure" => 1,
		"user" => "user",
		"pass" => "pass",
		"host" => "host.com",
		"port" => 4625,
		"path" => "this/is/path",
		"params" => ["key"=>"value","foo"=>"bar","baz"],
	];

	public function testParse()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->parse($this->demoUri);
		$this->assertEquals($this->demoComponents, $uri->components());
	}

	/**
	 * @depends testParse
	 */
	public function testInitWithString()
	{
		$uri = new Nirlah\Http\Uri($this->demoUri);
		$this->assertEquals($this->demoComponents, $uri->components());
	}

	public function testInitWithArray()
	{
		$uri = new Nirlah\Http\Uri($this->demoComponents);
		$this->assertEquals($this->demoComponents, $uri->components());
	}

	public function testInitWithUnsupported()
	{
		$this->setExpectedException('Nirlah\Http\HttpException');
		new Nirlah\Http\Uri(0);
	}

	//
	// Resolving
	//

	/**
	 * @depends testInitWithArray
	 */
	public function testResolvePath()
	{
		$uri = new Nirlah\Http\Uri($this->demoComponents);

		// Extend:
		$this->assertEquals("https://user:pass@host.com:4625/this/is/path/extended?key=value&foo=bar&baz", $uri->resolvePath("extended"));

		// Overwrite:
		$this->assertEquals("https://user:pass@host.com:4625/overwrite?key=value&foo=bar&baz", $uri->resolvePath("/overwrite"));
	}

	/**
	 * @depends testInitWithArray
	 */
	public function testResolveQuery()
	{
		$uri = new Nirlah\Http\Uri($this->demoComponents);

		// String:
		$this->assertEquals("https://user:pass@host.com:4625/this/is/path?baz=acme&foo", $uri->resolveQuery("baz=acme&foo"));

		// Array:
		$this->assertEquals("https://user:pass@host.com:4625/this/is/path?baz=acme&foo", $uri->resolveQuery(["baz"=>"acme","foo"]));

		// Json:
		$this->assertEquals("https://user:pass@host.com:4625/this/is/path?baz=acme&%23foo%40", $uri->resolveQuery(["baz"=>"acme","#foo@"]), true);

		// Unsupported type:
		$this->setExpectedException('Nirlah\Http\HttpException');
		$uri->resolveQuery(1);
	}

	/**
	 * @depends testResolvePath
	 * @depends testResolveQuery
	 */
	public function testBuild()
	{
		$uri = new Nirlah\Http\Uri($this->demoComponents);
		$this->assertEquals($this->demoUri, $uri->build());
	}

	//
	// Components
	//

	public function testProtocol()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->protocol = "http";
		$this->assertEquals("http", $uri->protocol);
	}

	public function testSecure()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->secure = true;
		$this->assertEquals(true, $uri->secure);
	}

	public function testSecureProtocol()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->protocol = "http";
		$uri->secure = true;
		$this->assertEquals("https", $uri->protocol);
	}

	public function testUser()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->user = "user";
		$this->assertEquals("user", $uri->user);
	}

	public function testPass()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->pass = "pass";
		$this->assertEquals("pass", $uri->pass);
	}

	public function testHost()
	{
		$uri = new Nirlah\Http\Uri;

		$uri->host = "host.com";
		$this->assertEquals("host.com", $uri->host);

		// Remove trailing slash:
		$uri->host = "host.com/";
		$this->assertEquals("host.com", $uri->host);
	}

	public function testPort()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->port = 4625;
		$this->assertEquals(4625, $uri->port);
	}

	public function testPath()
	{
		$uri = new Nirlah\Http\Uri;

		$uri->path = "this/is/path";
		$this->assertEquals("this/is/path", $uri->path);

		// Remove trailing slash:
		$uri->path = "this/is/path/";
		$this->assertEquals("this/is/path", $uri->path);
	}

	public function testParams()
	{
		$uri = new Nirlah\Http\Uri;

		// Array:
		$uri->params = ["foo"=>"bar","baz"];
		$this->assertEquals(["foo"=>"bar","baz"], $uri->params);

		// String with '?':
		$uri->params = "?foo=bar&baz";
		$this->assertEquals(["foo"=>"bar","baz"], $uri->params);

		// String without '?':
		$uri->params = "foo=bar&baz";
		$this->assertEquals(["foo"=>"bar","baz"], $uri->params);
	}

	public function testSetUnknownComponent()
	{
		$uri = new Nirlah\Http\Uri;
		$this->setExpectedException('Nirlah\Http\HttpException');
		$uri->component = "foo";
	}

	public function testGetUnknownComponent()
	{
		$uri = new Nirlah\Http\Uri;
		$this->setExpectedException('Nirlah\Http\HttpException');
		$uri->component;
	}

	public function testIssetComponent()
	{
		$uri = new Nirlah\Http\Uri;
		$this->assertFalse(isset($uri->port));
		$uri->port = 4625;
		$this->assertTrue(isset($uri->port));
	}

	/**
	 * @depends testIssetComponent
	 */
	public function testUnsetComponent()
	{
		$uri = new Nirlah\Http\Uri;
		$uri->port = 4625;
		unset($uri->port);
		$this->assertFalse(isset($uri->port));
	}

}
