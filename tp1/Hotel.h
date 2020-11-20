#include "vector"
#include "string"
#include "Chambre.h"
class Hotel{
    public:
        Hotel(int id,std::string nom,std::string ville,std::vector<Chambre> chambreList);
    private:
        const int _id;
        std::string _nom,_ville;
        std::vector<Chambre> _listChambre;
};