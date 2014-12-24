<?php

class ClientTestTest extends PHPUnit_Framework_TestCase {

	public function testInstantiatable()
	{
		// Array:
		$firstCollection = new Zephlack\Collection(["foo","bar","baz"]);
		$this->assertCount(3, $firstCollection);

		// Collection:
		$secondCollection = new Zephlack\Collection($firstCollection);
		$this->assertCount(3, $firstCollection);

		// Not array or Collection:
		$this->setExpectedException('Exception');
		$thirdCollection = new Zephlack\Collection("sdfsdf");
	}
}
