#include "alignmentgift.h"

AlignmentGift::AlignmentGift()
{
}


AlignmentGift::AlignmentGift(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    _id = def.getFieldValue("id");
    nameId = def.getFieldValue("nameId");
    effectId =  def.getFieldValue("effectId");
    gfxId = def.getFieldValue("gfxId");
}


QString AlignmentGift::getId()const{
    return _id;
}

QString AlignmentGift::getNameId()const{
    return nameId;
}

QString AlignmentGift::getEffectId()const{
    return effectId;
}

QString AlignmentGift::getGfxId()const{
    return gfxId;
}

QString AlignmentGift::getName(){
    return I18n->GetText(nameId.toInt());
}
