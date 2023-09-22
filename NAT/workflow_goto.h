#ifndef WORKFLOW_GOTO_H
#define WORKFLOW_GOTO_H


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



class WorkFlow_Goto : public QGraphicsView
{
public:
 //   WorkFlow_Goto();
    explicit WorkFlow_Goto(QGraphicsView *parent = nullptr);

    //设置属性
    void Set_Item_Attribute(QGraphicsItem *ptItem);



public:
    QGraphicsTextItem *m_ptItem_Text;
    QGraphicsTextItem *ptItem_GotoIndex;
    QGraphicsTextItem *ptItem_Count;
    QGraphicsScene *m_ptScene;

    uint16_t m_usGotoIndex; //跳转index
    uint32_t m_ulCount;     //循环次数
};

#endif // WORKFLOW_GOTO_H



