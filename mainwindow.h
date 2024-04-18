#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateGame();

private:
    Ui::MainWindow *ui;
    QTimer *gameTimer;
    int playerPosX,PlayerPosY;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;
    QGraphicsItem *player;
    bool isJumping;
    int jumpHeight;
    int jumpVelocity;

    void KeyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
