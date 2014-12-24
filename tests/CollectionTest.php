<?php

class CollectionTest extends PHPUnit_Framework_TestCase {

	public function testInstantiatable()
	{
		// Array:
		$firstCollection = new Nirlah\Collection(["foo","bar","baz"]);
		$this->assertCount(3, $firstCollection);

		// Collection:
		$secondCollection = new Nirlah\Collection($firstCollection);
		$this->assertCount(3, $firstCollection);

		// Not array or Collection:
		$this->setExpectedException('Exception');
		$thirdCollection = new Nirlah\Collection("sdfsdf");
	}

	public function testOOProperties()
	{
		$collection = new Nirlah\Collection;
		$collection->foo = "bar";
		$this->assertEquals("bar", $collection->foo);
		$this->assertTrue(isset($collection->foo));
		unset($collection->foo);
		$this->assertCount(0, $collection);
	}

	public function testArray()
	{
		$collection = new Nirlah\Collection;
		$collection['foo'] = "bar";
		$this->assertEquals("bar", $collection['foo']);
		$this->assertTrue(isset($collection['foo']));
		unset($collection['foo']);
		$this->assertCount(0, $collection);
	}

	public function testOOMethod()
	{
		$collection = new Nirlah\Collection;
		$collection->set('foo', "bar");
		$this->assertEquals("bar", $collection->get('foo'));
		$this->assertTrue($collection->has('foo'));
		$collection->forget('foo');
		$this->assertCount(0, $collection);
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testIteratable()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz"=>"acme"]);
		$i = 0;
		foreach ($collection as $key => $value) {
			switch ($i) {
				case 0:
					$this->assertEquals("foo", $value);
					break;
				case 1:
					$this->assertEquals("bar", $value);
					break;
				case 2:
					$this->assertEquals("baz", $key);
					$this->assertEquals("acme", $value);
					break;
			}
			$i++;
		}
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testAllMethod()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz"=>"acme"]);
		$this->assertEquals(["foo","bar","baz"=>"acme"], $collection->all());
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testOrderedAdding()
	{
		$collection = new Nirlah\Collection(["middle"]);
		$collection->add("last");
		$collection->insert("first");
		$this->assertEquals(["first","middle","last"], $collection->all());
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testMergingArray()
	{
		// Add items:
		$collection = new Nirlah\Collection(['foo'=>'bar']);
		$collection->merge(['baz'=>'acme']);
		$this->assertEquals(['foo'=>'bar','baz'=>'acme'], $collection->all());

		// Overwrite items:
		$collection->merge(['foo'=>'bang']);
		$this->assertEquals(['foo'=>'bang','baz'=>'acme'], $collection->all());
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testMergingCollection()
	{
		// Add items:
		$firstCollection = new Nirlah\Collection(['foo'=>'bar']);
		$secondCollection = new Nirlah\Collection(['baz'=>'acme']);
		$firstCollection->merge($secondCollection);
		$this->assertEquals(['foo'=>'bar','baz'=>'acme'], $firstCollection->all());

		// Overwrite items:
		$thirdCollection = new Nirlah\Collection(['foo'=>'bang']);
		$firstCollection->merge($thirdCollection);
		$this->assertEquals(['foo'=>'bang','baz'=>'acme'], $firstCollection->all());
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testGet()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz","acme","bang"]);
		$this->assertEquals("foo", $collection->first());
		$this->assertEquals("bang", $collection->last());
		$this->assertContains($collection->random(), $collection->all());
		$this->assertCount(2, $collection->random(2));
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testPull()
	{
		$collection = new Nirlah\Collection(["foo","bar","key"=>"baz","acme","bang"]);

		// Key:
		$this->assertEquals("baz", $collection->pull("key"));
		$this->assertCount(4, $collection->all());

		// First:
		$this->assertEquals("foo", $collection->pullFirst());
		$this->assertCount(3, $collection->all());

		// Last:
		$this->assertEquals("bang", $collection->pullLast());
		$this->assertCount(2, $collection->all());

		// // Random:
		// $all = $collection->all();
		// $this->assertContains($collection->pullRandom(), $all);
		// $this->assertCount(1, $collection->all());
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testContains()
	{
		$collection = new Nirlah\Collection(["foo"]);
		$this->assertTrue($collection->contains("foo"));
		$this->assertFalse($collection->contains("bar"));
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testEmpty()
	{
		$firstCollection = new Nirlah\Collection;
		$this->assertTrue($firstCollection->isEmpty());

		$secondCollection = new Nirlah\Collection(["foo"]);
		$this->assertFalse($secondCollection->isEmpty());
	}

	/**
	 * @depends testInstantiatable
	 * @depends testAllMethod
	 */
	public function testCount()
	{
		$firstCollection = new Nirlah\Collection(["foo","bar","baz"]);
		$this->assertEquals(3, $firstCollection->count());
		$this->assertCount(3, $firstCollection->all());

		$secondCollection = new Nirlah\Collection;
		$this->assertEquals(0, $secondCollection->count());
		$this->assertCount(0, $secondCollection->all());
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testKeys()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz"=>"acme"]);
		$this->assertEquals([0, 1, "baz"], $collection->keys());
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testListing()
	{
		$array2d = [
			['name'=>'a', 'age'=>4],
			['name'=>'b', 'age'=>6],
			['name'=>'c', 'age'=>2],
		];
		$collection = new Nirlah\Collection($array2d);
		$this->assertEquals(["a","b","c"], $collection->lists('name'));
		$this->assertEquals([2=>"c",4=>"a",6=>"b"], $collection->lists('name', 'age'));
	}

	/**
	 * @depends testInstantiatable
	 */
	public function testImplode()
	{
		// 1D: - No, not the "band"...
		$firstCollection = new Nirlah\Collection(["foo","bar","baz"]);
		$this->assertEquals("foo, bar, baz", $firstCollection->implode(', '));

		// 2D:
		$array2d = [
			['name'=>'foo', 'age'=>4],
			['name'=>'bar', 'age'=>2],
			['name'=>'baz', 'age'=>6],
		];
		$secondCollection = new Nirlah\Collection($array2d);
		$this->assertEquals("foo, bar, baz", $secondCollection->implodeBy('name', ', '));
		$this->assertEquals("bar, foo, baz", $secondCollection->implodeBy('name', ', ', 'age'));
	}

	/**
	 * @depends testInstantiatable
	 * @depends testImplode
	 */
	public function testOrdering()
	{
		// Reverse:
		$collection = new Nirlah\Collection(["foo","bar","baz"]);
		$this->assertEquals("baz,bar,foo", $collection->inverse()->implode(','));
		$this->assertEquals("baz,bar,foo", $collection->implode(','));

		// Shuffle:
		$one = $collection->shuffle()->implode(',');
		$two = $collection->shuffle()->implode(',');
		$three = $collection->shuffle()->implode(',');
		$four = $collection->shuffle()->implode(',');
		$five = $collection->shuffle()->implode(',');
		$this->assertFalse( $one == $two && $two == $three && $three == $four && $four == $five);
	}

	/**
	 * @depends testInstantiatable
	 * @depends testImplode
	 */
	public function testWalk()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz"]);
		$func = function(&$value){
			$value .= "Walk";
		};
		$this->assertEquals("fooWalk,barWalk,bazWalk", $collection->walk($func)->implode(','));
	}

	/**
	 * @depends testInstantiatable
	 * @depends testImplode
	 */
	public function testMap()
	{
		$collection = new Nirlah\Collection(["foo","bar","baz"]);
		$func = function($value){
			return $value . "Map";
		};
		$this->assertEquals("fooMap,barMap,bazMap", $collection->map($func)->implode(','));
	}

	/**
	 * @depends testInstantiatable
	 * @depends testImplode
	 */
	public function testFilter()
	{
		$collection = new Nirlah\Collection(["yes","true","good","no","false","bad"]);
		$func = function($value){
			return in_array($value, ["yes","true","good"]);
		};
		$this->assertEquals(["yes","true","good"], $collection->filter($func)->all());
	}

}
