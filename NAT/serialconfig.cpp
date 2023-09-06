#include "serialconfig.h"
#include "ui_serialconfig.h"

SerialConfig::SerialConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConfig)
{
    ui->setupUi(this);
}



SerialConfig::SerialConfig(QWidget *parent, QSerialPort* ptSerialPort) :
    QDialog(parent),
    ui(new Ui::SerialConfig)
{
    ui->setupUi(this);

    m_ptSerialPort = ptSerialPort;

    //串口参数初始化
    Init_SerialPort_Param();

    //按键初始状态
//    ui->pushButton_Open->setEnabled(true);
//    ui->pushButton_Close->setEnabled(false);
}




SerialConfig::~SerialConfig()
{
    delete ui;
}




/**
  * @brief
  * @param
  * @retval
  */
void SerialConfig::Init_SerialPort_Param()
{
    //端口
//    const auto infos = QSerialPortInfo::availablePorts();
//    for(const QSerialPortInfo &info : infos)
//    {
//        QString strPortName_Des = info.portName() + QString(" ") + info.description();
//        ui->comboBox_Port->addItem(strPortName_Des, info.portName());
//        qDebug()<<"strPortName_Des: "<<strPortName_Des;
//    }
//    m_tSerialParam.strPortName = ui->comboBox_Port->itemData(ui->comboBox_Port->currentIndex()).toString();  //保留最后一个Port name des
//    m_tSerialParam.strPortDes = ui->comboBox_Port->currentText();
//    qDebug()<<"strPortName: "<<m_tSerialParam.strPortName<<" "<<"Des "<<m_tSerialParam.strPortDes;

    uint16_t usIndex = 0;
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        m_tSerialParam.strListPortName.append(info.portName());
        m_tSerialParam.stListrPortDes.append(info.description());
        qDebug()<<"strPortName Des: "<<m_tSerialParam.strListPortName.at(usIndex)<<"  "\
            << m_tSerialParam.stListrPortDes.at(usIndex);
        usIndex++;
    }

    //波特率
    ui->comboBox_Baud->addItem(QString("9600"), QSerialPort::Baud9600);
    ui->comboBox_Baud->addItem(QString("19200"), QSerialPort::Baud19200);
    ui->comboBox_Baud->addItem(QString("38400"), QSerialPort::Baud38400);
    ui->comboBox_Baud->addItem(QString("115200"), QSerialPort::Baud115200);
    ui->comboBox_Baud->setCurrentIndex(3);
    m_tSerialParam.lBaudRate = static_cast<QSerialPort::BaudRate>(ui->comboBox_Baud->itemData(ui->comboBox_Baud->currentIndex()).toInt());
    m_tSerialParam.strBaudRate = QString::number(m_tSerialParam.lBaudRate);
    qDebug()<<"Baud: "<<m_tSerialParam.lBaudRate<<" "<<m_tSerialParam.strBaudRate;

    //数据位
    ui->comboBox_Data->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->comboBox_Data->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboBox_Data->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboBox_Data->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboBox_Data->setCurrentIndex(3);
    m_tSerialParam.dataBits = static_cast<QSerialPort::DataBits>(ui->comboBox_Data->itemData(ui->comboBox_Data->currentIndex()).toInt());
    m_tSerialParam.strDateBits =ui->comboBox_Data->currentText();
    qDebug()<<"DateBits: "<<m_tSerialParam.dataBits<<" "<<m_tSerialParam.strDateBits;

    //校验
    ui->comboBox_Parity->addItem(tr("None"), QSerialPort::NoParity);
    ui->comboBox_Parity->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->comboBox_Parity->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->comboBox_Parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->comboBox_Parity->addItem(tr("Space"), QSerialPort::SpaceParity);
    m_tSerialParam.parity = static_cast<QSerialPort::Parity>(ui->comboBox_Parity->itemData(ui->comboBox_Parity->currentIndex()).toInt());
    m_tSerialParam.stringParity =ui->comboBox_Parity->currentText();
    qDebug()<<"Parity: "<<m_tSerialParam.parity<<" "<<m_tSerialParam.stringParity;

    //停止位
    ui->comboBox_StopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboBox_StopBit->addItem(QStringLiteral("1.5"), QSerialPort::OneAndHalfStop);
    ui->comboBox_StopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
    m_tSerialParam.stopBits = static_cast<QSerialPort::StopBits>(ui->comboBox_StopBit->itemData(ui->comboBox_StopBit->currentIndex()).toInt());
    m_tSerialParam.stringStopBits =ui->comboBox_StopBit->currentText();
    qDebug()<<"stopBit: "<<m_tSerialParam.stopBits<<" "<<m_tSerialParam.stringStopBits;

    //流控
    ui->comboBox_FlowCtrl->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->comboBox_FlowCtrl->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->comboBox_FlowCtrl->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
    m_tSerialParam.flowControl = static_cast<QSerialPort::FlowControl>(ui->comboBox_FlowCtrl->itemData(ui->comboBox_FlowCtrl->currentIndex()).toInt());
    m_tSerialParam.stringFlowControl =ui->comboBox_FlowCtrl->currentText();
    qDebug()<<"FlowCtrl: "<<m_tSerialParam.flowControl<<" "<<m_tSerialParam.stringFlowControl;

}



