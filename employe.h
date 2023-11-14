#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QTableView>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employe
{

public:
    employe();
    employe(QString,QString,int,int,QDate,int,int);

    QDate dateE;

    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getcin(){return CIN;}
    int getsalaire(){return salaire;}
    QDate getdateE(){return dateE;}
    int getnumT(){return numT;}
    int getabs(){return abs;}
    void setcin(int nvcin){CIN=nvcin;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setsalaire(int s){salaire=s;}
    void setdateE(QDate d){dateE=d;}
    void setnumT(int num){numT=num;}
    void setabs(int a){abs=a;}
    QString nom,prenom;
    int CIN,salaire,numT,abs;




    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);



    QSqlQueryModel* trierParSalaire();
    QSqlQueryModel* trierParDateEmbauche();
    void rechercher(QTableView *tableView, int CIN);


    
};

#endif // EMPLOYE_H
