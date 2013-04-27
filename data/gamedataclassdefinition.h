#ifndef GAMEDATACLASSDEFINITION_H
#define GAMEDATACLASSDEFINITION_H
#include <QString>
#include <QVector>
#include "gamedatafield.h"
class GameDataClassDefinition
{
public:
    GameDataClassDefinition();
    GameDataClassDefinition(QString class1,QString class2);
    QString getName();
    void addField(GameDataField field);
    bool isNull();
    QVector <GameDataField> getFieldVector();
    void setDeveloppedFieldVector(QVector <GameDataField> developped);
    QString getFieldValue(QString name);

private:
    QString _class;
    QVector <GameDataField> _fields;
    GameDataField getField(QString name);
};

#endif // GAMEDATACLASSDEFINITION_H
