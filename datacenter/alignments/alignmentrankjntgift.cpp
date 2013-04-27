#include "alignmentrankjntgift.h"

AlignmentRankJntGift::AlignmentRankJntGift()
{
}

AlignmentRankJntGift::AlignmentRankJntGift(GameDataClassDefinition def, I18nFileAccessor *_I18n){
    I18n = _I18n;
    Id =  def.getFieldValue("id");
}


QString AlignmentRankJntGift::getModule()const{
    return "AlignmentRankJntGift";
}
