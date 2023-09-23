#include "workflow_start.h"


//Module_Start::Module_Start(QGraphicsItem *parent)
//    : QGraphicsLayoutItem(), QGraphicsTextItem(parent)
//{

//    //    setPlainText(QString("START"));

//}


WorkFlow_Start::WorkFlow_Start(uint16_t usIndex,QVector<WorkFlow*> *ptWorkFlow)
    : WorkFlow(WORKFLOW_TYPE_Start, usIndex, ptWorkFlow, nullptr)
{
//    m_ptScene = new QGraphicsScene(this);
    //开始
    m_ptItem_Text = new QGraphicsTextItem();
    m_ptItem_Text->setPlainText(QString("START"));
    m_ptItem_Text->setFlags(QGraphicsItem::ItemIsFocusable |
             QGraphicsItem::ItemIsSelectable |
             QGraphicsItem::ItemIsMovable);

    m_ptScene->addItem(m_ptItem_Text);
    setScene(m_ptScene);

}

