#ifndef ABUSEREASONS_H
#define ABUSEREASONS_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AbuseReasons
{
public:
    AbuseReasons();
    AbuseReasons(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getAbuseReasonId()const;
    QString getMask()const;
    QString getReasonTextId()const;
    QString getModule()const;
    QString Name();

private:
    QString _abuseReasonId;
    QString _mask;
    QString _reasonTextId;
    I18nFileAccessor *I18n;
};

#endif // ABUSEREASONS_H
