namespace Zephlack;

use Zephlack\Http\Response;

class Client extends Http\Request
{

    protected url = "";

    protected token = "";

    protected debug = false {
        set, get
    };

    public function __construct(team = null, token = null)
    {
        if empty team {
            throw new clientException("Team name is required.");
        }

        if empty token {
            throw new clientException("API token name is required.");
        }

        let this->url = "https://" . team . ".slack.com";
        let this->token = token;
        parent::__construct(this->url);
        this->setParams(["token" : token]);
    }

    public function getUrl()
    {
        return this->url;
    }

    public function getToken()
    {
        return this->token;
    }

    private function encode(value) -> string
    {
        return json_encode(value);
    }

    private function isOK(response) -> bool
    {
        var code, message;
        let code = response->__get("statusCode");

        let message = response->__get("statusMessage");

        if code == 200 && message == "OK" {
            return true;
        }

        return false;
    }

    public function notify(<Message\Message> message)
    {
        var payload, response, messageArray, data = [], key, value, valid;

        let messageArray = json_decode(json_encode(message), true);

        for key, value in messageArray  {
            let data[strtolower(preg_replace("/([a-z])([A-Z])/", "$1_$2", key))] = value;
        }

        let payload = this->encode(data);

        this->setUri(this->getUrl(). "/services/hooks/incoming-webhook");
        this->setParams(["payload": payload]);

        let response = this->post();

        let valid = this->isOK(response);

        return valid;
    }
}