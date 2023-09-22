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



class WorkFlow_Temp : public QGraphicsView
{
 //   Q_OBJECT
public:
    WorkFlow_Temp(QGraphicsView *parent = nullptr);

    //设置属性
    void Set_Item_Attribute(QGraphicsItem *ptItem);

public:
    QGraphicsTextItem *m_ptItem_Temp;
    QGraphicsTextItem *m_ptItem_Time;
    QGraphicsLineItem *m_ptItem_Line0;
    QGraphicsLineItem *m_ptItem_Line1;
    QGraphicsScene *m_ptScene;


};

#endif // WORKFLOW_TEMP_H










