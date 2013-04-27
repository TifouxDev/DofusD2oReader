#ifndef ALIGNMENTGIFT_H
#define ALIGNMENTGIFT_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentGift
{
public:
    AlignmentGift();
    AlignmentGift(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getModule()const;
    QString getId()const;
    QString getNameId()const;
    QString getEffectId()const;
    QString getGfxId()const;
    QString getName();
private:
    I18nFileAccessor *I18n;
    QString _id;
    QString nameId;
    QString effectId;
    QString gfxId;
};

#endif // ALIGNMENTGIFT_H
