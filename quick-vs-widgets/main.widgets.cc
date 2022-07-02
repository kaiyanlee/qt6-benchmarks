// Copyright (c) 2022 Kaiyan M. Lee
//
// This project is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License v3.0.

#include <QtCore/QElapsedTimer>
#include <QtCore/QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char** argv)
{
    QElapsedTimer timer;
    timer.start();

    QApplication app(argc, argv);

    QWidget window;
    window.show();

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
