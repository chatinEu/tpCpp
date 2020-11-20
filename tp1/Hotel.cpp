#include "Hotel.h"


Hotel::Hotel(int id,std::string nom,std::string ville,std::vector<Chambre> chambreList):
    _id(id),_nom(nom),_ville(ville),_listChambre(chambreList){}

