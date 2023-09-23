#include "workflow.h"
#include "qgraphicsitem.h"

//WorkFlow::WorkFlow(QGraphicsView *parent= nullptr): QGraphicsView{parent}
//{

//}


WorkFlow::WorkFlow(WorkFlow_Type_e eWorkFlow_Type, uint16_t usIndex,
         QVector<WorkFlow*> *ptWorkFlow,
         QGraphicsView *parent): QGraphicsView{parent}
{
    m_usIndex = usIndex;
    m_eWorkFlow_Type = eWorkFlow_Type;
    m_ptWorkFlow = ptWorkFlow;

    m_ptScene = new QGraphicsScene(this);
}



WorkFlow::~WorkFlow()
{
    if(nullptr != m_ptScene) delete m_ptScene;
}




/**
  * @brief 设置属性
  * @param
  * @retval
  */
void WorkFlow::setItemAttribute(QGraphicsItem *ptItem)
{
    ptItem->setFlags(QGraphicsItem::ItemIsFocusable |
                     QGraphicsItem::ItemIsSelectable |
                     QGraphicsItem::ItemIsMovable);
}



/**
  * @brief 流程号
  * @param
  * @retval
  */
uint16_t WorkFlow::index()
{
    return m_usIndex;
}



/**
  * @brief 设置流程号
  * @param
  * @retval
  */
uint16_t WorkFlow::setIndex(uint16_t usIndex)
{
    m_usIndex = usIndex;
    return m_usIndex;
}



/**
  * @brief 获取流程类型
  * @param
  * @retval
  */
WorkFlow_Type_e WorkFlow::workFlowType()
{
    return m_eWorkFlow_Type;
}










