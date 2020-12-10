#include "Chambre.h"

int Chambre::_idIterator=1;
Chambre::Chambre(int id,int prix,type type):_id(id),_prix(prix),_type(type){}
Chambre::Chambre(int prix,type type):_id(_idIterator),_prix(prix),_type(type){
    _idIterator+=1;
}
Chambre::Chambre():_id(-1){}

int Chambre::getDailyPrice() const{
    return _prix;
}

int Chambre::getId()const {
    return _id;
}