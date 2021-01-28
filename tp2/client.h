#ifndef CLIENT_H
#define CLIENT_H

#include "produit.h"

#include <string>
#include <vector>
using namespace std;


class Client
{
public:
    static int _idIterator;
    Client(string nom,string prenom);
    void addToPanier(Produit p,int quantity=1);
    void emptyPanier();
    void changeQuantityFromPanier(Produit p,int quantity);
    void deleteFromPanier(Produit p);


    int getId()const;
    string getNom()const;
    string getPrenom()const;
    vector<Produit> getPanier()const;



    friend ostream& operator<<(ostream& os,const Client& c);
private:
    int getPositionOfProduct(Produit p);
    Produit* findProductFromPanier(Produit p);
    int _id;
    string _nom,_prenom;
    vector<Produit> _panier;
};

#endif // CLIENT_H
