#include "produit.h"
#include <cmath>

int Produit::_idIterator=1;



ostream& operator<<(ostream &os,const  Produit& p)
{
    os<<p.toString()<<endl;
    return os;
}

Produit::Produit(string titre,string descr,int qte,double prix)
    :_id(_idIterator),_titre(titre),_description(descr),_quantitee(max(0,qte)),_prix(abs(prix)){
    _idIterator++;
}

string Produit::getTitre()const{
    return _titre;
}

string Produit::getDescription() const
{
    return _description;
}

int Produit::getQuantitee() const
{
    return _quantitee;
}

double Produit::getPrix() const
{
    return _prix;
}

int Produit::getId() const
{
    return _id;
}

bool Produit::equals(Produit p) const
{
    if(p.getId()==getId())
        return true;
    return false;
}

int Produit::setQuantitee(int qte)
{
    _quantitee=max(0,qte);
}

string Produit::toString() const
{
    return to_string(getId())+'\t'+ getTitre()+ '\t' +getDescription()+'\t'+to_string(getQuantitee())+'\t'+to_string(getPrix());
}

