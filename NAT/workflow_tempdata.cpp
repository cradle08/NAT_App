#include "workflow_tempdata.h"

WorkFlow_TempData::WorkFlow_TempData(QGraphicsView *parent):QGraphicsView(parent)
{
    //温度
    m_ptItem_Temp = new QGraphicsTextItem();
    m_ptItem_Temp->setPlainText(QString("Temp"));

    //时间
    m_ptItem_Time = new QGraphicsTextItem();
    m_ptItem_Time->setPlainText(QString("00:00"));

    //线
    m_ptItem_Line0 = new QGraphicsLineItem();
    m_ptItem_Line1 = new QGraphicsLineItem();
    m_ptItem_Line0->setLine(-50, 50, 0, 0);
    m_ptItem_Line1->setLine(0, 0, 50, 50);

    m_ptItem_Pixmap = new QGraphicsPixmapItem();

    //设置属性
    Set_Item_Attribute(m_ptItem_Temp);
    Set_Item_Attribute(m_ptItem_Time);
    Set_Item_Attribute(m_ptItem_Line0);
    Set_Item_Attribute(m_ptItem_Line1);

    //场景
    m_ptScene = new QGraphicsScene(this);
    m_ptScene->addItem(m_ptItem_Temp);
    m_ptScene->addItem(m_ptItem_Time);
    m_ptScene->addItem(m_ptItem_Line0);
    m_ptScene->addItem(m_ptItem_Line1);
    setScene(m_ptScene);

}




/**
  * @brief 设置属性
  * @param
  * @retval
  */
void WorkFlow_TempData::Set_Item_Attribute(QGraphicsItem *ptItem)
{
    ptItem->setFlags(QGraphicsItem::ItemIsFocusable |
                     QGraphicsItem::ItemIsSelectable |
                     QGraphicsItem::ItemIsMovable);
}






