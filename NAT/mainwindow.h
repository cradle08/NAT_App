#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QtSerialPort>
#include <QDebug>


#include "serialconfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //发送串口数据
    void Send_Serial_Data();


 public slots:
    //打开串口参数设置界面
    void Do_Action_Serial_Config();
    //读取串口数据
    void Do_Read_Serial_Data();


private:
    Ui::MainWindow *ui;

public:

    //串口设备
    QSerialPort *m_ptSerialPort;

    //串口配置窗口
    SerialConfig *m_ptSerialConfig;

private slots:
    void on_pushButton_Send_clicked();
};

#endif // MAINWINDOW_H
