namespace Nirlah\Http;

class Request {

	public uri;
	public header;
	protected curl;
	protected options = [];
	protected params = [];
	protected json = false;

	public function __construct(string uri = null)
	{
		// Check for CURL extension:
		if !extension_loaded("curl") {
			throw new HttpException("The \"curl\" extension is required.");
		}

		let this->curl = curl_init();
		let this->header = new Header();
		this->setUri(uri);
		this->setDefaultOptions();
	}

	public function __destruct()
	{
		curl_close(this->curl);
	}

	//
	// Uri
	//

	public function setUri(const baseUri) -> void
	{
		if is_object(baseUri) && (baseUri instanceof Uri) {
			let this->uri = baseUri;
		} else {
			let this->uri = new Uri(baseUri);
		}
	}

	public function getUri() -> string
	{
		return this->uri->build();
	}

	protected function resolveUri(const string resolvePath = null) -> string
	{
		if empty(resolvePath) {
			return this->uri->build();
		} else {
			return this->uri->resolvePath(resolvePath);
		}
	}

	protected function resolveUriWithQuery(const string resolvePath = null) -> string
	{
		var uri;
		if count(this->params) > 0 {
			if empty(resolvePath) {
				let uri = this->uri->resolveQuery(this->params, this->json);
			} else {
				let uri = this->uri->resolve(resolvePath, this->params, this->json);
			}
		} else {
			if empty(resolvePath) {
				let uri = this->uri->build();
			} else {
				let uri = this->uri->resolvePath(resolvePath);
			}
		}
		return uri;
	}

	//
	// Send
	//

	protected function send() -> <Response>
	{
		var header = [], content, headerSize, body;
		if count(this->header) > 0 {
			let header = this->header->build();
		}
		let header[] = "Expect:";
		this->setOption(CURLOPT_HTTPHEADER, header);

		// Register options & execute:
		curl_setopt_array(this->curl, this->options);

		let content = curl_exec(this->curl);

		if curl_errno(this->curl) != 0 {
			throw new HttpException(curl_error(this->curl), curl_errno(this->curl));
		}

		let headerSize = curl_getinfo(this->curl, CURLINFO_HEADER_SIZE);

		let body = substr(content, headerSize);
		let header = substr(content, 0, headerSize);
		return new Response(body, header);
	}

	public function get(const string resolvePath = null) -> <Response>
	{
		this->setOption(CURLOPT_URL, this->resolveUriWithQuery(resolvePath));
		this->setOption(CURLOPT_HTTPGET, true);
		this->setOption(CURLOPT_CUSTOMREQUEST, "GET");
		return this->send();
	}

	public function post(const string resolvePath = null, const boolean encodeParams = true) -> <Response>
	{
		if this->json {
			this->setOption(CURLOPT_POSTFIELDS, this->getJsonParams());
		} else {
			this->setOption(CURLOPT_POSTFIELDS, this->getPostParams(encodeParams));
		}
		this->setOption(CURLOPT_URL, this->resolveUri(resolvePath));
		this->setOption(CURLOPT_POST, true);
		this->setOption(CURLOPT_CUSTOMREQUEST, "POST");
		return this->send();
	}

	public function head(const string resolvePath = null) -> <Response>
	{
		this->setOption(CURLOPT_URL, this->resolveUriWithQuery(resolvePath));
		this->setOption(CURLOPT_HTTPGET, true);
		this->setOption(CURLOPT_CUSTOMREQUEST, "HEAD");
		return this->send();
	}

	public function put(const string resolvePath = null, const boolean encodeParams = true) -> <Response>
	{
		if this->json {
			this->setOption(CURLOPT_POSTFIELDS, this->getJsonParams());
		} else {
			this->setOption(CURLOPT_POSTFIELDS, this->getPostParams(encodeParams));
		}
		this->setOption(CURLOPT_URL, this->resolveUri(resolvePath));
		this->setOption(CURLOPT_POST, true);
		this->setOption(CURLOPT_CUSTOMREQUEST, "PUT");
		return this->send();
	}

