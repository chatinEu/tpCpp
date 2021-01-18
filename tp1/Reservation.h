#pragma once
#include "Date.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Client.h"
class Reservation
{
public :
	Reservation(int id, Date debut, Date fin, Hotel hotel, Client client, int nb_chambre);
	int getId() const;
	Date getDebut() const;
	Date getFin() const;
	Hotel getHotel() const;
	Client getClient() const;
	int getNb_chambre() const;
	void setDebut(Date debut);
	void setFin(Date fin);
	void setNb_chambre(int nb_chambre);
    float total();
	float total(float remise) const;
	string toString() const;
	


	


private :
	int _id;
	Date _debut;
	Date _fin;
	Hotel _hotel;
	Client _client;
	int _nb_chambre;
};

