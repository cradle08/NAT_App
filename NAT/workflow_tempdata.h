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



class WorkFlow_TempData : public QGraphicsView
{
public:
    WorkFlow_TempData(QGraphicsView *parent = nullptr);

    //设置属性
    void Set_Item_Attribute(QGraphicsItem *ptItem);

public:
    QGraphicsTextItem *m_ptItem_Temp;
    QGraphicsTextItem *m_ptItem_Time;
    QGraphicsLineItem *m_ptItem_Line0;
    QGraphicsLineItem *m_ptItem_Line1;
    QGraphicsPixmapItem *m_ptItem_Pixmap;
    QGraphicsScene *m_ptScene;


};

#endif // WORKFLOW_TEMPDATA_H
