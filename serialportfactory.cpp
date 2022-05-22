#include <QSerialPort>
#include <QCoreApplication>

#include "serialportfactory.h"

SerialPortFactory::SerialPortFactory(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    port(serialPort)
{
    connect(port, &QSerialPort::readyRead, this, &SerialPortFactory::handleReadyRead);
}

void SerialPortFactory::handleReadyRead()
{
    rcvData.clear();

    rcvData.append(port->readAll());

}
