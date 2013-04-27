#ifndef ALIGNMENTEFFECT_H
#define ALIGNMENTEFFECT_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentEffect
{
public:
    AlignmentEffect();
    AlignmentEffect(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getModule()const;
    QString getId()const;
    QString getCharacteristicId()const;
    QString getDescriptionId()const;
    QString getDescription()const;
private:
    QString _id;
    QString characteristicId;
    QString descriptionId;
    I18nFileAccessor *I18n;
};

#endif // ALIGNMENTEFFECT_H
