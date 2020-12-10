#include "Reservation.h"
#include "Hotel.h"
#include "Chambre.h"

int Reservation::_idIterator=1;
Reservation::Reservation(int id,Date debut,Date fin,int idHotel,int idChambre,int idClient):
    _id(id),_dateDebut(debut),_dateFin(fin),_idHotel(idHotel),_idChambre(idChambre),
    _idClient(idClient){
        autoSetMontant();

    }
Reservation::Reservation(Date debut,Date fin,int idHotel,int idChambre,int idClient):
    _id(_idIterator),_dateDebut(debut),_dateFin(fin),_idHotel(idHotel),_idChambre(idChambre),
    _idClient(idClient){
        _idIterator+=1;
        autoSetMontant();

    }

void Reservation::autoSetMontant(){
    int dureeSejour=_dateFin.compare(_dateDebut);
    Chambre ch = Hotel::getHotelById(_idHotel).getChambreById(_idChambre);
    _montantAPayer=dureeSejour*ch.getDailyPrice();
}
int Reservation::getPrice()const{
    return _montantAPayer;
}