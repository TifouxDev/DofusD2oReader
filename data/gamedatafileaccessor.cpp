#include "gamedatafileaccessor.h"
GameDataFileAccessor::GameDataFileAccessor(QObject *parent) :
    QObject(parent)
{
    I18nIni = false;
}

GameDataFileAccessor::~GameDataFileAccessor(){
    delete reader;
    delete I18n;
}

bool GameDataFileAccessor::loadFile(QString path)
{
    QFile d2o(path);
    d2o.open(QIODevice::ReadOnly);
    reader = new DataReader(d2o.readAll());
    _header = reader->readBytes(3);
    _indexes.clear();
    if(_header == "D2O")
    {
        _begin = reader->readInt();
        reader->setPos(_begin);
        _lenght = reader->readInt();
        for(int i = 0;i < _lenght;i += 8)
        {
            _key = reader->readInt();
            _pointer = reader->readInt();
            _indexes.insert(_key,_pointer);
        }
        _lenght = reader->readInt();
        for(int i = 0;i < _lenght;i++)
        {
            _classId = reader->readInt();
            readClassDefinition(_classId);
        }
    }
    else
    {
        return (false);
    }
    d2o.close();
    return (true);
}

void GameDataFileAccessor::readClassDefinition(int classId)
{
    QString class1 = reader->readString();
    QString class2 = reader->readString();
    GameDataClassDefinition def(class1, class2);
    int fieldLen = reader->readInt();
    definitionsByClassId.clear();
    for(int i = 0;i < fieldLen;i++)
    {
        QString name = reader->readString();
        GameDataField field(name);
        field.getType(reader);
        def.addField(field);
    }
    definitionsByClassId.insert(classId, def);
    QVector <int> vec = definitionsByClassId.keys().toVector();
    for(int i = 0;i < vec.size();i++)
    {
        GameDataClassDefinition currDef = definitionsByClassId[vec.at(i)];
        QVector <GameDataField> fields = def.getFieldVector();
        for(int i = 0;i < fields.size();i++)
        {
            GameDataField currField = fields.at(i);
        }
    }
}

GameDataClassDefinition GameDataFileAccessor::read(int key)
{
    if(!_indexes.contains(key))
    {
        return(GameDataClassDefinition());
    }
    reader->setPos(_indexes[key]);
    int classId = reader->readInt();
    GameDataClassDefinition def = definitionsByClassId[classId];
    return read(def);

}

GameDataClassDefinition GameDataFileAccessor::getField(GameDataClassDefinition def)
{
    QVector <GameDataField> fields = def.getFieldVector();
    QVector <GameDataField> newFields;
    if(!def.isNull())
    {
        for(int i = 0;i < fields.size();i++)
        {
            GameDataField currField = fields.at(i);
            QString method = currField.getReadMethod();
            QByteArray name = currField.name().toAscii();
            if(method == "readInteger")
            {
                currField.setValue(QVariant(reader->readInt()));
            }
            else if(method == "readBoolean")
            {
                currField.setValue(QVariant(reader->readByte()));
            }
            else if(method == "readString")
            {
                currField.setValue(QVariant(reader->readString()));
            }
            else if(method == "readNumber")
            {
                currField.setValue(QVariant(reader->readDouble()));
            }
            else if(method == "readI18n")
            {
                currField.setValue(QVariant(reader->readInt()));
            }
            else if(method == "readUnsignedInteger")
            {
                currField.setValue(QVariant(uint(reader->readInt())));
            }
            else if(method == "readObject")
            {
                int id = reader->readInt();
                GameDataClassDefinition def2 = definitionsByClassId[id];
                def = read(def2);
                currField.setValue(QVariant("Definition Class Id : "+QVariant(id).toString()));
            }
            else if(method == "readVector" || method == "readDoubleVector")
            {
                bool isDouble = false;
                if(method == "readDoubleVector")
                {
                    isDouble = true;
                }
                QString vectorValues = "Vector :\n";
                vectorValues.append("=======\n");
                int vectorSize;
                if(isDouble)
                {
                    vectorSize = reader->readInt();
                }
                else
                {
                    vectorSize = reader->readInt();
                }
                for(int i = 0;i < vectorSize;i++)
                {
                    vectorValues.append("Value"+QString::number(i)+" : ");
                    if(isDouble)
                    {
                        int subVectorSize = reader->readInt();
                        vectorValues.append(QVariant("SubVector :\n").toString());
                        for(int a = 0;a < subVectorSize;a++)
                        {
                            method = currField.getInnerReadMethod().at(0+1);
                            if(method == "readInteger")
                            {
                                vectorValues.append(QVariant(reader->readInt()).toString());
                            }
                            else if(method == "readBoolean")
                            {
                                vectorValues.append(QVariant(reader->readByte()).toString());
                            }
                            else if(method == "readString")
                            {
                                vectorValues.append(QVariant(reader->readString()).toString());
                            }
                            else if(method == "readNumber")
                            {
                                currField.setValue(QVariant(reader->readDouble()).toString());
                            }
                            else if(method == "readI18n")
                            {
                                vectorValues.append(QVariant(reader->readInt()).toString());
                            }
                            else if(method == "readUnsignedInteger")
                            {
                                vectorValues.append(QVariant(uint(reader->readInt())).toString());
                            }
                            vectorValues.append("\n");

                        }
                    }
                    else
                    {

                        method = currField.getInnerReadMethod().at(0);
                        if(method == "readInteger")
                        {
                            vectorValues.append(QVariant(reader->readInt()).toString());
                        }
                        else if(method == "readBoolean")
                        {
                            vectorValues.append(QVariant(reader->readByte()).toString());
                        }
                        else if(method == "readString")
                        {
                            vectorValues.append(QVariant(reader->readString()).toString());
                        }
                        else if(method == "readNumber")
                        {
                            currField.setValue(QVariant(reader->readDouble()).toString());
                        }
                        else if(method == "readI18n")
                        {
                            vectorValues.append(QVariant(reader->readInt()).toString());
                        }
                        else if(method == "readUnsignedInteger")
                        {
                            vectorValues.append(QVariant(uint(reader->readInt())).toString());
                        }
                        vectorValues.append("\n");
                    }
                }
                vectorValues.append("=======");
                currField.setValue(QVariant(vectorValues));
            }
            newFields.append(currField);
        }
        def.setDeveloppedFieldVector(newFields);
    }
    return def;
}
GameDataClassDefinition GameDataFileAccessor::read(GameDataClassDefinition def)
{
    GameDataClassDefinition tests = getField(def);
    return tests;
}

