#ifndef WORKFLOW_TEMP_H
#define WORKFLOW_TEMP_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRect>
#include <QDebug>



#include "workflow.h"



class WorkFlow_Temp : public WorkFlow
{
 //   Q_OBJECT
public:
    WorkFlow_Temp(uint16_t usIndex = 0, float fTemp = 0, uint32_t ulTime = 0,
                  QVector<WorkFlow*> *ptWorkFlow = nullptr);


public:

    //更新显示
    void updateUI();

    //温度
    float temperature();
    float setTemperature(float fTemp);

    //时间
    uint32_t temperatureTime();
    uint32_t setTemperatureTime(uint32_t ulTime);


public:
    QGraphicsTextItem *m_ptItem_Temp;
    QGraphicsTextItem *m_ptItem_Time;
    QGraphicsLineItem *m_ptItem_Line0;
    QGraphicsLineItem *m_ptItem_Line1;
//    QGraphicsScene *m_ptScene;

    float    m_fTemp;
    uint32_t m_ulTime;


};

#endif // WORKFLOW_TEMP_H










