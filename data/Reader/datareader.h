#ifndef DATAREADER_H
#define DATAREADER_H
#include <QObject>
/*
Auteur : Anthony
Date de création : 14/02/2013

Rôle :
Lecture des informations du fichier.
*/

#include <QByteArray>
typedef unsigned char byte;
class DataReader
{

public:
    DataReader();
    DataReader(QByteArray bytes);
    void fromBytes(QByteArray bytes);
    void setPos(int pos);
    int getPos();
    int readInt();
    byte readByte();
    QByteArray readBytes(int number);
    short readShort();
    QString readString();
   qint64 readDouble();
    bool ByteAvalable();

private:
    int _pos;
    QByteArray _buffer;
};

#endif // DATAREADER_H
