#ifndef SERIAL_TOOLBAR_H
#define SERIAL_TOOLBAR_H

#include <QWidget>
#include <QToolBar>
#include <QToolButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QtSerialPort>

#include "serialconfig.h"


class Serial_ToolBar : public QToolBar
{
    Q_OBJECT

public:
    explicit Serial_ToolBar(QWidget *parent = nullptr);
    Serial_ToolBar(QWidget *parent = nullptr, QSerialPort* ptSerialPort= nullptr);
    ~Serial_ToolBar();


     //获取串口开关状态
    bool Serial_Open_Flag();

private slots:

    //更改串口号
 //   void on_Serial_Port_Change(int index);

    //选项-修改串口参数
     void on_Serial_Param_Cfg(bool bBool);

    //打开串口
    void on_Serial_Open(bool bBool);

    //关闭串口
    void on_Serial_Close(bool bBool);

private:
//    QToolButton m_tToolBtn_Port;        //端口
//    QComboBox m_tComboBox_Port;         //选择端口
//    QToolButton m_tToolBtn_SerialCfg;   //串口配置
//    QToolButton m_tToolBtn_Open;        //打开
//    QToolButton m_tToolBtn_Close;       //关闭

    QToolButton *m_ptToolBtn_Port;        //端口
    QComboBox *m_ptComboBox_Port;         //选择端口
    QToolButton *m_ptToolBtn_SerialCfg;   //串口配置
    QToolButton *m_ptToolBtn_Open;        //打开
    QToolButton *m_ptToolBtn_Close;       //关闭

    bool m_bOpenFlag;                   //串口打开标志位
    SerialConfig *m_ptSerialConfig;     //串口参数
    QSerialPort *m_ptSerialPort;        //串口设备指针

};

#endif // SERIAL_TOOLBAR_H
