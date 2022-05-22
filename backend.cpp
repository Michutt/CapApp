#include "backend.h"

Backend::Backend()
{
    //
}

void Backend::setPortName(const QString &name)
{
    portName = name;
}

void Backend::setPortBaud(const int &baud)
{
    portBaud = baud;
}

void Backend::setConnect(const bool &connected)
{
    if (!isConnected)
    {
        serialPort.setPortName(portName);
        serialPort.setBaudRate(portBaud);

        if(serialPort.open(QIODevice::ReadWrite))
        {
            isConnected = true;
        }
        serialFactory = new SerialPortFactory(&serialPort);
    }
}

