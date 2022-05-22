#include "serialportfactory.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/CapApp/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QSerialPort serialPort;
    const QString serialPortName = "COM7";
    const int serialPortBaudRate = QSerialPort::Baud115200;

    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(serialPortBaudRate);

    serialPort.open(QIODevice::ReadOnly);

    SerialPortFactory SerialPortFactory(&serialPort);

    return app.exec();
}
