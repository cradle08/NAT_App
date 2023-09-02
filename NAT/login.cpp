#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    m_ptMainWindow = new MainWindow(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_Login_clicked()
{
    close();
    m_ptMainWindow->show();
    //m_ptMainWindow->exec();


}

