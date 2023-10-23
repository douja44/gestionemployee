#include "employe.h"

Employes::Employes() //pour initialiser les variable private
{
cin="";
prenom="";
nom="";
email="";
mdp="";
numtel="";
salaire="";
role="";
id="";
}

void Employes::setcin(QString n){cin=n;}
void Employes::setprenom(QString n){prenom=n;}
void Employes::setnom(QString n){nom=n;}
void Employes::setmdp(QString n){mdp=n;}
void Employes::setid(QString n){id=n;}
void Employes::setrole(QString n){role=n;}
void Employes::setnumtel(QString n){numtel=n;}
void Employes::setemail(QString n){email=n;}
void Employes::setsalaire(QString n){salaire=n;}
void Employes::setdatemb(QString n){datemb=n;}

QString Employes::get_cin(){return cin;}
QString Employes::get_prenom(){return prenom;}
QString Employes::get_nom(){return nom;}
QString Employes::get_email(){return email;}
QString Employes::get_mdp(){return mdp;}
QString Employes::get_numtel(){return numtel;}
QString Employes::get_salaire(){return salaire;}
QString Employes::get_role(){return role;}
QString Employes::get_id(){return id;}
QString Employes::get_datemb(){return datemb;}





