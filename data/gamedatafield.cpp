#include "gamedatafield.h"

GameDataField::GameDataField()
{
}

GameDataField::GameDataField(QString name)
{
    _name = name;
}

QString GameDataField::name()
{
    return (_name);
}

void GameDataField::getType(DataReader *reader)
{
    _type = reader->readInt();
    _readMethod = findReadMethod(_type,reader);
}

QString GameDataField::findReadMethod(int type,DataReader *reader)
{
    switch(type)
    {
    case -1 :
    {
        return "readInteger";
    }break;
    case -2 :
    {
        return "readBoolean";
    }break;
    case -3 :
    {
        return "readString";
    }break;
    case -4 :
    {
        return "readNumber";
    }break;
    case -5 :
    {
        return "readI18n";
    }break;
    case -6 :
    {
        return "readUnsignedInteger";
    }break;
    case -99 :
    {
        QString name = reader->readString();
        QVariant vectorCount = name.count("Vector");
        bool isDouble = false;
        if(vectorCount.toInt() == 2)
        {
            isDouble = true;
        }
        QString toInv = name.remove(".").remove("<").remove(">").remove("Vector");
        if(toInv == "uint")
        {
            _innerTypeName.append("readUnsignedInteger");
        }
        else if(toInv == "int")
        {
            _innerTypeName.append("readInteger");
        }
        else if(toInv == "String")
        {
            _innerTypeName.append("readString");
        }
        _innerReadMethod.insert(0,findReadMethod(reader->readInt(),reader));
        if(isDouble)
        {
            return "readDoubleVector";
        }
        return "readVector";
    }break;
    default :
    {
        if(_type > 0)
        {
            return "readObject";
        }
    }break;
    };
    return _readMethod;
}
QString GameDataField::getReadMethod()
{
    return(_readMethod);
}

QString GameDataField::getValue()
{
    return(value.toString());
}

void GameDataField::setValue(QVariant val)
{
    value = val;
}

QStringList GameDataField::getInnerReadMethod()
{
    return (_innerReadMethod);
}
