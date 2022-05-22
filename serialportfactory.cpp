#include <QSerialPort>
#include <QCoreApplication>

#include "serialportfactory.h"

SerialPortFactory::SerialPortFactory(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortFactory::handleReadyRead);
}

void SerialPortFactory::handleReadyRead()
{
    m_readData.clear();

    m_readData.append(m_serialPort->readAll());

}
