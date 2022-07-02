# Qt6 Benchmarks (6.2.3)

Notice: This is a work in progress, out of date, and should not be trusted to be scientifically accurate. Use the official benchmark suite made by Qt developers if you need real benchmarks for your release builds.

These are a collection of benchmarks that demonstrate the performance of various Qt6 features.

## Table of Contents

- [Background](#background)
- [Dependencies](#dependencies)
- [Getting Started](#getting-started)
- [Quick vs Widgets](#quick-vs-widgets)
- [QString](#string-benchmarks)
- TODO: Hash Tables (QHash vs QMap vs abseil vs std::unordered_map)
- TODO: Regular Expressions (QRegularExpression vs Onigurama vs std::regex)
- TODO: Image vs Text animation performance

## Background

- Hardware: `Intel Core i7 laptop throttled to a maximum of 2GHz`
- System: `Linux 5.16.4 x86_64`
- Defines: `QT_NO_EXCEPTIONS`
- Qt: `6.2.3 shared (dynamic) release build; by GCC 11.1.0`
- Features: `SSE2 SSE3 SSSE3 SSE4.1 SSE4.2 AVX AVX2`

## Dependencies

- Qt6Core
- Qt6Quick
- Qt6Qml
- Qt6Widgets
- Qt6Test

## Getting Started

```
git clone https://github.com/kaiyanlee/qt6-benchmarks
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE="Release"
make && ctest -VV
```

## Quick VS Widgets

Goal: Measure the startup time of an application using [Hyperfine](https://github.com/sharkdp/hyperfine).

Targets:

1. Simple QtWidgets application using QApplication to display a QWidget window
2. Simple QQmlApplicationEngine using QGuiApplication to display a QQuickWindow
3. Simple QQuickView using QGuiApplication to display a QQuickWindow

Results:

| Command                   |    Mean [ms] | Min [ms] | Max [ms] | Relative |
| :------------------------ | -----------: | -------: | -------: | -------: |
| `quick-engine-executable` | 170.2 ± 25.3 |    151.2 |    237.8 |     1.00 |
| `quick-executable`        | 163.3 ± 24.8 |    141.6 |    222.2 |     1.00 |
| `widgets-executable`      | 155.5 ± 23.4 |    117.7 |    188.6 |     1.00 |

Summary:

As expected, QQmlApplicationEngine is slower than QQuickView or QWidget. Clearly the extra parsing of QML is slowing it down. Overall the numbers look the same but it should be noted from personal experience that in more complex applications these numbers will increase.

This result is pretty obvious but it does not discourage me from using QtQuick. The benefits of declarative programming and the 2D/3D scene-graph integration of QtQuick3D easily outweigh a slowdown of a few milliseconds (or a bit of extra latency).

## String Benchmarks

Goal: Measure the difference between various classes storing strings.

Results:

| Task                    | Mean [ms] | Total | Iterations |
| ----------------------- | --------: | ----: | ---------: |
| QAnyStringView          | 0.0000054 |    92 |   16777216 |
| std::string             | 0.0000069 |    58 |    8388608 |
| QStringLiteral          | 0.0000065 |    55 |    8388608 |
| QLatin1String           | 0.0000064 |    54 |    8388608 |
| QString::fromLatin1     | 0.0000500 |    53 |    1048576 |
| std::string to QString  | 0.0000790 |    83 |    1048576 |
| QString                 | 0.0000750 |    79 |    1048576 |
| QString(QLatin1String)  | 0.0000500 |    53 |    1048576 |
| QString(QStringLiteral) | 0.0000061 |    53 |    1048576 |
| std::string(QString)    | 0.0002300 |    62 |     262144 |
| QUrl(QString)           | 0.0003900 |    52 |     131072 |
| QUrl to String          | 0.0006800 |    90 |     131072 |

Summary:

`QStringLiteral` and `QLatin1String` seem identical for individual creation but surprisingly `QStringLiteral` is way faster when you want to pass it around as a `QString`. Nothing else seems out of the ordinary; `std::string` to `QString` and vice versa is still really slow; `QUrl` needs a smaller alternative (QUrlView?).

## License

The source code for this project is licensed under GPLv3.
