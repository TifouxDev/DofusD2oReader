#ifndef ALIGNMENTTITLE_H
#define ALIGNMENTTITLE_H
#include "../../data/I18n/i18nfileaccessor.h"
#include "../../data/gamedataclassdefinition.h"
#include <QString>
#include "../../data/I18n/i18nfileaccessor.h"
class AlignmentTitle
{
public:
    AlignmentTitle();
    AlignmentTitle(GameDataClassDefinition def, I18nFileAccessor *_I18n);
    QString getModule()const;
    QString getSideId()const;
private:
    QString sideId;
    I18nFileAccessor *I18n;
};

#endif // ALIGNMENTTITLE_H


/* A mettre plus tard

#Var
public var namesId:Vector.<int>;
public var namesId:Vector.<int>;

#Function
public function getNameFromGrade(param1:int) : String
 {
  return I18n.getText(this.namesId[param1]);
 }// end function

 public function getShortNameFromGrade(param1:int) : String
 {
  return I18n.getText(this.shortsId[param1]);
 }// end function

*/
