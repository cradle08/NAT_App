#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_Login_clicked();


public:
    MainWindow *m_ptMainWindow;

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
