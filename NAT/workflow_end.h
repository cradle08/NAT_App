#ifndef WORKFLOW_END_H
#define WORKFLOW_END_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>

#include "global_define.h"
#include "workflow.h"


class WorkFlow_End : public WorkFlow
{
public:
//    WorkFlow_End();
    explicit WorkFlow_End(uint16_t usIndex = 0,QVector<WorkFlow*> *ptWorkFlow = nullptr);
    ~WorkFlow_End();


public:
    QGraphicsTextItem *m_ptItem_Text;
//    QGraphicsScene *m_ptScene;


};

#endif // WORKFLOW_END_H
