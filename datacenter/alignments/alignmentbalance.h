#ifndef ALIGNMENTBALANCE_H
#define ALIGNMENTBALANCE_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
class AlignmentBalance
{
public:
    AlignmentBalance();
    AlignmentBalance(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getModule()const;
    QString getId()const;
    QString getStartValue()const;
    QString getEndValue()const;
    QString getNameId()const;
    QString getDescriptionId()const;

    QString getName();
    QString getDescription();

private:
    I18nFileAccessor *I18n;
    QString _id;
    QString startValue;
    QString endValue;
    QString nameId;
    QString descriptionId;
};

#endif // ALIGNMENTBALANCE_H
