#ifndef SERIAL_PROTOCOLMSG_H
#define SERIAL_PROTOCOLMSG_H

#include <QObject>
#include <QMessageBox>
#include <QtSerialPort>
#include <QDebug>



class Serial_ProtocolMsg : public QObject
{
    Q_OBJECT
public:
    explicit Serial_ProtocolMsg(QObject *parent = nullptr);
    Serial_ProtocolMsg(QObject *parent = nullptr, QSerialPort *ptSerialPort = nullptr);

    //处理串口接受消息
    uint8_t Handle_Recv_Msg(QByteArray &tArr);




signals:


private:
    QSerialPort *m_ptSerialPort;        //串口设备指针

};

#endif // SERIAL_PROTOCOLMSG_H





