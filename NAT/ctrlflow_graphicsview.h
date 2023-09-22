#ifndef CTRLFLOW_GRAPHICSVIEW_H
#define CTRLFLOW_GRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsPathItem>
#include <QGraphicsLayout>
#include <QVector>
#include <QGraphicsProxyWidget>

#include <QtWidgets>



class CtrlFlow_GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CtrlFlow_GraphicsView(QWidget *parent = nullptr);
    ~CtrlFlow_GraphicsView();

    //设置默认执行流程
    void Set_Dedefault_CtrlFlow();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void MouseMovePoint(QPoint tPoint);
    void MousePressPoint(QPoint tPoint);


private:
    QGraphicsScene *m_ptScene;
    QGraphicsWidget *m_ptSceneWidget;
    QGraphicsLinearLayout *m_ptLayout;

//    QVector<QGraphicsItemGroup *> m_tVector_Item;
//    QGraphicsScene *m_ptScene_2;


};


#endif // CTRLFLOW_GRAPHICSVIEW_H







