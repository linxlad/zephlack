namespace Zephlack\Message;

class Message
{
    public text {
        set, get
    };

    public channel {
        set, get
    };

    public username {
        set, get
    };

    public iconEmoji {
        set, get
    };

    public iconUrl {
        set, get
    };

    public linkNames = false;

    public attachments = [] {
        set, get
    };

    /**
     * __construct
     *
     * @param string $text message text
     */
    public function __construct(text = "")
    {
        let this->text = text;
    }

    public function enableLinkNames(linkNames) -> bool
    {
        let this->linkNames = linkNames;
        return this;
    }

    public function addAttachment(<MessageAttachment> attachment) -> array
    {
        let this->attachments[] = attachment;
        return this;
    }
}