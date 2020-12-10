#include "Hotel.h"

int Hotel::_idIterator=1;
std::vector<Hotel*> Hotel::_listHotel;

Hotel::Hotel(std::string nom,std::string ville,std::vector<Chambre> chambreList):
    _id(_idIterator),_nom(nom),_ville(ville),_listChambre(chambreList){
       _idIterator+=1;
       _listHotel.push_back(this);
    }
Hotel::Hotel():_id(-1){}
//used for copies
Hotel::Hotel(int id,std::string nom,std::string ville,std::vector<Chambre> chambreList):
    _id(id),_nom(nom),_ville(ville),_listChambre(chambreList){}


Hotel Hotel::getHotelById(int id){
  
    for (auto i : _listHotel)
    {
        if (i->_id==id)
           return *i;
    } 
    return Hotel();
}

Chambre Hotel::getChambreById(int id){
    for (auto &&i : _listChambre)
    {
        if(i.getId()==id)
            return i;
    }
    return Chambre();
}

Hotel Hotel::copy(){
    Hotel ho(getId(),
        getNom(),
        getVille(),
        getChambreList());
    return ho;
}

int Hotel::getId() const{
    return _id;
}
std::string Hotel::getNom() const {
    return _nom;
}
std::string Hotel::getVille()const{
    return _ville;
}
std::vector<Chambre> Hotel::getChambreList()const{
    return _listChambre;
}
