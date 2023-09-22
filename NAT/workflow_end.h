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



class WorkFlow_End : public QGraphicsView
{
public:
//    WorkFlow_End();
    explicit WorkFlow_End(QGraphicsView *parent = nullptr);

    //设置属性
    void Set_Item_Attribute(QGraphicsItem *ptItem);



public:
    QGraphicsTextItem *m_ptItem_Text;
    QGraphicsScene *m_ptScene;


};

#endif // WORKFLOW_END_H
