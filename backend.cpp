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

bool Backend::isConnected()
{
    return m_isConnected;
}

void Backend::setConnect(const bool &unused)
{
    if (!m_isConnected)
    {
        serialPort.setPortName(portName);
        serialPort.setBaudRate(portBaud);

        if(serialPort.open(QIODevice::ReadWrite))
        {
            m_isConnected = true;
            emit connected();
        }
        serialFactory = new SerialPortFactory(&serialPort);
    }
}

