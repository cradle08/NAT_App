#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QtSerialPort>
#include <QDebug>
#include <QComboBox>
#include <QPushButton>
#include <QToolBar>
#include <QVector>
#include <QGraphicsView>

#include "workflow.h"
#include "serial_toolbar.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum {
      EN_TAB_INDEX_Sample_Analysis  = 0,
      EN_TAB_INDEX_ListReview,
      EN_TAB_INDEX_QC,
      EN_TAB_INDEX_Set,
      EN_TAB_INDEX_Debug,
    };


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //发送串口数据
    void Send_Serial_Data();

    //默认流程初始化
    void Define_Process_Init();

 public slots:
//    //打开串口参数设置界面
//    void on_Action_Serial_Config();
     //处理串口接受消息
     uint8_t on_Handle_Recv_Msg();

    //样本分析
    void on_Action_SampleAnalysis(bool bBool);

    //列表回顾
    void on_Action_ListReview(bool bBool);

    //质控
    void on_Action_QC(bool bBool);

    //设置
    void on_Action_Set(bool bBool);

    //注销
    void on_Action_Logout(bool bBool);

    //关闭
    void on_Action_Close(bool bBool);

    //上一记录
    void on_Last_Record();

    //下一记录
    void on_Next_Record();

    //启动分析
    void on_Start_Analysis();

    //打印
    void on_Print();

    //样本信息输入
    void on_Sample_Info_Input();



    //串口配置窗口
 //   SerialConfig *m_ptSerialConfig;

private slots:
    void on_pushButton_Send_clicked();


private:
    Ui::MainWindow *ui;

public:
    QSerialPort *m_ptSerialPort; //串口设备
    Serial_ToolBar *m_ptSerial_ToolBar; //串口-工具栏
    QToolBar *m_ptFuncBar; //菜单-工具栏
    QVector<WorkFlow*> *m_ptVector_WorkFlow;

};

#endif // MAINWINDOW_H








