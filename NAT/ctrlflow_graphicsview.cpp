#include "ctrlflow_graphicsview.h"

#include "workflow_start.h"
#include "workflow_temp.h"



/**
  * @brief
  * @param
  * @retval
  */
CtrlFlow_GraphicsView::CtrlFlow_GraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
 //   QGraphicsTextItem
//   QGraphicsItem
    //
    //setDragMode(QGraphicsView::ScrollHandDrag);
 //   setDragMode(QGraphicsView::RubberBandDrag);

    //Scene
    QRectF tRect = rect();
    qDebug()<<tRect.x()<<" " <<tRect.y();
    m_ptScene = new QGraphicsScene(tRect, this);
    //m_ptScene = new QGraphicsScene(0, 0, 200, 200, this);
 //   m_ptScene_2 = new QGraphicsScene(201, 0, 200, 200, this);


    //Scene Widget
    m_ptSceneWidget = new QGraphicsWidget();
    //m_ptSceneWidget->setGeometry(tRect);

    //Scene Widget Layout
    m_ptLayout = new QGraphicsLinearLayout(Qt::Horizontal);
    m_ptSceneWidget->setLayout(m_ptLayout);


    //Set_Dedefault_CtrlFlow();
//    Module_Start *ptStart0 = new Module_Start();
//    QGraphicsProxyWidget *ptStart00 = new QGraphicsProxyWidget(ptStart0);
//    m_ptLayout->addItem(ptStart00);

 //   Module_Temp *ptModule_Temp = new Module_Temp();
//    m_ptLayout->addItem(ptModule_Start);
//    m_ptLayout->addItem(ptModule_Temp);

    QGraphicsProxyWidget *ptStart = new QGraphicsProxyWidget;
    ptStart->setWidget(new QPushButton(QString("TTT")));
    m_ptLayout->addItem(ptStart);

    QGraphicsProxyWidget *ptStart1 = new QGraphicsProxyWidget;
    ptStart1->setWidget(new QPushButton(QString("SSS")));
    m_ptLayout->addItem(ptStart1);

    QGraphicsProxyWidget *ptStart2 = new QGraphicsProxyWidget;
    ptStart2->setWidget(new QPushButton(QString("GGG")));
    m_ptLayout->addItem(ptStart2);


#if 0
    Module_Start *ptItem_Start = new Module_Start();
    ptItem_Start->setFlags(QGraphicsItem::ItemIsFocusable |
                            QGraphicsItem::ItemIsSelectable |
                            QGraphicsItem::ItemIsMovable);

    ptItem_Start->setPlainText(QString("START"));

    //
    Module_Start *ptItem_Start2 = new Module_Start();
    //    QGraphicsTextItem *ptItem_Start = new QGraphicsTextItem();
    ptItem_Start2->setFlags(QGraphicsItem::ItemIsFocusable |
                           QGraphicsItem::ItemIsSelectable |
                           QGraphicsItem::ItemIsMovable);

    ptItem_Start2->setPlainText(QString("START2"));
    m_ptScene->addItem(ptItem_Start);
    m_ptScene->addItem(ptItem_Start2);

#else

 //   m_ptLayout = new QGraphicsLinearLayout(Qt::Vertical);

//    Module_Start *ptItem_Start = new Module_Start();
//    ptItem_Start->setFlags(QGraphicsItem::ItemIsFocusable |
//                           QGraphicsItem::ItemIsSelectable |
//                           QGraphicsItem::ItemIsMovable);

//    ptItem_Start->setPlainText(QString("START"));

    //    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(m_ptSceneWidget);
    //    proxy->setWidget(ptItem_Start);

 //   m_ptLayout->addItem(ptItem_Start);
    //    m_ptLayout->setStretchFactor(ptItem_Start, 1);
    //m_ptSceneWidget->setLayout(m_ptLayout);
    //m_ptScene->addItem(m_ptSceneWidget);
//    ptItem_Start->setPos(-10////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////0, 0);
//    qDebug()<<"GGG:"<<ptItem_Start->x()<<" "<<ptItem_Start->y()
//    Module_Temp *ptItem_Temp = new Module_Temp();
//    ptItem_Temp->setFlags(QGraphicsItem::ItemIsFocusable |
//                           QGraphicsItem::ItemIsSelectable |
//                           QGraphicsItem::ItemIsMovable);
//    m_ptScene->addItem(ptItem_Temp);
//    m_ptScene->addItem(ptItem_Start);


#endif


    //
    //m_ptScene->addItem(m_ptSceneWidget);

 //   m_ptScene->addItem(m_ptSceneWidget);
    m_ptScene->addItem(m_ptSceneWidget);
    setScene(m_ptScene);
 //   setScene(m_ptScene_2);


}



/**
  * @brief
  * @param
  * @retval
  */
