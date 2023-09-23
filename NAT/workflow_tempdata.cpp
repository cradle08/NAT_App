#include "workflow_tempdata.h"


WorkFlow_TempData::WorkFlow_TempData(uint16_t usIndex, float fTemp, uint32_t ulTime,
                QVector<WorkFlow*> *ptWorkFlow)
        : WorkFlow(WORKFLOW_TYPE_TempData, usIndex, ptWorkFlow, nullptr)
{
    //属性
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //温度
    m_ptItem_Temp = new QGraphicsTextItem();
    m_ptItem_Temp->setPlainText(QString("Temp"));

    //时间
    m_ptItem_Time = new QGraphicsTextItem();
    m_ptItem_Time->setPlainText(QString("00:00"));

    //线
    m_ptItem_Line0 = new QGraphicsLineItem();
    m_ptItem_Line1 = new QGraphicsLineItem();
    m_ptItem_Line0->setLine(-50, 50, 0, 0);
    m_ptItem_Line1->setLine(0, 0, 50, 50);

    m_ptItem_Pixmap = new QGraphicsPixmapItem();

    //设置属性
    setItemAttribute(m_ptItem_Temp);
    setItemAttribute(m_ptItem_Time);
    setItemAttribute(m_ptItem_Line0);
    setItemAttribute(m_ptItem_Line1);

    //场景
//    m_ptScene = new QGraphicsScene(this);
    m_ptScene->addItem(m_ptItem_Temp);
    m_ptScene->addItem(m_ptItem_Time);
    m_ptScene->addItem(m_ptItem_Line0);
    m_ptScene->addItem(m_ptItem_Line1);
    setScene(m_ptScene);

}





/**
  * @brief 获取温度
  * @param
  * @retval
  */
float WorkFlow_TempData::temperature()
{
    return m_fTemp;
}


/**
  * @brief 设置温度
  * @param
  * @retval
  */
float WorkFlow_TempData::setTemperature(float fTemp)
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
uint32_t WorkFlow_TempData::temperatureTime()
{
    return m_ulTime;
}



/**
  * @brief 设置时间
  * @param
  * @retval
  */
uint32_t WorkFlow_TempData::setTemperatureTime(uint32_t ulTime)
{
    if(ulTime > MAX_TEMPERATURE_TIME) ulTime = MAX_TEMPERATURE_TIME;
    m_ulTime = ulTime;
    return m_ulTime;
}





