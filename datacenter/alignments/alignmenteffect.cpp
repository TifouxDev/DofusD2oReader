#include "alignmenteffect.h"

AlignmentEffect::AlignmentEffect()
{
}

AlignmentEffect::AlignmentEffect(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    _id = def.getFieldValue("id");
    characteristicId = def.getFieldValue("characteristicId");
    descriptionId = def.getFieldValue("descriptionId");
}

QString AlignmentEffect::getModule()const{
    return "AlignmentEffect";
}

QString AlignmentEffect::getId()const{
    return _id;
}

QString AlignmentEffect::getCharacteristicId()const{
    return characteristicId;
}

QString AlignmentEffect::getDescriptionId()const{
    return descriptionId;
}

QString AlignmentEffect::getDescription()const{
    return I18n->GetText(descriptionId.toInt());
}
