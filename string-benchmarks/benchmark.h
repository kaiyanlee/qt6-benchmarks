// Copyright (c) 2022 Kaiyan M. Lee
//
// This project is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License v3.0.

#include <QtTest/QTest>

class StringTester : public QObject
{
    Q_OBJECT

public:
    StringTester() = default;

private:
    Q_SLOT void tst_std_string();
    Q_SLOT void tst_std_string_to_QString();
    Q_SLOT void tst_std_string_from_QString();

    Q_SLOT void tst_QUrl_from_QString();
    Q_SLOT void tst_QUrl_to_QString();

    Q_SLOT void tst_QString();

    Q_SLOT void tst_QStringLiteral();
    Q_SLOT void tst_QLatin1String();

    Q_SLOT void tst_QAnyStringView();

    Q_SLOT void tst_QStringFromLatin1();
    Q_SLOT void tst_QStringFromQLatin1String();
    Q_SLOT void tst_QStringFromQStringLiteral();
};
