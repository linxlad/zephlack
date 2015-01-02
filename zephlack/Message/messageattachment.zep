namespace Zephlack\Message;

class MessageAttachment
{
    public fallback {
        set, get
    };

    public text {
        set, get
    };

    public pretext {
        set, get
    };

    public color {
        set, get
    };

    public fields {
        set, get
    };

    public function addField(<MessageField> field) -> array
    {
        let this->fields[] = field;
        return this;
    }

}