namespace Nirlah\Http;

class Response {
	
	protected header;
	protected body;

	public function __construct(body, header = null)
	{
		// Body:
		if empty(body) {
			throw new HttpException("The response's body must be defined.");
		} elseif typeof body != "string" {
			throw new HttpException("The response's body must be a string.");
		} else {
			let this->body = body;
		}

		// Header:
		if header == null {
			let this->header = new Header;
		} else {
			this->parseHeader(header);
		}
	}

	protected function parseHeader(header)
	{
		if is_object(header) && (header instanceof Header) {
			let this->header = header;
		} elseif typeof header == "string" {
			let this->header = new Header(header);
		} else {
			throw new HttpException("The header may only be a Header class or string.");
		}
	}

	public function toObject() -> <\stdClass>
	{
		this->validateBody();
		return self::decodeJson(this->body);
	}

	public function toArray() -> array
	{
		this->validateBody();
		return self::decodeJson(this->body, true);
	}

	protected function validateBody() -> void
	{	
		if empty(this->body) {
			throw new HttpException("The response's body is not defined.");
		}
	}

	protected static function decodeJson(const string json, const boolean toArray = false) -> array|<\stdClass>
	{
		var parsed;
		let parsed = json_decode(json, toArray);

		if json_last_error() == JSON_ERROR_NONE {
			return parsed;
		} else {
			throw new HttpException(json_last_error_msg());
		}
	}

	public function __get(const string attribute)
	{
		if attribute == "body" {
			return this->body;
		} elseif attribute == "header" {
			return this->header;
		} else {
			return this->header->{attribute};
		}
	}

	public function __call(const string method, const array args)
	{
		if method_exists(this->header, method) == false {
			throw new HttpException("The header has no method \"".method."\".");
		}

		return this->header->{method}(args);
	}

}