	public function delete(const string resolvePath = null) -> <Response>
	{
		this->setOption(CURLOPT_URL, this->resolveUriWithQuery(resolvePath));
		this->setOption(CURLOPT_HTTPGET, true);
		this->setOption(CURLOPT_CUSTOMREQUEST, "DELETE");
		return this->send();
	}

	//
	// Options
	//

	protected function setDefaultOptions() -> void
	{
		this->setOption(CURLOPT_RETURNTRANSFER, true);
		this->setOption(CURLOPT_AUTOREFERER, true);
		this->setOption(CURLOPT_FOLLOWLOCATION, true);
		this->setOption(CURLOPT_HEADER, true);
		this->setOption(CURLOPT_CONNECTTIMEOUT, 30);
		this->setOption(CURLOPT_TIMEOUT, 30);
		this->setOption(CURLOPT_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
		this->setOption(CURLOPT_REDIR_PROTOCOLS, CURLPROTO_HTTP | CURLPROTO_HTTPS);
	}

	public function setOption(const int option, value = null) -> void
	{
		let this->options[option] = value;
	}

	public function getOption(const int option) -> var
	{
		if this->hasOption(option) {
			return this->options[option];
		} else {
			throw new HttpException("The option was not set before.");
		}
	}

	public function hasOption(const int option) -> boolean
	{
		return isset(this->options[option]);
	}

	//
	// Params
	//

	protected function getPostParams(boolean useEncoding) -> string
	{
		var params = [], param;
		let params = this->params;
		for param in params {
			if typeof param == "string" && preg_match("/^@/", param) {
				let useEncoding = false;
				break;
			}
		}

		if useEncoding {
			let params = http_build_query(params);
		}

		return params;
	}

	protected function getJsonParams() -> string
	{
		return json_encode(this->params);
	}

	public function setParams(const array params) -> void
	{
		let this->params = array_merge(this->params, params);
	}

	public function setParam(const param, const value = null) -> void
	{
		if typeof param == "array" {
			this->setParams(param);
		} else {
			let this->params[param] = value;
		}
	}

	public function getParam(const string param) -> var
	{
		if this->hasParam(param) {
			return this->params[param];
		} else {
			throw new HttpException("The parameter \"".param."\" is not defined.");
		}
	}

	public function getParams() -> array
	{
		return this->params;
	}

	public function hasParam(const string param) -> boolean
	{
		return isset(this->params[param]);
	}

	public function unsetParam(const string param) -> void
	{
		unset(this->params[param]);
	}

	public function clearParams() -> void
	{
		let this->params = [];
	}

	public function __set(const string param, const value) -> void
	{
		this->setParam(param, value);
	}

	public function __get(const string param) -> var
	{
		return this->getParam(param);
	}

	public function __isset(const string param) -> boolean
	{
		return this->hasParam(param);
	}

	public function __unset(const string param) -> void
	{
		this->unsetParam(param);
	}

	//
	// Headers
	//

	public function setHeader(const field, value = null) -> void
	{
		if typeof field == "array" {
			this->setHeaders(field);
		} else {
			this->header->setField(field, value);
		}
	}

	public function setHeaders(const array fields) -> void
	{
		this->header->setFields(fields);
	}

	public function getHeader(const string field) -> var
	{
		return this->header->getField(field);
	}

	public function hasHeader(const string field) -> boolean
	{
		return this->header->hasField(field);
	}

	public function unsetHeader(const string field) -> void
	{
		this->header->unsetField(field);
	}

	public function clearHeaders() -> void
	{
		this->header->clearFields();
	}

	public function useJson() -> void
	{
		this->setHeaders([
			"Content-Type": "application/json",
			"Accept": "application/json; charset=UTF-8"
		]);
		let this->json = true;
	}

}
