#include "vector"
#include "string"
#include "Chambre.h"
class Hotel{
    public:
        static int _idIterator;
        static std::vector<Hotel*> _listHotel;
        Hotel(int id,std::string nom,std::string ville,std::vector<Chambre> chambreList);
        Hotel(std::string nom,std::string ville,std::vector<Chambre> chambreList);
        Hotel();
        static Hotel getHotelById(int id);
        Chambre getChambreById(int id);
        Hotel copy();
        
        int getId()const ;
        std::string getNom()const;
        std::string getVille()const;
        std::vector<Chambre> getChambreList()const;
    private:
        const int _id;
        std::string _nom,_ville;
        std::vector<Chambre> _listChambre;
};