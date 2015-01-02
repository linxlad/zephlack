namespace Zephlack\Message;

class Message implements MessageInterface
{
    protected text {
        set, get
    };

    protected channel {
        set, get
    };

    protected username {
        set, get
    };

    protected iconEmoji {
        set, get
    };

    protected iconUrl {
        set, get
    };

    protected linkNames = false;

    protected attachments = [] {
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