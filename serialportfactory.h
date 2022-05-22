#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class SerialPortFactory : public QObject
{
    Q_OBJECT

public:
    SerialPortFactory(QSerialPort *serialPort, QObject *parent = nullptr);

private slots:
    void handleReadyRead();

private:
    QSerialPort *port = nullptr;
    QByteArray rcvData;
};

#endif // SERIALPORT_H
