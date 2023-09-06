#include "serial_toolbar.h"
#include "qglobal.h"




Serial_ToolBar::Serial_ToolBar(QWidget *parent) :
    QToolBar(parent)
{

}



//Serial_ToolBar::Serial_ToolBar(QWidget *parent, QSerialPort* ptSerialPort) :
//    QToolBar(parent),
//    m_tToolBtn_Port(this),
//    m_tComboBox_Port(this),
//    m_tToolBtn_SerialCfg(this),
//    m_tToolBtn_Open(this),
//    m_tToolBtn_Close(this)
//{
//    //串口设备
//    m_ptSerialPort = ptSerialPort;

//    setMovable(false);
//    setContentsMargins(0, 0, 0, 0);

//    //m_tToolBtn_Port.setSizePolicy(QToolButton::Adj);
//    m_tComboBox_Port.setSizeAdjustPolicy(QComboBox::AdjustToContents);

//    QWidget *leftMargin = new QWidget(this);
//    leftMargin->setFixedWidth(4);
//    addWidget(leftMargin);

//    //Port
//    m_tToolBtn_Port.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    addWidget(&m_tToolBtn_Port);
//    addWidget(&m_tComboBox_Port);

//    //cfg
//    m_tToolBtn_SerialCfg.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    addWidget(&m_tToolBtn_SerialCfg);

//    //Open
//    m_tToolBtn_Open.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    addWidget(&m_tToolBtn_Open);
//    //Close
//    m_tToolBtn_Close.setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
//    addWidget(&m_tToolBtn_Close);


//}



/**
  * @brief
  * @param
  * @retval
  */
Serial_ToolBar::Serial_ToolBar(QWidget *parent, QSerialPort* ptSerialPort) :
    QToolBar(parent)
{
    m_ptToolBtn_Port = nullptr;
    m_ptComboBox_Port = nullptr;
    m_ptToolBtn_SerialCfg = nullptr;
    m_ptToolBtn_Open = nullptr;
    m_ptToolBtn_Close = nullptr;

    //串口设备
    m_ptSerialPort = ptSerialPort;
    m_ptSerialConfig = new SerialConfig(this, ptSerialPort);

    setMovable(false);
    setContentsMargins(0, 0, 0, 0);

    QWidget *leftMargin = new QWidget(this);
    leftMargin->setFixedWidth(4);
    addWidget(leftMargin);

    //Port，端口提示
    m_ptToolBtn_Port = new QToolButton(this);
    m_ptToolBtn_Port->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_ptToolBtn_Port->setIcon(QIcon(":/icons/icons/sub_port.ico"));
    m_ptToolBtn_Port->setText(QString(tr("串口")));
    addWidget(m_ptToolBtn_Port);
    m_ptToolBtn_Port->setEnabled(false);

    //Port Combobox,端口选择
    m_ptComboBox_Port = new QComboBox(this);
    m_ptComboBox_Port->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    uint16_t usIndex = m_ptSerialConfig->m_tSerialParam.strListPortName.count();
    for(uint16_t i = 0; i < usIndex; i++)
    {
        QString strPortName_Des = m_ptSerialConfig->m_tSerialParam.strListPortName.at(i) + QString(" ") + \
                                    m_ptSerialConfig->m_tSerialParam.stListrPortDes.at(i);
        m_ptComboBox_Port->addItem(strPortName_Des);
    }
 //   connect(m_ptComboBox_Port, &QComboBox::currentIndexChanged, this, &Serial_ToolBar::on_Serial_Port_Change);
    addWidget(m_ptComboBox_Port);

    //Cfg, 参数修改
    m_ptToolBtn_SerialCfg = new QToolButton(this);
    m_ptToolBtn_SerialCfg->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_ptToolBtn_SerialCfg->setIcon(QIcon(":/icons/icons/setting.ico"));
    m_ptToolBtn_SerialCfg->setText(QString(tr("设置")));
    connect(m_ptToolBtn_SerialCfg, &QToolButton::clicked, this, &Serial_ToolBar::on_Serial_Param_Cfg);
    addWidget(m_ptToolBtn_SerialCfg);

    //Open，打开串口
    m_ptToolBtn_Open = new QToolButton(this);
    m_ptToolBtn_Open->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_ptToolBtn_Open->setIcon(QIcon(":/icons/icons/Rotate_Right.png"));
    m_ptToolBtn_Open->setText(QString(tr("打开")));
    connect(m_ptToolBtn_Open, &QToolButton::clicked, this, &Serial_ToolBar::on_Serial_Open);    addWidget(m_ptToolBtn_Open);

    //Close，关闭串口
    m_ptToolBtn_Close = new QToolButton(this);
    m_ptToolBtn_Close->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_ptToolBtn_Close->setIcon(QIcon(":/icons/icons/Stop.png"));
    m_ptToolBtn_Close->setText(QString(tr("关闭")));
    connect(m_ptToolBtn_Close, &QToolButton::clicked, this, &Serial_ToolBar::on_Serial_Close);
    addWidget(m_ptToolBtn_Close);

    //打开，关闭按键状态
    m_ptToolBtn_Open->setEnabled(true);
    m_ptToolBtn_SerialCfg->setEnabled(true);
    m_ptToolBtn_Close->setEnabled(false);
    m_bOpenFlag = false;
}




