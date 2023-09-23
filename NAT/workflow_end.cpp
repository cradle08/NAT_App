#include "workflow_end.h"

//WorkFlow_End::WorkFlow_End()
//{

//}


//WorkFlow_End::WorkFlow_End(QGraphicsView *parent): QGraphicsView{parent}
//{

//}


WorkFlow_End::WorkFlow_End(uint16_t usIndex, QVector<WorkFlow*> *ptWorkFlow)
    : WorkFlow(WORKFLOW_TYPE_End, usIndex, ptWorkFlow, nullptr)
{
//    m_ptScene = new QGraphicsScene(this);
    //END
    m_ptItem_Text = new QGraphicsTextItem();
    m_ptItem_Text->setPlainText(QString("END"));
//    m_ptItem_Text->setFlags(QGraphicsItem::ItemIsFocusable |
//                            QGraphicsItem::ItemIsSelectable |
//                            QGraphicsItem::ItemIsMovable);

    m_ptScene->addItem(m_ptItem_Text);
    setScene(m_ptScene);


}



 WorkFlow_End::~WorkFlow_End()
{


 }











