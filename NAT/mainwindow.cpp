#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //串口
    m_ptSerialPort = nullptr;
    m_ptSerialPort = new QSerialPort(this);
    //消息处理
    connect(m_ptSerialPort, &QSerialPort::readyRead, this, &MainWindow::Do_Read_Serial_Data);

    //串口配置窗口
    m_ptSerialConfig = nullptr;
    m_ptSerialConfig = new SerialConfig(this, m_ptSerialPort);
    connect(ui->actionSerialConfig, &QAction::triggered, this, &MainWindow::Do_Action_Serial_Config);


}

MainWindow::~MainWindow()
{
    delete ui;

    if(nullptr != m_ptSerialPort) delete m_ptSerialPort;
    if(nullptr != m_ptSerialConfig) delete m_ptSerialConfig;


}



/*
 * @brif
 * @param
 * @note
 */
void MainWindow::Do_Action_Serial_Config()
{
    qDebug()<<"Action Serial Config";
    m_ptSerialConfig->show();

}



/**
  * @brief 读取串口数据
  * @param
  * @retval
  */
void MainWindow::Do_Read_Serial_Data()
{

    QByteArray Arr = m_ptSerialPort->readAll();
    ui->plainTextEdit_RecvMsg->appendPlainText(QString(Arr));
    qDebug()<<"Do_Read_Serial_Data:"<<Arr;

}



/**
  * @brief 写入串口数据
  * @param
  * @retval
  */
void MainWindow::Send_Serial_Data()
{

    QByteArray  Arr = ui->plainTextEdit_SendMsg->toPlainText().toLocal8Bit();

    m_ptSerialPort->write(Arr);
    qDebug()<<"Send_Serial_Data:"<<Arr;
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






















