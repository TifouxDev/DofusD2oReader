#include "i18nfileaccessor.h"

I18nFileAccessor::I18nFileAccessor()
{

}


I18nFileAccessor::I18nFileAccessor(QString path)
{
    _path = path;
    _indexes = new QMap<int,int>;
    _textIndexes = new QMap<QString,int>;
    QFile I18nFile(_path);
    I18nFile.open(QIODevice::ReadOnly);
    streamReader = new DataReader(I18nFile.readAll());
    int position = streamReader->readInt();
    streamReader->setPos(position);
    int _loc_4 = streamReader->readInt();
//    int _loc_7 = 0;
//    while(_loc_7 < _loc_4){
//        int _loc_5 = streamReader->readInt();
//        int _loc_6 = streamReader->readInt();
//        _indexes->insert(_loc_5, _loc_6);
//        _loc_7 = _loc_7 + 8;
//    }
    for (int i = 0;i < _loc_4;i += 8)
    {
        int _loc_5 = streamReader->readInt();
        int _loc_6 = streamReader->readInt();
        _indexes->insert(_loc_5, _loc_6);
    }

    while(streamReader->ByteAvalable()){
        QString _loc_8 =  streamReader->readString();
        int _loc_6 = streamReader->readInt();
        _textIndexes->insert(_loc_8, _loc_6);
    }
}

QString I18nFileAccessor::GetText(int value)
{
    if (_indexes->contains(value))
    {
        int _loc_2 = _indexes->value(value); // on charge la position ou le text et placer
        streamReader->setPos(_loc_2);
        return streamReader->readString();
    }else{
        return "Impossible de trouver le text.";
    }
}

QString I18nFileAccessor::getNamedText(QString value)
{
    if (_textIndexes->contains(value)){
        int _loc_2 = _textIndexes->value(value);
        streamReader->setPos(_loc_2);
        return streamReader->readString();
    }else{
        return "Impossible de trouver le text à partir du mot.";
    }
}
