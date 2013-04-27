#ifndef I18NFILEACCESSOR_H
#define I18NFILEACCESSOR_H
/*
Auteur : Anthony
Date de création : 14/02/2013

Rôle :
Lecture D2i
*/
#include <QString>
#include <QFile>
#include <QMap>
#include "../Reader/datareader.h"
class I18nFileAccessor
{
public:
    I18nFileAccessor();
    I18nFileAccessor(QString path);
    QString GetText(int value);
private:
    QString _path;
    DataReader *streamReader;
    QMap<int,int> *_indexes;
    QMap<QString,int> *_textIndexes;
    QString getNamedText(QString value);
};

#endif // I18NFILEACCESSOR_H
