<?php

class Neo4jLazyTransactionTest extends PHPUnit_Framework_TestCase {

	public function testAllStatements()
	{
		$transaction = new Nirlah\Neo4j\Transactions\LazyTransaction;
		$this->assertInternalType("array", $transaction->allStatements());
	}

	public function testAdd()
	{
		$transaction = new Nirlah\Neo4j\Transactions\LazyTransaction;

		// String:
		$transaction->add("MATCH (n) return n");
		$all = $transaction->allStatements();
		$this->assertCount(1, $all);
		$this->assertInstanceOf("Nirlah\Neo4j\Transactions\Statement", $all[0]);

		// Statement:
		$statement = new Nirlah\Neo4j\Transactions\Statement("MATCH (n) return n");
		$transaction->add($statement);
		$this->assertCount(2, $transaction->allStatements());

		// Unsupported:
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		$transaction->add(true);
	}

	public function testCommit()
	{
		$transaction = new Nirlah\Neo4j\Transactions\LazyTransaction;
		$udid = uniqid();
		// 
		// $transaction->add("MATCH (n:`Foo $udid`) return n");
		// 
		$transaction->add("MATCH (s:Show)--(e:Episode) return s, e");
		$transaction->commit();
		// 
		// ...
		// 
		// print_r($transaction->getColumns());
	}

	/**
	 * @depends testCommit
	 */
	public function testAddAfterCommit()
	{
		$transaction = new Nirlah\Neo4j\Transactions\LazyTransaction;
		$transaction->commit();
		$this->setExpectedException("Nirlah\Neo4j\Neo4jException");
		$transaction->add("MATCH (n) return n");
	}

}
