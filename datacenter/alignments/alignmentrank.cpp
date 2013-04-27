#include "alignmentrank.h"

AlignmentRank::AlignmentRank()
{
}


AlignmentRank::AlignmentRank(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    Id =  def.getFieldValue("id");
    nameId = def.getFieldValue("nameId");
    orderId = def.getFieldValue("orderId");
    descriptionId = def.getFieldValue("descriptionId");
    minimumAlignment =  def.getFieldValue("minimumAlignment");
    objectsStolen = def.getFieldValue("objectsStolen");
}

QString AlignmentRank::getModule()const{
    return "AlignmentRank";
}


QString AlignmentRank::getId()const{
    return Id;
}

QString AlignmentRank::getOrderId()const{
    return orderId;
}

QString AlignmentRank::getDescriptionId()const{
    return descriptionId;
}

QString AlignmentRank::getMinimumAlignment()const{
    return minimumAlignment;
}

QString AlignmentRank::getObjectsStolen()const{
    return objectsStolen;
}

QString AlignmentRank::getNameId()const{
    return nameId;
}
QString AlignmentRank::getName(){
    return I18n->GetText(nameId.toInt());
}

QString AlignmentRank::getDescription(){
    return I18n->GetText(descriptionId.toInt());
}
