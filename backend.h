#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

#include "serialportfactory.h"

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString portName WRITE setPortName NOTIFY portNameChanged)
    Q_PROPERTY(int portBaud WRITE setPortBaud NOTIFY portBaudChanged)
    Q_PROPERTY(bool isConnected WRITE setConnect NOTIFY onConnect)

    QSerialPort serialPort;
    SerialPortFactory* serialFactory;

public:
    Backend();
    void setPortName(const QString &name);
    void setPortBaud(const int &baud);
    void setConnect(const bool &connected);

private:
    QString portName;
    int portBaud;
    bool isConnected;

signals:
    void portNameChanged();
    void portBaudChanged();
    void onConnect();
};

#endif // BACKEND_H
