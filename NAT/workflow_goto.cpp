#include "workflow_goto.h"





WorkFlow_Goto::WorkFlow_Goto(uint16_t usIndex,QVector<WorkFlow*> *ptWorkFlow)
    : WorkFlow(WORKFLOW_TYPE_Goto, usIndex, ptWorkFlow, nullptr)
{
//    m_ptScene = new QGraphicsScene(this);

    //GOTO
    m_ptItem_Text = new QGraphicsTextItem();
    m_ptItem_Text->setPlainText(QString("GOTO"));
    setItemAttribute(m_ptItem_Text);

    m_usGotoIndex = 2;
    ptItem_GotoIndex = new QGraphicsTextItem(QString("%1").arg(m_usGotoIndex));
    setItemAttribute(ptItem_GotoIndex);

    m_ulCount = 40;
    ptItem_Count = new QGraphicsTextItem(QString("%1").arg(m_ulCount));
    setItemAttribute(ptItem_Count);

    m_ptScene->addItem(m_ptItem_Text);
    m_ptScene->addItem(ptItem_GotoIndex);
    m_ptScene->addItem(ptItem_Count);
    setScene(m_ptScene);


}











