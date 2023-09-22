#include "workflow_goto.h"


WorkFlow_Goto::WorkFlow_Goto(QGraphicsView *parent): QGraphicsView{parent}
{
    m_ptScene = new QGraphicsScene(this);

    //GOTO
    m_ptItem_Text = new QGraphicsTextItem();
    m_ptItem_Text->setPlainText(QString("GOTO"));
    Set_Item_Attribute(m_ptItem_Text);

    m_usGotoIndex = 2;
    ptItem_GotoIndex = new QGraphicsTextItem(QString("%1").arg(m_usGotoIndex));
    Set_Item_Attribute(ptItem_GotoIndex);

    m_ulCount = 40;
    ptItem_Count = new QGraphicsTextItem(QString("%1").arg(m_ulCount));
    Set_Item_Attribute(ptItem_Count);

    m_ptScene->addItem(m_ptItem_Text);
    m_ptScene->addItem(ptItem_GotoIndex);
    m_ptScene->addItem(ptItem_Count);
    setScene(m_ptScene);


}


/**
  * @brief 设置属性
  * @param
  * @retval
  */
void WorkFlow_Goto::Set_Item_Attribute(QGraphicsItem *ptItem)
{
    ptItem->setFlags(QGraphicsItem::ItemIsFocusable |
                     QGraphicsItem::ItemIsSelectable |
                     QGraphicsItem::ItemIsMovable);
}

