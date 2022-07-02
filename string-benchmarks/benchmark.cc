// Copyright (c) 2022 Kaiyan M. Lee
//
// This project is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License v3.0.

#include "benchmark.h"

#include <QtTest/QTest>

void StringTester::tst_std_string()
{
    QBENCHMARK
    {
        auto a = std::string("Hello, World (01).");
        Q_ASSERT(a.length() > 0);
    }
}

void StringTester::tst_std_string_to_QString()
{
    QBENCHMARK
    {
        auto a = std::string("Hello, World (02).");
        auto b = QString::fromStdString(a);
        Q_ASSERT(b.length() > 0);
    }
}

void StringTester::tst_std_string_from_QString()
{
    QBENCHMARK
    {
        auto a = QString::fromUtf8("Hello, World (03).");
        auto b = a.toStdString();
        Q_ASSERT(b.length() > 0);
    }
}

void StringTester::tst_QUrl_from_QString()
{
    QBENCHMARK
    {
        auto a = QUrl(QLatin1String("localhost:1313"), QUrl::StrictMode);
        Q_ASSERT(!a.isEmpty());
    }
}

void StringTester::tst_QUrl_to_QString()
{
    QBENCHMARK
    {
        auto a = QUrl(QString::fromLatin1("localhost:3131"));
        auto b = a.toDisplayString();
        Q_ASSERT(b.length() > 0);
    }
}

void StringTester::tst_QStringLiteral()
{
    QBENCHMARK
    {
        auto a = QStringLiteral("Hello, World (04).");
        Q_ASSERT(a.length() > 0);
    }
}

void StringTester::tst_QString()
{
    QBENCHMARK
    {
        auto a = QString::fromUtf8("Hello, World (05).");
        Q_ASSERT(a.length() > 0);
    }
}

void StringTester::tst_QLatin1String()
{
    QBENCHMARK
    {
        auto a = QLatin1String("Hello, World (06).");
        Q_ASSERT(a.size() > 0);
    }
}

void StringTester::tst_QAnyStringView()
{
    QBENCHMARK
    {
        auto a = QAnyStringView("Hello, World (07).");
        Q_ASSERT(a.size() > 0);
    }
}

void StringTester::tst_QStringFromLatin1()
{
    QBENCHMARK
    {
        auto a = QString::fromLatin1("Hello, World (08).");
        Q_ASSERT(a.size() > 0);
    }
}

void StringTester::tst_QStringFromQLatin1String()
{
    QBENCHMARK
    {
        auto a = QString(QLatin1String("Hello, World (09)."));
        Q_ASSERT(a.size() > 0);
    }
}

void StringTester::tst_QStringFromQStringLiteral()
{
    QBENCHMARK
    {
        auto a = QString(QStringLiteral("Hello, World (10)."));
        Q_ASSERT(a.size() > 0);
    }
}

QTEST_MAIN(StringTester);
