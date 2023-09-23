#ifndef WORKFLOW_H
#define WORKFLOW_H

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


#include "global_define.h"



class WorkFlow : public QGraphicsView
{
public:
    WorkFlow(WorkFlow_Type_e eWorkFlow_Type = WORKFLOW_TYPE_END,
             uint16_t usIndex = 0,
             QVector<WorkFlow*> *ptWorkFlow = nullptr,
             QGraphicsView *parent= nullptr);

    ~WorkFlow();

    //设置属性
    void setItemAttribute(QGraphicsItem *ptItem);

    //流程号
    uint16_t index();
    uint16_t setIndex(uint16_t usIndex);

    //获取流程类型
    WorkFlow_Type_e workFlowType();


public:
    QGraphicsScene *m_ptScene;

    uint16_t m_usIndex;
    WorkFlow_Type_e m_eWorkFlow_Type;
    QVector<WorkFlow*> *m_ptWorkFlow;

};

#endif // WORKFLOW_H



