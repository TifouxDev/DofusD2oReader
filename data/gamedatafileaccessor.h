#ifndef GAMEDATAFILEACCESSOR_H
#define GAMEDATAFILEACCESSOR_H
/*
Auteur : Anthony
Date de création : 14/02/2013

Rôle :
lire les informations du Fichier.
*/

#include <QObject>
#include <QMap>
#include <QFile>
#include "gamedataclassdefinition.h"
#include "Reader/datareader.h"
#include "gamedatafield.h"
#include "gamedataclassdefinition.h"
#include "I18n/i18nfileaccessor.h"
class GameDataFileAccessor : public QObject
{
    Q_OBJECT

public:
    GameDataFileAccessor(QObject *parent = 0);
    ~GameDataFileAccessor();
    bool loadFile(QString path);
    template <class T> T readIndex(int key)
    {
        T myClass;
        if(!I18nIni){
        I18n = new I18nFileAccessor("F:/Other Dfus/i18n/i18n_fr.d2i"); // Fix Me
        I18nIni = true;
        }
        loadFile("F:/Other Dfus/common/" + myClass.getModule() + ".d2o");
        myClass = T(read(key), I18n);
        return myClass;
    }

private :
    GameDataClassDefinition read(int key);
    GameDataClassDefinition read(GameDataClassDefinition def);
    DataReader *reader;
    QString _header;
    int _begin;
    int _lenght;
    int _key;
    int _pointer;
    int _classId;
    QMap <int,int> _indexes;
    QMap <int,GameDataClassDefinition> definitionsByClassId;
    void readClassDefinition(int classId);
    GameDataClassDefinition getField(GameDataClassDefinition def);
    I18nFileAccessor *I18n;
    bool I18nIni;
};

#endif // GAMEDATAFILEACCESSOR_H
