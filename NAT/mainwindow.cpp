#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "serial_toolbar.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 //   setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    /* 串口 */
    m_ptSerialPort = nullptr;
    m_ptSerialPort = new QSerialPort(this);
    //串口接受消息处理
    connect(m_ptSerialPort, &QSerialPort::readyRead, this, &MainWindow::on_Handle_Recv_Msg);

    /* 串口工具栏 */
   m_ptSerial_ToolBar = new Serial_ToolBar(this, m_ptSerialPort);
   addToolBar(m_ptSerial_ToolBar);

   /* 功能工具栏 */
   m_ptFuncBar = new QToolBar(this);
   m_ptFuncBar->setMovable(false);
   m_ptFuncBar->setContentsMargins(0, 0, 0, 0);

   //样本分析
//   QAction *ptAction = new QAction(this);
//   ptAction->setText(QString(tr("样本分析")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/hand.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_SampleAnalysis);
//   m_ptFuncBar->addAction(ptAction);
   QToolButton *ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/hand.ico")));
   ptToolBtn->setText(QString(tr("样本分析")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_SampleAnalysis);

   //列表回顾
//   ptAction = new QAction(this);
//   ptAction->setText(QString(tr("列表回顾")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/parameter.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_ListReview);
//   m_ptFuncBar->addAction(ptAction);
   ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/parameter.ico")));
   ptToolBtn->setText(QString(tr("列表回顾")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_ListReview);

   //质控
//   ptAction = new QAction(this);
//   ptAction->setText(QString(tr("质控")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/graph.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_QC);
//   m_ptFuncBar->addAction(ptAction);
   ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/graph.ico")));
   ptToolBtn->setText(QString(tr("质控")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_QC);

   //设置
//   ptAction = new QAction(this);
//   ptAction->setText(QString(tr("设置")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/settings.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_Set);
//   m_ptFuncBar->addAction(ptAction);
   ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/settings.ico")));
   ptToolBtn->setText(QString(tr("设置")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_Set);


   //注销
//   ptAction = new QAction(this);
//   ptAction->setText(QString(tr("注销")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/down.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_Logout);
//   m_ptFuncBar->addAction(ptAction);
   ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/down.ico")));
   ptToolBtn->setText(QString(tr("注销")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_Logout);

   //关闭
//   ptAction = new QAction(this);
//   ptAction->setText(QString(tr("关闭")));
//   ptAction->setIcon(QIcon(QString(":/icons/icons/down.ico")));
//   connect(ptAction, &QAction::triggered, this, &MainWindow::on_Action_Close);
//   m_ptFuncBar->addAction(ptAction);
   ptToolBtn = new QToolButton(this);
   ptToolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   ptToolBtn->setIcon(QIcon(QString(":/icons/icons/down.ico")));
   ptToolBtn->setText(QString(tr("关闭")));
   m_ptFuncBar->addWidget(ptToolBtn);
   connect(ptToolBtn, &QToolButton::clicked, this, &MainWindow::on_Action_Close);
   //
   addToolBar(m_ptFuncBar);


//    //串口配置窗口
//    m_ptSerialConfig = nullptr;
//    m_ptSerialConfig = new SerialConfig(this, m_ptSerialPort);
// //   connect(ui->actionSerialConfig, &QAction::triggered, this, &MainWindow::Do_Action_Serial_Config);

//    /* 工具栏 - 窗口 */
//    ui->toolBar_Comm->setFixedHeight(40);
//    QLabel *ptLabel_Port = new QLabel(ui->toolBar_Comm);
//    ptLabel_Port->setText(QString("Port"));
// //   QComboBox *ptComboBox = new QComboBox(ui->toolBar_Comm);

}

MainWindow::~MainWindow()
{
    delete ui;
    if(nullptr != m_ptSerialPort)       delete m_ptSerialPort;
    if(nullptr != m_ptSerial_ToolBar)   delete m_ptSerial_ToolBar;
    if(nullptr != m_ptFuncBar)          delete m_ptFuncBar;
}



/*
 * @brif
 * @param
 * @note
 */
//void MainWindow::on_Action_Serial_Config()
//{
//    qDebug()<<"Action Serial Config";
////    m_ptSerialConfig->show();

//}



/**
* @brief 处理串口接受消息
* @param
* @retval
*/
uint8_t MainWindow::on_Handle_Recv_Msg()
{
    QByteArray Arr = m_ptSerialPort->readAll();
    qDebug()<<"Do_Read_Serial_Data:"<<Arr;
 //   ui->plainTextEdit_RecvMsg->appendPlainText(QString(Arr));

}




/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_SampleAnalysis(bool bBool)
{
    ui->stackedWidget->setCurrentWidget(ui->page_SampleAnalysis);
}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_ListReview(bool bBool)
{
    ui->stackedWidget->setCurrentWidget(ui->page_ListReview);
}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_QC(bool bBool)
{
    ui->stackedWidget->setCurrentWidget(ui->page_QC);
}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_Set(bool bBool)
{
    ui->stackedWidget->setCurrentWidget(ui->page_Set);
}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_Logout(bool bBool)
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Action_Close(bool bBool)
{

    close();
}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Last_Record()
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Next_Record()
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Start_Analysis()
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Print()
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_Sample_Info_Input()
{

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::Send_Serial_Data()
{

 //   QByteArray  Arr = ui->plainTextEdit_SendMsg->toPlainText().toLocal8Bit();

 //   m_ptSerialPort->write(Arr);
    //    qDebug()<<"Send_Serial_Data:"<<Arr;
}






/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::on_pushButton_Send_clicked()
{
    Send_Serial_Data();
}






















