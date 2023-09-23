#ifndef WORKFLOW_TEMPDATA_H
#define WORKFLOW_TEMPDATA_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "global_define.h"
#include "workflow.h"



class WorkFlow_TempData : public WorkFlow
{
public:
//    WorkFlow_TempData(QGraphicsView *parent = nullptr);
    WorkFlow_TempData(uint16_t usIndex = 0, float fTemp = 0, uint32_t ulTime = 0,
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
    QGraphicsPixmapItem *m_ptItem_Pixmap;
 //   QGraphicsScene *m_ptScene;

    float    m_fTemp;
    uint32_t m_ulTime;


};

#endif // WORKFLOW_TEMPDATA_H







