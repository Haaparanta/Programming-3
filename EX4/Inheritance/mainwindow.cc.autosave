#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "fastball.hh"
#include "constants.hh"
#include "movingobjectgraphics.hh"

#include <QDebug>
#include <QLayout>
#include <QWidget>
#include <QTimer>

const QString MainWindow::S_START = QString("Start");
const QString MainWindow::S_STOP = QString("Stop");


MainWindow::MainWindow(ObjectController* controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), engine_(controller)
{

    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene;
    view_ = new QGraphicsView(this);
    view_->setScene(scene);
    ui->gridLayout->addWidget(view_);
    scene->setSceneRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT);
    connect(ui->startButton, &QPushButton::clicked,
            this, &MainWindow::startOrStop);
    connect(ui->exitButton, &QPushButton::clicked,
            this, &MainWindow::close);

    // Set timer
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout,
            this, &MainWindow::moveObjects);

    timer_->setInterval(CLOCK_MS);
}

MainWindow::~MainWindow()
{

}

void MainWindow::spawnObjects(int count, ObjectType type)
{
    qDebug() << "Count: " << count << "  Type: "  << type;
    for( int i = 0; i < count; ++i)
    {
        if( type == ObjectType::FASTBALL )
        {
            auto pObj = std::make_shared<FastBall>();
            engine_->registerObject(pObj);
            auto pGraph = new MovingObjectGraphics(pObj);
            graphics_.push_back(pGraph);
            view_->scene()->addItem(pGraph);

        }
    }
}

void MainWindow::moveObjects()
{
    engine_->moveObjects();
    for (auto g = graphics_.begin(); g != graphics_.end(); ++g){
        (*g)->updatePos();
    }
}

void MainWindow::startOrStop()
{
    if(ui->startButton->text() == MainWindow::S_START)
    {
        timer_->start();
        ui->startButton->setText(MainWindow::S_STOP);
    }
    else
    {
        timer_->stop();
        ui->startButton->setText(MainWindow::S_START);
    }

}


