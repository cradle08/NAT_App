#include "workflow_temp.h"

#include "workflow_start.h"
#include "workflow_tempdata.h"
#include "workflow_goto.h"
#include "workflow_end.h"




WorkFlow_Temp::WorkFlow_Temp(uint16_t usIndex, float fTemp, uint32_t ulTime, QVector<WorkFlow*> *ptWorkFlow)
    : WorkFlow(WORKFLOW_TYPE_Temp, usIndex, ptWorkFlow, nullptr)
{
    //
    m_fTemp =fTemp;
    m_ulTime = ulTime;


    //属性,关闭自动滑条
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //温度
    m_ptItem_Temp = new QGraphicsTextItem();
//    m_ptItem_Temp->setPlainText(QString::asprintf("%0.1f", m_fTemp));

    //时间
    m_ptItem_Time = new QGraphicsTextItem();
//    m_ptItem_Time->setPlainText(QString("%1:%2").arg(m_ulTime/60).arg(m_ulTime%60));

    //线
    m_ptItem_Line0 = new QGraphicsLineItem();
    m_ptItem_Line1 = new QGraphicsLineItem();
//    m_ptItem_Line0->setLine(-50, 50, 0, 0);
//    m_ptItem_Line1->setLine(0, 0, 50, 50);

    //设置属性
    setItemAttribute(m_ptItem_Temp);
    setItemAttribute(m_ptItem_Time);
    setItemAttribute(m_ptItem_Line0);
    setItemAttribute(m_ptItem_Line1);

    //场景
 //   m_ptScene = new QGraphicsScene(this);
    m_ptScene->addItem(m_ptItem_Temp);
    m_ptScene->addItem(m_ptItem_Time);
    m_ptScene->addItem(m_ptItem_Line0);
    m_ptScene->addItem(m_ptItem_Line1);
    setScene(m_ptScene);

    //刷新
    updateUI();
}



/**
  * @brief 设置属性
  * @param
  * @retval
  */
void WorkFlow_Temp::updateUI()
{
    qDebug()<<this->width()<<" "<<height()<<"TTE";

    float fLastTemp = 0;
    uint8_t ucLineFlag = 0; //0:直线， 1：上升斜线， 2：下降斜线
    if(m_usIndex == 0)
    {
        ucLineFlag = 1;
    }else{
        WorkFlow_Type_e eLastType = m_ptWorkFlow->at(m_usIndex - 1)->workFlowType();
        switch(eLastType)
        {
            case WORKFLOW_TYPE_Start:
            {
                ucLineFlag = 1;
            }
            break;
            case WORKFLOW_TYPE_Temp:
            {
                WorkFlow_Temp *ptFlow = dynamic_cast<WorkFlow_Temp*>(m_ptWorkFlow->at(m_usIndex - 1));
                fLastTemp = ptFlow->temperature();
                if(fLastTemp > m_fTemp)
                {
                    ucLineFlag = 2;
                }if(fLastTemp < m_fTemp){
                    ucLineFlag = 1;
                }else{
                    ucLineFlag = 0;
                }
            }
            break;
            case WORKFLOW_TYPE_TempData:
            {
                WorkFlow_TempData *ptFlow = dynamic_cast<WorkFlow_TempData*>(m_ptWorkFlow->at(m_usIndex - 1));
                fLastTemp = ptFlow->temperature();
                if(fLastTemp > m_fTemp)
                {
                    ucLineFlag = 2;
                }if(fLastTemp < m_fTemp){
                    ucLineFlag = 1;
                }else{
                    ucLineFlag = 0;
                }
            }
            break;
            case WORKFLOW_TYPE_Goto:
                ucLineFlag = 0;
                break;
            case WORKFLOW_TYPE_End:
                return;
                break;
            case WORKFLOW_TYPE_END:
                return;
                break;
        }
    }

    /* 划线  0:直线， 1：上升斜线， 2：下降斜线 */
    QPointF tPoint0, tPoint1, tPoint2;
    if(0 == ucLineFlag)
    {



    }else if(1 == ucLineFlag){
        tPoint0.rx() = 0;
        tPoint0.ry() = fLastTemp*height()/MAX_TEMPERATURE_VALUE;

        tPoint1.rx() = width()/4;
        tPoint0.ry() = temperature()*height()/MAX_TEMPERATURE_VALUE;

        tPoint1.rx() = width();
        tPoint0.ry() = temperature()*height()/MAX_TEMPERATURE_VALUE;

        QLineF tLine0(tPoint0, tPoint1);
        QLineF tLine1(tPoint1, tPoint2);
        m_ptItem_Line0->setLine(tLine0);
        m_ptItem_Line1->setLine(tLine1);

    }if(2 == ucLineFlag){

    }else{

    }

    m_ptItem_Temp->setPlainText(QString::asprintf("%0.1f", m_fTemp));
    m_ptItem_Time->setPlainText(QString("%1:%2").arg(m_ulTime/60>60?60:m_ulTime/60).arg(m_ulTime%60));
    m_ptItem_Line0->setLine(-50, 50, 0, 0);
    m_ptItem_Line1->setLine(0, 0, 50, 50);

}







/**
  * @brief 获取温度
  * @param
  * @retval
  */
float WorkFlow_Temp::temperature()
{
    return m_fTemp;
}


/**
  * @brief 设置温度
  * @param
  * @retval
  */
float WorkFlow_Temp::setTemperature(float fTemp)
{
    if(fTemp > MAX_TEMPERATURE_VALUE) fTemp = MAX_TEMPERATURE_VALUE;
    m_fTemp = fTemp;
    return m_fTemp;
}


/**
  * @brief 获取时间
  * @param
  * @retval
  */
uint32_t WorkFlow_Temp::temperatureTime()
{
    return m_ulTime;
}



/**
  * @brief 设置时间
  * @param
  * @retval
  */
uint32_t WorkFlow_Temp::setTemperatureTime(uint32_t ulTime)
{
    m_ulTime = ulTime;
    return m_ulTime;
}














