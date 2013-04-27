#ifndef ALIGNMENTRANK_H
#define ALIGNMENTRANK_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentRank
{
public:
    AlignmentRank();
    AlignmentRank(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getModule()const;
    QString getName();
    QString getDescription();
    QString getId()const;
    QString getOrderId()const;
    QString getNameId()const;
    QString getDescriptionId()const;
    QString getMinimumAlignment()const;
    QString getObjectsStolen()const;

private:
    I18nFileAccessor *I18n;
    QString Id;
    QString orderId;
    QString nameId;
    QString descriptionId;
    QString minimumAlignment;
    QString objectsStolen;
};

#endif // ALIGNMENTRANK_H


/* A mettre plus tard
  public var gifts:Vector.<int>;

*/
