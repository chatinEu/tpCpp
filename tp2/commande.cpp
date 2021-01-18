#include "commande.h"

int Commande::_idIterator=1;
Commande::Commande(Client *client,vector<Produit> *liste):_id(_idIterator),_client(client),_listeProduit(liste){
    _idIterator++;
}
