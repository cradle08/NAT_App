#ifndef WORKFLOW_START_H
#define WORKFLOW_START_H

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


//class Module_Start : public QGraphicsLayoutItem//, public QGraphicsItem
class WorkFlow_Start : public WorkFlow//, public QGraphicsItem
{

//    Q_OBJECT
public:
//    explicit Module_Start(QGraphicsView *parent = nullptr);
//    explicit Module_Start(QGraphicsItem *parent = nullptr);

    explicit WorkFlow_Start(uint16_t usIndex = 0,QVector<WorkFlow*> *ptWorkFlow = nullptr);

    //设置属性
    void Set_Item_Attribute(QGraphicsItem *ptItem);

//    // Inherited from QGraphicsLayoutItem
//    void setGeometry(const QRectF &geom) override;
//    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;


//    // Inherited from QGraphicsItem
//    QRectF boundingRect() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;


signals:


public:
    QGraphicsTextItem *m_ptItem_Text;
//    QGraphicsScene *m_ptScene;




};

#endif // WORKFLOW_START_H


