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
    QString res= QString::number(CIN);
    QString res1= QString::number(dateE);
    QString res2= QString::number(numT);
    QString res3= QString::number(salaire);
    QString res4= QString::number(abs);
    query.prepare("insert into employe(CIN, nom, prenom, dateE, numT, salaire, abs)""values(:CIN, :nom, :prenom, :dateE, :numT, :salaire, :abs)");
    query.bindValue(":CIN",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":dateE",res1);
    query.bindValue(":numT",res2);
    query.bindValue(":salaire",res3);
    query.bindValue(":abs",res4);
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
    QString res=QString::number(CIN) ;
    query.prepare("Delete from employe where CIN= :CIN");
    query.bindValue (":CIN", res);
    return query.exec () ;
}
