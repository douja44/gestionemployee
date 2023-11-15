#include "ui_login.h"
#include "login.h"
#include "mainwindow.h"
#include "employe.h"
#include <QMainWindow>
#include <QMessageBox>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    connect(ui->lineEdit_password, &QLineEdit::textChanged, this, &login::on_lineEdit_password_textChanged);

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    employe e;
    QString CIN = ui->lineEdit_username->text();
    QString mdp = ui->lineEdit_password->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE CIN=:CIN");
    query.bindValue(":CIN",CIN);

    if (query.exec() && query.next() && mdp=="smartdelivery") {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("login avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        this->hide();
        MainWindow *auth = new MainWindow;
        auth->show();

    } else {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" please enter valid id or password.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void login::on_lineEdit_password_textChanged(const QString &text)
{
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}
