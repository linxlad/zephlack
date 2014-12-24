<?php

class Neo4jStatementTest extends PHPUnit_Framework_TestCase {

	protected $statement = "MATCH n RETURN n";
	protected $components = [
		"statement" => "MATCH n RETURN n",
		"resultDataContents" => ["row","graph"]
	];

	public function testInstanitateBare()
	{
		$this->setExpectedException("BadMethodCallException");
		new Nirlah\Neo4j\Transactions\Statement;
	}

	public function testBuild()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement($this->statement);
		$this->assertEquals($this->components, $statement->build());
	}

	public function testParams()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement($this->statement);
		$this->assertFalse(isset($statement->foo));
		$statement->foo = "bar";
		$this->assertTrue(isset($statement->foo));
		$this->assertEquals("bar", $statement->foo);
		unset($statement->foo);
		$this->assertFalse(isset($statement->foo));
	}

	/**
	 * @depends testBuild
	 * @depends testParams
	 */
	public function testBuildParams()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement($this->statement);
		$statement->foo = "bar";
		$statement->baz = 2;
		$components = $this->components;
		$components['parameters'] = ["foo"=>"bar", "baz"=>2];
		$this->assertEquals($components, $statement->build());
	}

	public function testFormat()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement($this->statement);

		// Rest:
		$statement->formatAsRest();
		$components = $this->components;
		$components['resultDataContents'] = ["REST"];
		$this->assertEquals($components, $statement->build());

		// Graph:
		$statement->formatAsGraph();
		$components = $this->components;
		$components['resultDataContents'] = ["graph"];
		$this->assertEquals($components, $statement->build());

		// Row:
		$statement->formatAsRow();
		$components = $this->components;
		$components['resultDataContents'] = ["row"];
		$this->assertEquals($components, $statement->build());

		// Row & Graph:
		$components = $this->components;
		$components['resultDataContents'] = ["row","graph"];
		$statement->formatAsRowAndGraph();
		$this->assertEquals($components, $statement->build());
		$statement->formatAsGraphAndRow();
		$this->assertEquals($components, $statement->build());
	}

	// 
	// testCommit
	// 

	public function testTable()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement("MATCH (s:Show)--(e:Episode) return s, e");
		$statement->commit();
		$components = $arrayName = [[
			's'=>['name'=>'Gotham'],
			'e'=>['num'=>1]
		]];
		$this->assertEquals($components, $statement->getTable());
	}

	public function testGraph()
	{
		$statement = new Nirlah\Neo4j\Transactions\Statement("MATCH (s:Show)--(e:Episode) return s, e");
		$statement->commit();
		print_r($statement->getGraphs());
	}

}
