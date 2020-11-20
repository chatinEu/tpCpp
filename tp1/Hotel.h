#include "vector"
#include "string"
#include "Chambre.h"
class Hotel{
    private:
        const int id;
        std::string nom,ville;
        std::vector<Chambre> listChambre;
}