CtrlFlow_GraphicsView::~CtrlFlow_GraphicsView()
{
    if(nullptr != m_ptScene) delete m_ptScene;

}



/**
  * @brief
  * @param
  * @retval
  */
void CtrlFlow_GraphicsView::Set_Dedefault_CtrlFlow()
{
//    /*** Group 1 ***/
//    QGraphicsItemGroup *ptItemGroup_1 = new QGraphicsItemGroup();
//    ptItemGroup_1->setFlags(QGraphicsItem::ItemIsFocusable |
//                            QGraphicsItem::ItemIsSelectable |
//                            QGraphicsItem::ItemIsMovable);
//    //Line
//    QGraphicsLineItem *ptLineItem = new QGraphicsLineItem();
//    ptLineItem->setLine(-10, 50, 10, 50);
//    ptLineItem->setFlags(QGraphicsItem::ItemIsFocusable |
//                         QGraphicsItem::ItemIsSelectable |
//                         QGraphicsItem::ItemIsMovable);
//    QPen tPen(Qt::blue);
//    tPen.setWidth(3);
//    ptLineItem->setPen(tPen);
//    //ptLineItem->setItem(1, 5);
//    ptItemGroup_1->addToGroup(ptLineItem);

//    //将Group添加道Scene中
//    m_ptScene->addItem(ptItemGroup_1);

//    /*** Group 2 ***/
//    QGraphicsItemGroup *ptItemGroup_2 = new QGraphicsItemGroup();
//    ptItemGroup_2->setFlags(QGraphicsItem::ItemIsFocusable |
//                            QGraphicsItem::ItemIsSelectable |
//                            QGraphicsItem::ItemIsMovable);
//    //Line
//    ptLineItem = new QGraphicsLineItem();
//    ptLineItem->setLine(0, 10, 0, -10);
//    ptLineItem->setFlags(QGraphicsItem::ItemIsFocusable |
//                         QGraphicsItem::ItemIsSelectable |
//                         QGraphicsItem::ItemIsMovable);
//    QPen tPen_2(Qt::blue);
//    tPen_2.setWidth(3);
//    ptLineItem->setPen(tPen_2);
//    //ptLineItem->setItem(1, 5);
//    ptItemGroup_2->addToGroup(ptLineItem);

//    //将Group添加道Scene中
//    m_ptScene->addItem(ptItemGroup_2);

 //   Module_Start *ptItem = new Module_Start(this);
 //   m_ptLayout->addItem(ptItem);




#if 0
    Module_Start *ptItem_Start = new Module_Start();
    ptItem_Start->setFlags(QGraphicsItem::ItemIsFocusable |
                            QGraphicsItem::ItemIsSelectable |
                            QGraphicsItem::ItemIsMovable);

    ptItem_Start->setPlainText(QString("START"));

    //
    Module_Start *ptItem_Start2 = new Module_Start();
    //    QGraphicsTextItem *ptItem_Start = new QGraphicsTextItem();
    ptItem_Start2->setFlags(QGraphicsItem::ItemIsFocusable |
                           QGraphicsItem::ItemIsSelectable |
                           QGraphicsItem::ItemIsMovable);

    ptItem_Start2->setPlainText(QString("START2"));
    m_ptScene->addItem(ptItem_Start);
    m_ptScene->addItem(ptItem_Start2);

#else

//    m_ptLayout = new QGraphicsLinearLayout(Qt::Horizontal);

//    Module_Start *ptItem_Start = new Module_Start();
//    ptItem_Start->setFlags(QGraphicsItem::ItemIsFocusable |
//                           QGraphicsItem::ItemIsSelectable |
//                           QGraphicsItem::ItemIsMovable);

//    ptItem_Start->setPlainText(QString("START"));

////    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(m_ptSceneWidget);
////    proxy->setWidget(ptItem_Start);

//    m_ptLayout->addItem(ptItem_Start);
////    m_ptLayout->setStretchFactor(ptItem_Start, 1);
//    m_ptSceneWidget->setLayout(m_ptLayout);
//    m_ptScene->addItem(m_ptSceneWidget);


#endif

    //m_ptSceneWidget->a

  //  m_tVector_Item.append(ptGroup);
 //   m_ptLayout->in

 //   m_ptSceneWidget->setLayout(m_ptLayout);


//        Module_Start *ptModule_Start = new Module_Start();
//        Module_Temp *ptModule_Temp = new Module_Temp();


}




/**
  * @brief
  * @param
  * @retval
  */
void CtrlFlow_GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint tPoint = event->pos();
    emit MouseMovePoint(tPoint);
    QGraphicsView::mouseMoveEvent(event);
}





/**
  * @brief
  * @param
  * @retval
  */
void CtrlFlow_GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        QPoint  tPoint = event->pos();
        emit MousePressPoint(tPoint);
    }
    QGraphicsView::mousePressEvent(event);
}







