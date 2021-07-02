#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qextserialbase.h"
#include "qextserialport.h"
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
   Posix_QextSerialPort *myCom;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QTimer *readTimer;

private slots:
    void on_pushButton_4_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Textt();
};

#endif // MAINWINDOW_H
