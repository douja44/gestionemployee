#ifndef LOGIN_H
#define LOGIN_H
#include "employe.h"
#include <QDialog>
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include <QMainWindow>
#include <QSqlError>
#include<QSqlQueryModel>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();
    void on_lineEdit_password_textChanged(const QString &text);






    void on_pushButton_oublier_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
