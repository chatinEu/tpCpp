#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"

class Reservation{
    public:
        Reservation(int id,Date debut,Date fin,int idHotel,int idChambre,int idClient);
        
    private:
        int _id,_idHotel,_idChambre,_idClient;
        Date _dateDebut,_dateFin;
        int _montantAPayer;
        void autoSetMontant();
};
#endif