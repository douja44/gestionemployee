#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employe
{

public:
    employe();
    employe(QString,QString,int,int,int,int,int);


    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int getcin(){return CIN;}
    int getsalaire(){return salaire;}
    int getdateE(){return dateE;}
    int getnumT(){return numT;}
    int getabs(){return abs;}
    void setcin(int nvcin){CIN=nvcin;}
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setsalaire(int s){salaire=s;}
    void setdateE(int d){dateE=d;}
    void setnumT(int num){numT=num;}
    void setabs(int a){abs=a;}
    QString nom,prenom;
    int CIN,salaire,dateE,numT,abs;



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);

    void exportToPDF();


    
    
};

#endif // EMPLOYE_H
