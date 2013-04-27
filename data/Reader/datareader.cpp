#include "datareader.h"

DataReader::DataReader()
{
    _pos = 0;
}

DataReader::DataReader(QByteArray bytes){
    _buffer = bytes;
    _pos = 0;
}


void DataReader::fromBytes(QByteArray bytes){
    _buffer = bytes;
}

void DataReader::setPos(int pos){
    _pos = pos;
}

int DataReader::getPos(){
    return _pos;
}

int DataReader::readInt(){
    if (_buffer.length() >= 4)
    {
        uint i = (readByte() << 24) + (readByte() << 16) + (readByte() << 8) + (readByte() << 0);
        return i;
    }
    return(0);
}

byte DataReader::readByte(){
    if (_buffer.length() >= 1 && _pos < _buffer.length())
    {
        uchar result;
        result = _buffer.at(_pos);
        _pos++;
        return result;
    }
    else
    {
        qDebug("Warn : Out of range");
    }
    return(0);
}

QByteArray DataReader::readBytes(int number){
    QByteArray result;
    for (int i = 0; i != number; i++)
    {
        result.append(readByte());
    }
    return result;
}

short DataReader::readShort(){
    if (_buffer.length() >= 2)
    {
        ushort one = readByte();
        ushort two = readByte();
        ushort s = (one << 8) + two;
        return s;
    }
    return (0);
}

QString DataReader::readString(){
    QByteArray bstr = readBytes(readShort());
    QString str;
    int i = 0;
    while(i != bstr.size())
    {
        str.append(bstr.at(i));
        i++;
    }
    return (str);
}

qint64 DataReader::readDouble()
{
    byte array[8];
    array[7] = readByte();
    array[6] = readByte();
    array[5] = readByte();
    array[4] = readByte();
    array[3] = readByte();
    array[2] = readByte();
    array[1] = readByte();
    array[0] = readByte();
    return qint64(*reinterpret_cast<double * const>(array));
}

bool DataReader::ByteAvalable()
{
    return _pos < _buffer.length();
}