/**
  * @brief
  * @param
  * @retval
  */
Serial_ToolBar::~Serial_ToolBar()
{
    if(nullptr == m_ptToolBtn_Port)      delete m_ptToolBtn_Port;
    if(nullptr == m_ptComboBox_Port)     delete m_ptComboBox_Port;
    if(nullptr == m_ptToolBtn_SerialCfg) delete m_ptToolBtn_SerialCfg;
    if(nullptr == m_ptToolBtn_Open)      delete m_ptToolBtn_Open;
    if(nullptr == m_ptToolBtn_Close)     delete m_ptToolBtn_Close;
}




/**
  * @brief 串口打开标志位
  * @param
  * @retval
  */
bool Serial_ToolBar::Serial_Open_Flag()
{
    return m_bOpenFlag;
}



/**
  * @brief
  * @param
  * @retval
  */
//void Serial_ToolBar::on_Serial_Port_Change(int index)
//{
    //none
//    m_tSerialParam.strPortName = ui->comboBox_Port->itemData(ui->comboBox_Port->currentIndex()).toString();  //保留最后一个Port name des
//    m_tSerialParam.strPortDes = ui->comboBox_Port->currentText();
//    qDebug()<<"strPortName: "<<m_tSerialParam.strPortName<<" "<<"Des "<<m_tSerialParam.strPortDes;
//}




/**
  * @brief 串口参数接口
  * @param
  * @retval
  */
void Serial_ToolBar::on_Serial_Param_Cfg(bool bBool)
{
    int ret = m_ptSerialConfig->exec();
    qDebug()<<__FUNCTION__<<":"<<ret;

    if(ret == QDialog::Accepted)
    {
        //等待窗口关闭
    }
}




/**
  * @brief 打开串口
  * @param
  * @retval
  */
void Serial_ToolBar::on_Serial_Open(bool bBool)
{
    uint16_t usPortIndex = m_ptComboBox_Port->currentIndex();
    m_ptSerialPort->setPortName(m_ptSerialConfig->m_tSerialParam.strListPortName.at(usPortIndex));
    m_ptSerialPort->setBaudRate(m_ptSerialConfig->m_tSerialParam.lBaudRate);
    m_ptSerialPort->setDataBits(m_ptSerialConfig->m_tSerialParam.dataBits);
    m_ptSerialPort->setParity(m_ptSerialConfig->m_tSerialParam.parity);
    m_ptSerialPort->setStopBits(m_ptSerialConfig->m_tSerialParam.stopBits);
    m_ptSerialPort->setFlowControl(m_ptSerialConfig->m_tSerialParam.flowControl);

    if (m_ptSerialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<"Open Serial Success";
        m_ptToolBtn_Open->setEnabled(false);
        m_ptToolBtn_SerialCfg->setEnabled(false);
        m_ptToolBtn_Close->setEnabled(true);
        m_bOpenFlag = true;
    } else {
        QMessageBox::critical(this, tr("Error"), m_ptSerialPort->errorString());
        m_ptToolBtn_Open->setEnabled(true);
        m_ptToolBtn_SerialCfg->setEnabled(true);
        m_ptToolBtn_Close->setEnabled(false);
        qDebug()<<"Open Serial Failure";
        m_bOpenFlag = false;
    }
}




/**
  * @brief 关闭串口
  * @param
  * @retval
  */
void Serial_ToolBar::on_Serial_Close(bool bBool)
{
    if (true == m_bOpenFlag) {

        //关闭串口
        m_ptSerialPort->close();

        //设置按键状态等
        m_ptToolBtn_Open->setEnabled(true);
        m_ptToolBtn_SerialCfg->setEnabled(true);
        m_ptToolBtn_Close->setEnabled(false);
        m_bOpenFlag = false;
        qDebug()<<"Close Serial";

    }
}










