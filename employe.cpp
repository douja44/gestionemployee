#include "employe.h"
#include<QString>
#include<QObject>
#include <iostream>
employe::employe()
{
    CIN=0;
    nom="";
    prenom="";
    salaire=0;
    dateE=0;
    numT=0;
    abs=0;
}
employe::employe(QString nom,QString prenom,int CIN,int abs,int dateE,int numT,int salaire)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->salaire=salaire;
    this->abs=abs;
    this->dateE=dateE;
    this->numT=numT;
}

bool employe::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence d'un employé avec le même CIN
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount > 0) {
        // L'employé avec ce CIN existe déjà, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé n'existe pas, insérez-le
    QString res1 = QString::number(dateE);
    QString res2= QString::number(numT);
    QString res3 = QString::number(salaire);
    QString res4 = QString::number(abs);

    query.prepare("INSERT INTO employe (CIN, nom, prenom, dateE, salaire, abs) VALUES (:CIN, :nom, :prenom, :dateE, :salaire, :abs)");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateE", res1);
    query.bindValue(":numT",res2);
    query.bindValue(":salaire", res3);
    query.bindValue(":abs", res4);

    return query.exec();
}


QSqlQueryModel *employe::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery ("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("numT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("abs"));
    return model;
}
bool employe::supprimer(int CIN)
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence de l'employé avec le CIN spécifié
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount == 0) {
        // L'employé avec ce CIN n'existe pas, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé existe, supprimez-le
    query.prepare("DELETE FROM employe WHERE CIN = :CIN");
    query.bindValue(":CIN", res);

    return query.exec();
}

bool employe::modifier(int CIN)
{
    QSqlQuery query;
    QString res = QString::number(CIN);

    // Vérification de l'existence de l'employé avec le CIN spécifié
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM employe WHERE CIN = :CIN");
    checkQuery.bindValue(":CIN", res);
    checkQuery.exec();
    checkQuery.next();

    int rowCount = checkQuery.value(0).toInt();

    if (rowCount == 0) {
        // L'employé avec ce CIN n'existe pas, vous pouvez gérer l'erreur ici
        // Par exemple, afficher un message d'erreur ou journaliser l'incident
        return false;
    }

    // Si l'employé existe, mettez à jour les données
    QString res1 = QString::number(dateE);
    QString res2= QString::number(numT);
    QString res3 = QString::number(salaire);
    QString res4 = QString::number(abs);

    query.prepare("UPDATE employe SET nom = :nom, prenom = :prenom,numT=:numT, salaire = :salaire, dateE = :dateE, abs = :abs WHERE CIN = :CIN");
    query.bindValue(":CIN", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateE", res1);
    query.bindValue(":numT",res2);
    query.bindValue(":salaire", res3);
    query.bindValue(":abs", res4);

    return query.exec();
}



