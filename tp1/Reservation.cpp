#include "Reservation.h"

Reservation::Reservation(int id,Date debut,Date fin,int idHotel,int idChambre,int idClient):
    _id(id),_dateDebut(debut),_dateFin(fin),_idHotel(idHotel),_idChambre(idChambre),
    _idClient(idClient){
        autoSetMontant();

    }

void Reservation::autoSetMontant(){
    _montantAPayer=0;    
}
