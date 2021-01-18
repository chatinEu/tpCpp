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
    void addToPanier(Produit p);
private:
    int _id;
    string _nom,_prenom;
    vector<Produit> _panier;
};

#endif // CLIENT_H
