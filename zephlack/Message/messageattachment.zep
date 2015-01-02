namespace Zephlack\Message;

class MessageAttachment
{
    protected fallback {
        set, get
    };

    protected text {
        set, get
    };

    protected pretext {
        set, get
    };

    protected color {
        set, get
    };

    protected fields {
        set, get
    };

    public function addField(<MessageField> field) -> array
    {
        let this->fields[] = field;
        return this;
    }

}