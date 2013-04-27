#ifndef GAMEDATAFIELD_H
#define GAMEDATAFIELD_H
#include <QString>
#include <QStringList>
#include <QVariant>
#include "Reader/datareader.h"
#define null -1431655766;

class GameDataField
{
public:
    GameDataField();
    GameDataField(QString name);
    QString name();
    QString findReadMethod(int type, DataReader *reader);
    void getType(DataReader *reader);
    QString getReadMethod();
    QString getValue();
    void setValue(QVariant val);
    QStringList getInnerReadMethod();

private :
    QString _name;
    int _type;
    QVariant value;
    QString _readMethod;
    QStringList _innerTypeName;
    QStringList _innerReadMethod;
};

#endif // GAMEDATAFIELD_H
