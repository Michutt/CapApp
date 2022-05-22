#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

#include "serialportfactory.h"

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString portName WRITE setPortName NOTIFY portNameChanged)
    Q_PROPERTY(int portBaud WRITE setPortBaud NOTIFY portBaudChanged)
    Q_PROPERTY(bool connect WRITE setConnect NOTIFY onConnect)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connected)

    QSerialPort serialPort;
    SerialPortFactory* serialFactory;

public:
    Backend();
    void setPortName(const QString &name);
    void setPortBaud(const int &baud);
    void setConnect(const bool &unused);
    bool isConnected();

private:
    QString portName;
    int portBaud;
    bool m_isConnected = false;

signals:
    void portNameChanged();
    void portBaudChanged();
    void onConnect();
    void connected();
};

#endif // BACKEND_H
