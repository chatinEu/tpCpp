#include "produit.h"
#include <cmath>

int Produit::_idIterator=1;

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

int Produit::setQuantitee(int qte)
{
    _quantitee=max(0,qte);
}

string Produit::toString() const
{
    return getTitre()+ " " +getDescription()+" "+to_string(getQuantitee())+" "+to_string(getPrix());
}

ostream &Produit::operator<<(ostream& os)
{
    os << toString()<<endl;
    return os;
}