/**
  * @brief 选择串口号
  * @param
  * @retval
  */
//void SerialConfig::on_comboBox_Port_currentIndexChanged(int index)
//{
//    m_tSerialParam.strPortName = ui->comboBox_Port->itemData(ui->comboBox_Port->currentIndex()).toString();  //保留最后一个Port name des
//    m_tSerialParam.strPortDes = ui->comboBox_Port->currentText();
//    qDebug()<<"strPortName: "<<m_tSerialParam.strPortName<<" "<<"Des "<<m_tSerialParam.strPortDes;
//}



/**
  * @brief 修改波特率
  * @param
  * @retval
  */
void SerialConfig::on_comboBox_Baud_currentIndexChanged(int index)
{
    //m_tSerialParam.lBaudRate = static_cast<QSerialPort::BaudRate>(ui->comboBox_Baud->itemData(ui->comboBox_Baud->currentIndex()).toInt());
    m_tSerialParam.lBaudRate = static_cast<QSerialPort::BaudRate>(index);
    m_tSerialParam.strBaudRate = QString::number(m_tSerialParam.lBaudRate);
    qDebug()<<"Baud: "<<m_tSerialParam.lBaudRate<<" "<<m_tSerialParam.strBaudRate;
}



/**
  * @brief 修改串口 数据位
  * @param
  * @retval
  */
void SerialConfig::on_comboBox_Data_currentIndexChanged(int index)
{
    //m_tSerialParam.dataBits = static_cast<QSerialPort::DataBits>(ui->comboBox_Data->itemData(ui->comboBox_Data->currentIndex()).toInt());
    m_tSerialParam.dataBits = static_cast<QSerialPort::DataBits>(index);
    m_tSerialParam.strDateBits =ui->comboBox_Data->currentText();
    qDebug()<<"DateBits: "<<m_tSerialParam.dataBits<<" "<<m_tSerialParam.strDateBits;
}



/**
  * @brief 修改串口，检验位
  * @param
  * @retval
  */
void SerialConfig::on_comboBox_Parity_currentIndexChanged(int index)
{
    //m_tSerialParam.parity = static_cast<QSerialPort::Parity>(ui->comboBox_Parity->itemData(ui->comboBox_Parity->currentIndex()).toInt());
    m_tSerialParam.parity = static_cast<QSerialPort::Parity>(index);
    m_tSerialParam.stringParity =ui->comboBox_Parity->currentText();
    qDebug()<<"Parity: "<<m_tSerialParam.parity<<" "<<m_tSerialParam.stringParity;
}



/**
  * @brief 修改串口，停止位
  * @param
  * @retval
  */
void SerialConfig::on_comboBox_StopBit_currentIndexChanged(int index)
{
    //m_tSerialParam.stopBits = static_cast<QSerialPort::StopBits>(ui->comboBox_StopBit->itemData(ui->comboBox_StopBit->currentIndex()).toInt());
    m_tSerialParam.stopBits = static_cast<QSerialPort::StopBits>(index);
    m_tSerialParam.stringStopBits =ui->comboBox_StopBit->currentText();
    qDebug()<<"stopBit: "<<m_tSerialParam.stopBits<<" "<<m_tSerialParam.stringStopBits;
}



