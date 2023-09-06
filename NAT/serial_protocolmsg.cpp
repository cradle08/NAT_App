#include "serial_protocolmsg.h"

Serial_ProtocolMsg::Serial_ProtocolMsg(QObject *parent)
    : QObject{parent}
{

}



Serial_ProtocolMsg::Serial_ProtocolMsg(QObject *parent, QSerialPort *ptSerialPort)
    : QObject(parent)
{

    m_ptSerialPort = ptSerialPort;
    //串口接受消息处理
//    connect(m_ptSerialPort, &QSerialPort::readyRead, this, &Serial_ProtocolMsg::on_Read_Serial_Data);

}




/**
  * @brief 处理串口接受消息
  * @param
  * @retval
  */
uint8_t Serial_ProtocolMsg::Handle_Recv_Msg(QByteArray &tArr)
{

}
