namespace Nirlah\Http;

class Header implements \Countable {

	const THROW_EXCEPTIONS = true;

	public version = "";
	public statusCode = 0;
	public statusMessage = "";
	public status = "";
	protected fields = [];

	public function __construct(const content = null)
	{
		if content != null {
			this->parse(content);
		}
	}

	public function parse(content) -> void
	{
		if empty(content) || in_array(typeof content, ["string","array"]) == false {
			throw new HttpException("parse() can only work with non-empty string or array.");
		}

		// Convert string to array
		if typeof content == "string" {
			let content = array_filter(explode("\r\n", content));
			// Use filter without callback to remove FALSE values.
		}

		var status = [];
		if preg_match("|HTTP/(\\d(?:\\.\\d)?)\\s+(\\d{3})\\s+(.+)|i", content[0], status) {
			let this->status = array_shift(content);
			let this->version = status[1];
			let this->statusCode = intval(status[2]);
			let this->statusMessage = status[3];

			// Trow exception on error:
			if self::THROW_EXCEPTIONS && this->statusCode >= 400 {
				throw new HttpException("HTTP ".this->statusCode.": ".this->statusMessage, this->statusCode);
			}
		}

		var field;
		for field in content {
			if typeof field != "array" {
				let field = array_map("trim", explode(":", field, 2));
			}

			if count(field) == 2 {
				this->setField(field[0], field[1]);
			}
		}
	}

	public function build(const int flags = 0) -> array
	{
		var lines = [], message;
		let message = self::getMessage(this->statusCode);
		if message != false {
			let lines[] = "HTTP/".this->version." ".this->statusCode.
						  " ".message;
		}

		var field, value;
		for field, value in this->fields {
			let lines[] = field.": ".value;
		} 

		return lines;
	}

	//
	// Fields access
	//

	public function setField(const field, const value = null) -> void
	{
		if typeof field == "array" {
			this->setFields(field);
		} else {
			let this->fields[field] = value;
		}
	}

	public function setFields(const array fields) -> void
	{
		let this->fields = array_merge(this->fields, fields);
	}

	public function getField(const string field) -> var
	{
		if this->hasField(field) {
			return this->fields[field];
		} else {
			throw new HttpException("The field \"".field."\" is not defined.");
		}
	}

	public function getFields() -> array
	{
		return this->fields;
	}

	public function hasField(const string field) -> boolean
	{
		return isset(this->fields[field]);
	}

	public function unsetField(const string field) -> void
	{
		if this->hasField(field) {
			unset(this->fields[field]);
		}
	}

	public function clearFields() -> void
	{
		let this->fields = [];
	}

	public function count() -> int
	{
		return count(this->fields);
	}

	public function __set(const string field, const value) -> void
	{
		this->setField(field, value);
	}

	public function __get(const string field) -> var
	{
		return this->getField(field);
	}

	public function __isset(const string field) -> boolean
	{
		return this->hasField(field);
	}

	public function __unset(const string field) -> void
	{
		this->unsetField(field);
	}

	protected static function getMessage(const int code) -> string|boolean
	{
		var messages = [
			// Informational 1xx
			100: "Continue",
			101: "Switching Protocols",

			// Success 2xx
			200: "OK",
			201: "Created",
			202: "Accepted",
			203: "Non-Authoritative Information",
			204: "No Content",
			205: "Reset Content",
			206: "Partial Content",

			// Redirection 3xx
			300: "Multiple Choices",
			301: "Moved Permanently",
			302: "Found",
			303: "See Other",
			304: "Not Modified",
			305: "Use Proxy",
			307: "Temporary Redirect",

			// Client Error 4xx
			400: "Bad Request",
			401: "Unauthorized",
			402: "Payment Required",
			403: "Forbidden",
			404: "Not Found",
			405: "Method Not Allowed",
			406: "Not Acceptable",
			407: "Proxy Authentication Required",
			408: "Request Timeout",
			409: "Conflict",
			410: "Gone",
			411: "Length Required",
			412: "Precondition Failed",
			413: "Request Entity Too Large",
			414: "Request-URI Too Long",
			415: "Unsupported Media Type",
			416: "Requested Range Not Satisfiable",
			417: "Expectation Failed",

			// Server Error 5xx
			500: "Internal Server Error",
			501: "Not Implemented",
			502: "Bad Gateway",
			503: "Service Unavailable",
			504: "Gateway Timeout",
			505: "HTTP Version Not Supported",
			509: "Bandwidth Limit Exceede"
		];

		if isset(messages[code]) {
			return messages[code];
		} else {
			return false;
		}
	}
	
}
