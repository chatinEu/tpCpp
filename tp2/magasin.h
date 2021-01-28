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
    void addClient(Client* c);




    string toString()const;
    void showProduits(string str)const;
    void showProduits()const;

    void showClients()const;
    void showClients(int id)const;
    void showClients(string nom)const;
    void addProductFromClientPanier(Client client,Produit produit,int quantitee=1);
    void deleteProductFromClientPanier(Client client,Produit produit);
    void modifyProductQuantityFromClientPanier(Client client,Produit produit,int quantity);
private:
    Produit *findProduct(string str)const;
    Client *findClient(int id)const;
    vector<Client *>findClient(string str)const;


    vector<Client*>     _listClient;
    vector<Produit*>    _listProduit;
    vector<Commande*>   _listCommande;
};

#endif // MAGASIN_H
