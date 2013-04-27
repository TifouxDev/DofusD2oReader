#include "alignmentorder.h"

AlignmentOrder::AlignmentOrder()
{
}

AlignmentOrder::AlignmentOrder(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    _id = def.getFieldValue("id");
    nameId = def.getFieldValue("nameId");
    sideId = def.getFieldValue("sideId");

}


QString AlignmentOrder::getModule()const{
    return "AlignmentOrder";
}

QString AlignmentOrder::getName(){
    return I18n->GetText(nameId.toInt());
}

QString AlignmentOrder::getId()const{
    return _id;
}

QString AlignmentOrder::getNameId()const{
    return nameId;
}

QString AlignmentOrder::getSideId()const{
    return sideId;
}
