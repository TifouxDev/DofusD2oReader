#include "alignmentbalance.h"

AlignmentBalance::AlignmentBalance()
{
}

AlignmentBalance::AlignmentBalance(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    _id = def.getFieldValue("id");
    startValue = def.getFieldValue("startValue");
    endValue = def.getFieldValue("endValue");
    descriptionId = def.getFieldValue("descriptionId");
    nameId = def.getFieldValue("nameId");
}

QString AlignmentBalance::getModule() const{
    return "AlignmentBalance";
}

QString AlignmentBalance::getId()const{
    return _id;
}

QString AlignmentBalance::getStartValue()const{
    return startValue;
}

QString AlignmentBalance::getEndValue()const{
    return endValue;
}

QString AlignmentBalance::getNameId()const{
    return nameId;
}

QString AlignmentBalance::getDescriptionId()const{
    return descriptionId;
}
QString AlignmentBalance::getName(){
    return I18n->GetText(nameId.toInt());
}

QString AlignmentBalance::getDescription(){
    return I18n->GetText(descriptionId.toInt());
}
