#include "mainwindow.h"
#include "gridwidget.h"
#include "ui_mainwindowform.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QChartView>
#include <vector>

MainWindow570::MainWindow570(QWidget *parent):QMainWindow{parent}, mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
    connect(mMainWindowUI->actionExit, SIGNAL(triggered()), this, SLOT(actionExit_triggered()));
    connect(mMainWindowUI->actionReset, SIGNAL(triggered()), this, SLOT(reset()));
    resize(antWorld.get_world_size() + extraSpace, antWorld.get_world_size() + extraSpace);
    create_world();
    timer.start(timeStepInMiliSeconds,this);
}

MainWindow570::~MainWindow570()
{
    delete mMainWindowUI;
}

void MainWindow570::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) {
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void MainWindow570::actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow570::reset()
{
    antWorld.reset();
}

void MainWindow570::create_world()
{
    QHBoxLayout* layoutForFoodandAnts = new QHBoxLayout{mMainWindowUI->gridFrame};
    antSimulation = new GridWidget{antWorld, mMainWindowUI->gridFrame};
    antSimulation->setStyleSheet("background-color:black");
    layoutForFoodandAnts->addWidget(antSimulation);
}

