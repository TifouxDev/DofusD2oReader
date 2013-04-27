#include "gamedataclassdefinition.h"

GameDataClassDefinition::GameDataClassDefinition()
{
}

GameDataClassDefinition::GameDataClassDefinition(QString class1,QString class2)
{
    _class = class1+"."+class2;
}

QString GameDataClassDefinition::getName()
{
    return (_class);
}

void GameDataClassDefinition::addField(GameDataField field)
{
    _fields.append(field);
}

GameDataField GameDataClassDefinition::getField(QString name)
{
    for(int i = 0;i < _fields.size();i++)
    {
        if(GameDataField(_fields.at(i)).name().toLower() == name.toLower())
        {
            return _fields.at(i);
        }
    }
    GameDataField unknow("Unknow");
    unknow.setValue("Field inexistant");
    return unknow;
}

QString GameDataClassDefinition::getFieldValue(QString name){
    return getField(name).getValue();
}

bool GameDataClassDefinition::isNull()
{
    return _class.isNull();
}

QVector <GameDataField> GameDataClassDefinition::getFieldVector()
{
    return _fields;
}

void GameDataClassDefinition::setDeveloppedFieldVector(QVector <GameDataField> developped)
{
    _fields = developped;
}
