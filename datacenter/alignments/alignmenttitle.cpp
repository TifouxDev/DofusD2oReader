#include "alignmenttitle.h"

AlignmentTitle::AlignmentTitle()
{
}


AlignmentTitle::AlignmentTitle(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    sideId = def.getFieldValue("sideId");
}

QString AlignmentTitle::getSideId()const{
    return sideId;
}
QString AlignmentTitle::getModule()const{
    return "AlignmentTitles";
}