/**
  * @brief 修改串口，流控
  * @param
  * @retval
  */
void SerialConfig::on_comboBox_FlowCtrl_currentIndexChanged(int index)
{
    //m_tSerialParam.flowControl = static_cast<QSerialPort::FlowControl>(ui->comboBox_FlowCtrl->itemData(ui->comboBox_FlowCtrl->currentIndex()).toInt());
    m_tSerialParam.flowControl = static_cast<QSerialPort::FlowControl>(index);
    m_tSerialParam.stringFlowControl =ui->comboBox_FlowCtrl->currentText();
    qDebug()<<"FlowCtrl: "<<m_tSerialParam.flowControl<<" "<<m_tSerialParam.stringFlowControl;
}



/**
  * @brief 打开串口
  * @param
  * @retval
  */
//void SerialConfig::on_pushButton_Open_clicked()
//{
//    m_ptSerialPort->setPortName(m_tSerialParam.strPortName);
//    m_ptSerialPort->setBaudRate(m_tSerialParam.lBaudRate);
//    m_ptSerialPort->setDataBits(m_tSerialParam.dataBits);
//    m_ptSerialPort->setParity(m_tSerialParam.parity);
//    m_ptSerialPort->setStopBits(m_tSerialParam.stopBits);
//    m_ptSerialPort->setFlowControl(m_tSerialParam.flowControl);

//    if (m_ptSerialPort->open(QIODevice::ReadWrite)) {

//        qDebug()<<"Open Serial Success";
//        ui->pushButton_Open->setEnabled(false);
//        ui->pushButton_Close->setEnabled(true);
//    } else {
//        QMessageBox::critical(this, tr("Error"), m_ptSerialPort->errorString());
//        ui->pushButton_Open->setEnabled(true);
//        ui->pushButton_Close->setEnabled(false);
//        qDebug()<<"Open Serial Failure";
//    }
//}



/**
  * @brief 关闭串口
  * @param
  * @retval
  */
//void SerialConfig::on_pushButton_Close_clicked()
//{
//    ui->pushButton_Open->setEnabled(true);
//    ui->pushButton_Close->setEnabled(false);
//}





/**
  * @brief  确定当前参数
  * @param
  * @retval
  */
void SerialConfig::on_pushButton_Sure_clicked()
{
    /* 更新串口数据 */
    //波特率
    uint32_t index = ui->comboBox_Baud->currentIndex();
    m_tSerialParam.lBaudRate = static_cast<QSerialPort::BaudRate>(index);
    m_tSerialParam.strBaudRate = QString::number(m_tSerialParam.lBaudRate);
    qDebug()<<"Baud: "<<m_tSerialParam.lBaudRate<<" "<<m_tSerialParam.strBaudRate;

    //数据位
    index = ui->comboBox_Data->currentIndex();
    m_tSerialParam.dataBits = static_cast<QSerialPort::DataBits>(index);
    m_tSerialParam.strDateBits =ui->comboBox_Data->currentText();
    qDebug()<<"DateBits: "<<m_tSerialParam.dataBits<<" "<<m_tSerialParam.strDateBits;

    //检验位
    index = ui->comboBox_Parity->currentIndex();
    m_tSerialParam.parity = static_cast<QSerialPort::Parity>(index);
    m_tSerialParam.stringParity =ui->comboBox_Parity->currentText();
    qDebug()<<"Parity: "<<m_tSerialParam.parity<<" "<<m_tSerialParam.stringParity;

    //停止位
    index = ui->comboBox_StopBit->currentIndex();
    m_tSerialParam.stopBits = static_cast<QSerialPort::StopBits>(index);
    m_tSerialParam.stringStopBits =ui->comboBox_StopBit->currentText();
    qDebug()<<"stopBit: "<<m_tSerialParam.stopBits<<" "<<m_tSerialParam.stringStopBits;

    //流控
    index = ui->comboBox_FlowCtrl->currentIndex();
    m_tSerialParam.flowControl = static_cast<QSerialPort::FlowControl>(index);
    m_tSerialParam.stringFlowControl =ui->comboBox_FlowCtrl->currentText();
    qDebug()<<"FlowCtrl: "<<m_tSerialParam.flowControl<<" "<<m_tSerialParam.stringFlowControl;


    /* 关闭窗口 */
    close();
}








