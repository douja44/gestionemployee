#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked() //bouton pour valider
{
Employes e; //creation de l'objet.

//recuration des informations saisie et par la suite les afficher
e.setcin(ui->lineEdit_cin->text()); // text()=methode de recupération.
e.setprenom(ui->lineEdit_prenom->text());
e.setnom(ui->lineEdit_nom->text());
e.setemail(ui->lineEdit_email->text());
e.setmdp(ui->lineEdit_mdp->text());
e.setid(ui->lineEdit_id->text());
e.setrole(ui->lineEdit_role->text());
e.setnumtel(ui->lineEdit_tel->text());
e.setsalaire(ui->lineEdit_salaire->text());
e.setdatemb(ui->lineEdit_datemb->text());

}


void MainWindow::on_pushButton_maj_clicked()
{
    QApplication::quit();
}



void MainWindow::on_pushButton_supp_clicked()
{
    QApplication::quit();
}
