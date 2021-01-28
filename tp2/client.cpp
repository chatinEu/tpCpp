#include "client.h"
#include <iostream>

int Client::_idIterator=1;
Client::Client(string nom, string prenom):_id(_idIterator),_nom(nom),_prenom(prenom),_panier()
{
    _idIterator++;
}

void Client::addToPanier(Produit p, int quantity)
{
    //change quantitée de l'obj local
    p.setQuantitee(quantity);
     _panier.push_back(p);
}


void Client::emptyPanier()
{
    _panier.clear();
}

void Client::changeQuantityFromPanier(Produit p, int quantity)
{
    Produit* prod=findProductFromPanier(p);
    prod->setQuantitee(quantity);
}

void Client::deleteFromPanier(Produit p)
{
    int pos=getPositionOfProduct(p);
    if(pos!=-1){
        vector<Produit>::iterator it=_panier.begin();
        it+=pos;
        _panier.erase(it);
    }
}

int Client::getId() const
{
    return _id;
}

string Client::getNom() const
{
    return _nom;
}

string Client::getPrenom() const
{
    return _prenom;
}

vector<Produit> Client::getPanier() const
{
    return _panier;
}

int Client::getPositionOfProduct(Produit p)
{
    for(int i=0;i<(int)_panier.size();++i){
        if(_panier.at(i).getId()==p.getId()){
            return i;
        }
    }
    return -1;
}

Produit *Client::findProductFromPanier(Produit p)
{
    for(Produit& it:_panier){
        if(it.getId()==p.getId()){
            return &it;
        }
    }
}

ostream &operator<<(ostream &os,const Client& c)
{
    os << c.getId() << '\t' +c.getNom()+'\t' << c.getPrenom()+'\t'<< endl;
    for (Produit p:c.getPanier()){
        os <<'\t'<< p;
    }
    return os;
}


