#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QHBoxLayout>
#include <QFrame>
#include <QLineSeries>
#include <QtCharts>
#include <QChart>

#include "world.h"


class GridWidget;

namespace Ui

{
class MainWindowForm;
}

class MainWindow570 : public QMainWindow
{

    Q_OBJECT

public:

    explicit MainWindow570(QWidget *parent = 0);
    ~MainWindow570();

public slots:

    void actionExit_triggered();
    void reset();
    void timerEvent(QTimerEvent *event);

private slots:

private:

    World antWorld;
    QBasicTimer timer;
    Ui::MainWindowForm *mMainWindowUI;
    GridWidget* antSimulation;

    int timeStepInMiliSeconds{75};
    int extraSpace{100};

    void create_world();

};

#endif // MAINWINDOW_H
