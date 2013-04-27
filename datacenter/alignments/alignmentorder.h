#ifndef ALIGNMENTORDER_H
#define ALIGNMENTORDER_H

#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentOrder
{
public:
    AlignmentOrder();
    AlignmentOrder(GameDataClassDefinition def, I18nFileAccessor *_I18n);

    QString getModule()const;
    QString getName();

    QString getId()const;
    QString getNameId()const;
    QString getSideId()const;

private:
    I18nFileAccessor *I18n;
    QString _id;
    QString nameId;
    QString sideId;
};
#endif // ALIGNMENTORDER_H
