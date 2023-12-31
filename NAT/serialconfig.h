﻿#ifndef SERIALCONFIG_H
#define SERIALCONFIG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSerialPort>
#include <QDebug>
#include <QIntValidator>
#include <QSerialPortInfo>

namespace Ui {
class SerialConfig;
}

class SerialConfig : public QDialog
{
    Q_OBJECT

public:
    typedef struct
    {
        //端口
        QStringList strListPortName;    //端口
        QStringList stListrPortDes;     //端口描述
        //波特率
        qint32 lBaudRate;
        QString strBaudRate;
        //数据位
        QSerialPort::DataBits dataBits;
        QString strDateBits;
        //校验位
        QSerialPort::Parity parity;
        QString stringParity;
        //停止位
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        //控制流
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;

    }SerialParam_t;

public:
    explicit SerialConfig(QWidget *parent = nullptr);
    SerialConfig(QWidget *parent = nullptr, QSerialPort* ptSerialPort= nullptr);
    ~SerialConfig();

    //初始化串口参数
    void Init_SerialPort_Param();

public:
    QSerialPort* m_ptSerialPort;
    SerialParam_t m_tSerialParam;

private slots:
//    void on_pushButton_Open_clicked();

//    void on_pushButton_Close_clicked();

 //   void on_comboBox_Port_currentIndexChanged(int index);

    void on_comboBox_Baud_currentIndexChanged(int index);

    void on_comboBox_Data_currentIndexChanged(int index);

    void on_comboBox_Parity_currentIndexChanged(int index);

    void on_comboBox_StopBit_currentIndexChanged(int index);

    void on_comboBox_FlowCtrl_currentIndexChanged(int index);

    void on_pushButton_Sure_clicked();

private:
    Ui::SerialConfig *ui;
};

#endif // SERIALCONFIG_H
