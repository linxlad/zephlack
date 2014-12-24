namespace Nirlah;

class Collection implements \ArrayAccess, \Countable, \IteratorAggregate {
	
	protected items = [];

	public function __construct(const items = null)
	{
		if items != null {
			this->merge(items);
		}
	}

	public function all() -> array
	{
		return this->items;
	}

	public function keys() -> array
	{
		return array_keys(this->items);
	}

	public function get(const key) -> var
	{
		return this->items[key];
	}
	
	public function set(const key, const value) -> <Collection>
	{
		let this->items[key] = value;
		return this;
	}

	public function forget(const key) -> <Collection>
	{
		unset(this->items[key]);
		return this;
	}

	public function has(const key) -> boolean
	{
		return isset(this->items[key]);
	}

	public function contains(const value) -> boolean
	{
		return in_array(value, this->items);
	}

	public function isEmpty() -> boolean
	{
		return empty(this->items);
	}

	public function add(const value) -> <Collection>
	{
		let this->items[] = value;
		return this;
	}

	public function insert(const value) -> <Collection>
	{
		array_unshift(this->items, value);
		return this;
	}

	public function merge(const collection) -> <Collection>
	{
		if is_object(collection) && (collection instanceof Collection) {
			let this->items = array_merge(this->items, collection->all());
		} elseif is_array(collection) {
			let this->items = array_merge(this->items, collection);
		} else {
			throw new \Exception("Collection can merge only array or another Collection.");
		}
		return this;
	}

	public function first() -> var
	{
		// WARNING changes pointer location.
		return reset(this->items);
	}

	public function last() -> var
	{
		// WARNING changes pointer location.
		return end(this->items);
	}

	public function pullFirst() -> var
	{
		// WARNING changes pointer location.
		return array_shift(this->items);
	}

	public function pullLast() -> var
	{
		// WARNING changes pointer location.
		return array_pop(this->items);
	}

	public function pull(const key) -> var
	{
		var value;
		let value = [this->items[key]];
		unset(this->items[key]);
		return value[0];
	}

	public function random(const int amount = 1) -> var
	{
		var keys;
		let keys = array_rand(this->items, amount);
		if amount == 1 {
			return this->items[keys];
		}

		// Else:
		var values = [], key;
		for key in keys {
			let values[key] = this->items[key];
		}
		return values;
	}

	// public function pullRandom(const int amount = 1) -> var
	// {
	// 	var keys, values, key;
	// 	let keys = array_rand(this->items, amount);
	// 	if amount == 1 {
	// 		return this->pull(keys);
	// 	}

	// 	// Else:
	// 	let values = [];
	// 	for key in keys {
	// 		let values[key] = this->items[key];
	// 		unset(this->items[key]);
	// 	}
	// 	return values;
	// }

	public function lists(const key, const index = null) -> array
	{
		var items;
		let items = array_column(this->items, key, index);
		if index != null {
			ksort(items);
		}
		return items;
	}

	public function count() -> int
	{
		return count(this->items);
	}

	public function inverse() -> <Collection>
	{
		let this->items = array_reverse(this->items);
		return this;
	}

	public function shuffle() -> <Collection>
	{
		shuffle(this->items);
		return this;
	}

	public function implode(const string glue) -> string
	{
		// TODO add sort.
		return implode(glue, this->items);
	}

	public function implodeBy(const key, const string glue, const index = null) -> string
	{
		return implode(glue, this->lists(key, index));
	}

	public function map(const func) -> <Collection>
	{
		var mapped;
		let mapped = array_map(func, this->items);
		return new self(mapped);
	}

	public function walk(const func, const userData = null) -> <Collection>
	{
		array_walk(this->items, func, userData);
		return this;
	}

	public function filter(const func) -> <Collection>
	{
		var filtered;
		let filtered = array_filter(this->items, func);
		return new self(filtered);
	}

	public function getIterator() -> <\ArrayIterator>
	{
		return new \ArrayIterator(this->items);
	}

	public function offsetGet(const key) -> var
	{
		return this->get(key);
	}

	public function offsetSet(const key, const value) -> void
	{
		this->set(key, value);
	}

	public function offsetExists(const key) -> boolean
	{
		return this->has(key);
	}

	public function offsetUnset(const key) -> void
	{
		this->forget(key);
	}

	public function __get(const key) -> var
	{
		return this->get(key);
	}

	public function __set(const key, const value) -> void
	{
		this->set(key, value);
	}

	public function __isset(const key) -> boolean
	{
		return this->has(key);
	}

	public function __unset(const key) -> void
	{
		this->forget(key);
	}

}
