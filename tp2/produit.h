#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <ostream>

using namespace  std;

class Produit
{

public:
    static int _idIterator;
    Produit(string titre,string descr,int qte,double prix);

    string  getTitre()const;
    string  getDescription()const;
    int     getQuantitee()const;
    double  getPrix()const;


    int setQuantitee(int qte);
    string toString()const;
    ostream& operator<<(ostream& os);
private:
    int _id;
    string _titre,_description;
    int _quantitee;
    double _prix;
};

#endif // PRODUIT_H
