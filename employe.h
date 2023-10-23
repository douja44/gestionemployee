#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>


class Employes
{
public:
    void setcin(QString n);
    void setprenom(QString n);
    void setnom(QString n);
    void setemail(QString n);
    void setmdp(QString n);
    void setnumtel(QString n);
    void setsalaire(QString n);
    void setrole(QString n);
    void setid(QString n);
    void setdatemb(QString n);
    QString get_cin();
    QString get_prenom();
    QString get_nom();
    QString get_email();
    QString get_mdp();
    QString get_numtel();
    QString get_salaire();
    QString get_role();
    QString get_id();
    QString get_datemb();

    Employes();
private:
    QString cin, prenom, nom, email, mdp, numtel, salaire, role, id,datemb;
};

#endif // EMPLOYES_H
