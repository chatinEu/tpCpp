#ifndef COMMANDE_H
#define COMMANDE_H
#include "client.h"
#include <vector>
using namespace std;
class Commande
{
public:
    enum   Etat{
        livree,
        Pas_livree
    };

    static int _idIterator;
    Commande(Client *client,vector<Produit> *liste);


private:
    int _id;
    Client* _client;
    vector<Produit>* _listeProduit;

};

#endif // COMMANDE_H
