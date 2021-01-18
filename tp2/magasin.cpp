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

string Magasin::toString() const
{
    return "";
}

void Magasin::showProduits() const
{
    for (Produit* obj:_listProduit){
        cout<<obj->toString()<<endl;
    }
}

void Magasin::showProduits(string str) const
{
    cout<<findProduct(str)->toString();
}

Produit *Magasin::findProduct(string str) const
{
    for (Produit* obj:_listProduit){
       if (obj->getTitre()==str){
           return obj;
       }
    }
    return nullptr;
}

