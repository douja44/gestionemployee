#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTextDocument>
#include <QTextCursor>
using namespace std;
#include"employe.h"
#include"connection.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_cinsupp->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_abs->setValidator(new QIntValidator(0,999,this));
    ui->lineEdit_numT->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_dateE->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_salaire->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_nom->setMaxLength(8);
    ui->lineEdit_nom->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z_]{1,8}$"), this));
    ui->lineEdit_prenom->setMaxLength(8);
    ui->lineEdit_prenom->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z_]{1,8}$"), this));



}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int CIN=ui->lineEdit_cin->text().toInt();
    int abs=ui->lineEdit_abs->text().toInt();
    int dateE=ui->lineEdit_dateE->text().toInt();
    int numT=ui->lineEdit_numT->text().toInt();
    int salaire=ui->lineEdit_salaire->text().toInt();

    employe e(nom,prenom,CIN,abs,dateE,numT,salaire);

    bool test=e.ajouter();
    if (test){


        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{
    employe e;
    int CIN=ui->lineEdit_cinsupp->text().toInt();
    bool test=e.supprimer(CIN);

    if (test){
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tableView->setModel(e.afficher());
}



void MainWindow::on_pushButton_modifier_clicked()
{
    qDebug();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int CIN=ui->lineEdit_cin->text().toInt();
    int abs=ui->lineEdit_abs->text().toInt();
    int dateE=ui->lineEdit_dateE->text().toInt();
    int numT=ui->lineEdit_numT->text().toInt();
    int salaire=ui->lineEdit_salaire->text().toInt();

    employe e(nom,prenom,CIN,abs,dateE,numT,salaire);

    bool test=e.modifier(CIN);
    if (test){


        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("modifier avec success.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr(" modifier non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_pdf_clicked()
{

}
