#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objectcontroller.hh"
#include "constants.hh"
#include "movingobjectgraphics.hh"

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QTimer>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( ObjectController* controller, QWidget *parent = 0);
    ~MainWindow();


public slots:

    void spawnObjects(int count, ObjectType type);
    void moveObjects();
    void startOrStop();

private:

    Ui::MainWindow *ui;

    ObjectController* engine_;
    QGraphicsView* view_;
    std::vector< MovingObjectGraphics* > graphics_;


    QPushButton* button_exit_;
    QPushButton* button_control_;

    QTimer* timer_;

    static const QString S_START;
    static const QString S_STOP;
};

#endif // MAINWINDOW_H
