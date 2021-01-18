#include "client.h"

int Client::_idIterator=1;
Client::Client(string nom, string prenom):_id(_idIterator),_nom(nom),_prenom(prenom),_panier()
{
    _idIterator++;
}

void Client::addToPanier(Produit p)
{
    _panier.push_back(p);
}


