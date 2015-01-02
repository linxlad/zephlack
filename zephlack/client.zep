namespace Zephlack;


class Client extends Http\Request
{

    protected url = "";
    protected token = "";

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

    public function encode(value)
    {
        return json_encode(value);
    }

    public function notify()
    {
    }
}