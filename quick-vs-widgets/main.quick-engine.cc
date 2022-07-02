// Copyright (c) 2022 Kaiyan M. Lee
//
// This project is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License v3.0.

#include <QtCore/QElapsedTimer>
#include <QtCore/QTimer>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

int main(int argc, char** argv)
{
    QElapsedTimer timer;
    timer.start();

    qputenv("QV4_FORCE_INTERPRETER", "1");
    qputenv("QML_DISABLE_DISK_CACHE", "1");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine(QStringLiteral("qrc:/main.qml"));

    // qInfo() << timer.elapsed() << "milliseconds";

    QMetaObject::invokeMethod(
      &app,
      [&timer]() {
          //   qInfo() << timer.elapsed() << "milliseconds";
          QCoreApplication::exit();
      },
      Qt::QueuedConnection);

    return app.exec();
}
