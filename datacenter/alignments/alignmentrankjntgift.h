#ifndef ALIGNMENTRANKJNTGIFT_H
#define ALIGNMENTRANKJNTGIFT_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentRankJntGift
{
public:
    AlignmentRankJntGift();
    AlignmentRankJntGift(GameDataClassDefinition def, I18nFileAccessor *_I18n);

    QString getModule()const;
    QString getId()const;
private:
    I18nFileAccessor *I18n;
    QString Id;

};

#endif // ALIGNMENTRANKJNTGIFT_H


/* A mettre plus tard

   public var gifts:Vector.<int>;
   public var parameters:Vector.<int>;
   public var levels:Vector.<int>;
*/
