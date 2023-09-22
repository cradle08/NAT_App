#include "workflow_end.h"

//WorkFlow_End::WorkFlow_End()
//{

//}



WorkFlow_End::WorkFlow_End(QGraphicsView *parent): QGraphicsView{parent}
{
    m_ptScene = new QGraphicsScene(this);
    //END
    m_ptItem_Text = new QGraphicsTextItem();
    m_ptItem_Text->setPlainText(QString("END"));
    m_ptItem_Text->setFlags(QGraphicsItem::ItemIsFocusable |
                            QGraphicsItem::ItemIsSelectable |
                            QGraphicsItem::ItemIsMovable);

    m_ptScene->addItem(m_ptItem_Text);
    setScene(m_ptScene);
}



/**
  * @brief 设置属性
  * @param
  * @retval
  */
void WorkFlow_End::Set_Item_Attribute(QGraphicsItem *ptItem)
{
    ptItem->setFlags(QGraphicsItem::ItemIsFocusable |
                     QGraphicsItem::ItemIsSelectable |
                     QGraphicsItem::ItemIsMovable);
}





