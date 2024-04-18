#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isJumping(false)
    , jumpHeight(0)
    , jumpVelocity(10)
{
    ui->setupUi(this);
     //创建游戏定时器
    gameTimer=new QTimer(this);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(updateGame()));
    gameTimer->start(16);//约60fps

    playerPosX = 100;
    PlayerPosY = 100;

    //创建游戏场景和视图
    gameScene = new QGraphicsScene(this);
    gameView = new QGraphicsView(gameScene);
    setCentralWidget(gameView);

    //添加玩家（）

    //添加平台
    QGraphicsRectItem *platform = new QGraphicsRectItem(0,300,400,20);
    //setbrush
    gameScene->addItem(platform);

    //设置游戏场景大小
    gameScene->setSceneRect(0,0,800,600);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGame(){
    //更新游戏状态
    if(isJumping){
        //增加跳跃高度
        jumpHeight+=jumpVelocity;
        player->setY(player->y()-jumpVelocity);

        //如果达到最大高度，开始下落
        if(jumpHeight>=100){
            jumpVelocity = -10;//设置下落速度
        }

        //如果玩家回到平台上
        if(player->y()>=250){
            isJumping = false;
            jumpHeight = 0;
            jumpVelocity=10;
            player->setY(250);
        }
    }
}

void MainWindow::KeyPressEvent(QKeyEvent *event){
    //处理键盘事件
    if(event->key() == Qt::Key_Left){
        player->setX(player->x()-5);
    }
    else if (event->key() == Qt::Key_Right){
        player->setX(player->x()+5);
    }
    else if(event->key() == Qt::Key_Space && !isJumping){
        isJumping = true;
    }
}
