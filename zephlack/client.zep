namespace Zephlack;

use Zephlack\Http\Request;

class Client
{
    protected request;

    public static function say()
    {
        let this->request = new Request();
    }

}