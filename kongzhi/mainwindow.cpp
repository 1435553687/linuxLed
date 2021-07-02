#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//int ti=1;
//static int fb;
//int arg;
//int n=0;
//pthread_t p1;

//void *thrd_yqs(void *arg){
//    int s,a=0;
//    int b,c,d,ab,ac,ba,ca,da;
//    ac=0;
//        while(1)
//        {
//            if(n==0)
//            {
//                ioctl(fb,0,0);
//                ioctl(fb,0,1);
//                ioctl(fb,0,2);
//                ioctl(fb,0,3);
//            }else if(n==1)
//            {
//                sleep(ti);
//                s=a%2;
//                ioctl(fb,s,0);
//                ioctl(fb,s,1);
//                ioctl(fb,s,2);
//                ioctl(fb,s,3);
//                a++;
//            }else if(n==2)
//            {
//                sleep(ti);
//                ab=ac%4;
//                b=(ab+1)%4;
//                c=(ab+2)%4;
//                d=(ab+3)%4;
//                ioctl(fb,1,ab);
//                ioctl(fb,0,b);
//                ioctl(fb,0,c);
//                ioctl(fb,0,d);
//                ac++;
//            }else if(n==3)
//            {
//                sleep(ti);
//                ab=rand()%2;
//                ba=rand()%2;
//                ca=rand()%2;
//                da=rand()%2;
//                ioctl(fb,ab,0);
//                ioctl(fb,ba,1);
//                ioctl(fb,ca,2);
//                ioctl(fb,da,3);
//            }
//        }
//    return NULL;
//}

void MainWindow::Textt()//读取串口数据并显示出来
{
    QByteArray temp = myCom->readAll();    //返回读取的字节
    QString str = temp;
//    if(str!=NULL)
//    {
//        if(str ==QString::fromLocal8Bit("/jiasu"))
//        {
//
//            pthread_create(&p1, NULL,thrd_yqs, NULL);
//            n=1;
//            ui->label->setText("1");
//
//        }
//        else if(str ==QString::fromLocal8Bit("/2"))
//        {
//            pthread_create(&p1, NULL,thrd_yqs, NULL);
//            n=2;
//            ui->label->setText("2");
//        }
//    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
readTimer=new QTimer(this);
    readTimer->start(100);
    myCom = new Posix_QextSerialPort("/nfs/ttyS1",QextSerialBase::Polling);
    myCom ->open(QIODevice::ReadWrite);
    myCom->setBaudRate(BAUD9600);          //波特率设置，我们设置为9600
    myCom->setDataBits(DATA_8);            //数据位设置，我们设置为8位数据位
    myCom->setParity(PAR_NONE);           //奇偶校验设置，我们设置为无校验
    myCom->setStopBits(STOP_1);            //停止位设置，我们设置为1位停止位
    myCom->setFlowControl(FLOW_OFF);      //控制流
    myCom->setTimeout(100);              //设置时间间隔

    connect(readTimer,SIGNAL(timeout()),this,SLOT(Textt()));


myCom->flush();
//    QFile f("/nfs/myleds.ko");
//    if (f.exists())
//        {
//                fb = open("/nfs/myleds.ko", QIODevice::ReadWrite);
//                if (fb < 0)
//                {
//                        perror("open device leds fail");
//                        return  ;
//                }
//        }
//        else{
//                perror("leds device not exit");
//                return  ;
//        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
myCom->write("/1");
//    pthread_create(&p1, NULL,thrd_yqs, NULL);
//    n=1;
//    ui->label->setText("1");
myCom->flush();
}

void MainWindow::on_pushButton_2_clicked()
{
//    pthread_create(&p1, NULL,thrd_yqs, NULL);
//    n=2;
//    ui->label->setText("2");
    myCom->write("/2");
    myCom->flush();
}


void MainWindow::on_pushButton_3_clicked()
{
//    pthread_create(&p1, NULL,thrd_yqs, NULL);
//    ui->label->setText("3");
//    n=3;
    myCom->write("/3");
    myCom->flush();
}

void MainWindow::on_pushButton_4_clicked()
{
    /*pthread_create(&p1, NULL,thrd_yqs, NULL);
    ui->label->setText("0");
    n=0*/;
}

void MainWindow::on_radioButton_clicked()
{
//    ti=3;
    myCom->write("/4");
    myCom->flush();
}

void MainWindow::on_radioButton_2_clicked()
{
//    ti=2;
    myCom->write("/5");
    myCom->flush();
}

void MainWindow::on_radioButton_3_clicked()
{
//    ti=1;
    myCom->write("/6");
    myCom->flush();
}


