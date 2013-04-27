#include "abusereasons.h"

AbuseReasons::AbuseReasons()
{
}

AbuseReasons::AbuseReasons(GameDataClassDefinition def, I18nFileAccessor *_I18n)
{
    I18n  = _I18n;
    _abuseReasonId = def.getFieldValue("_abuseReasonId");
    _mask = def.getFieldValue("_mask");
    _reasonTextId = def.getFieldValue("_reasonTextId");
}

QString AbuseReasons::getAbuseReasonId()const{
    return _abuseReasonId;
}

QString AbuseReasons::getMask()const{
    return _mask;
}

QString AbuseReasons::getReasonTextId()const{
    return _reasonTextId;
}

QString AbuseReasons::getModule()const{
    return "AbuseReasons";
}

QString AbuseReasons::Name(){
    QString message = I18n->GetText(_reasonTextId.toInt());
    return message;
}
