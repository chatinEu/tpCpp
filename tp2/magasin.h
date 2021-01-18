#ifndef MAGASIN_H
#define MAGASIN_H

#include "client.h"
#include "commande.h"
#include "produit.h"

#include <vector>
using namespace std;
class Magasin
{
public:
    Magasin();
    Magasin(vector<Client*> clients,vector<Produit*> produits,vector<Commande*> commandes);
    void addProduct(Produit* p);
    void updateProduct(string str,int qte);

    string toString()const;
    void showProduits(string str)const;
    void showProduits()const;
private:
    Produit *findProduct(string str)const;
    vector<Client*>     _listClient;
    vector<Produit*>    _listProduit;
    vector<Commande*>   _listCommande;
};

#endif // MAGASIN_H
