#include "magasin.h"
#include <iostream>
Magasin::Magasin():_listClient(),_listProduit(),_listCommande()
{
}

void Magasin::addProduct(Produit* p)
{
    _listProduit.push_back(p);
}

void Magasin::updateProduct(string str,int qte)
{
    Produit* p=findProduct(str);
    if(p!=nullptr)
        p->setQuantitee(qte);

}

void Magasin::addClient(Client *c)
{
    _listClient.push_back(c);
}

string Magasin::toString() const
{
    return "";
}

void Magasin::showProduits() const
{
    for (Produit* obj:_listProduit){
        cout<<*obj;
    }
}

void Magasin::showClients() const
{
    for (auto ci:_listClient){
        std::cout<<*ci;
    }
}

void Magasin::showClients(int id) const
{
    cout<<*findClient(id);
}

void Magasin::showClients(string nom) const
{
    for(Client* ci:findClient(nom)){
        cout<<*ci;
    }
}

void Magasin::addProductFromClientPanier(Client client, Produit produit, int quantitee)
{
    Client* c=findClient(client.getId());
    c->addToPanier(produit,quantitee);
}

void Magasin::deleteProductFromClientPanier(Client client, Produit produit)
{
     Client* c=findClient(client.getId());
     c->deleteFromPanier(produit);
}

void Magasin::modifyProductQuantityFromClientPanier(Client client, Produit produit,int quantity)
{
    Client* c=findClient(client.getId());
    c->changeQuantityFromPanier(produit,quantity);
}

void Magasin::showProduits(string str) const
{
    cout<<"found product->\t"+findProduct(str)->toString()<<endl;
}

Produit *Magasin::findProduct(string str) const
{
    for (Produit* obj:_listProduit){
       if (obj->getTitre()==str){
           return obj;
       }
    }
    cout<<"no object of this name found\n";
    //cerr bloque la suite du programme
    return nullptr;
}

Client *Magasin::findClient(int id) const
{
    for(Client* ci:_listClient)
        if(ci->getId()==id)
            return ci;
    return nullptr;
}

vector<Client *> Magasin::findClient(string nom) const
{
    //plusieurs personnes peuvent avoir le meme nom
    vector<Client*> vect;
    for(Client* ci:_listClient){
        if(ci->getNom()==nom)
                vect.push_back(ci);
    }
    return vect;
}

