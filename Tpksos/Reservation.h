#pragma once
#include "Date.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Client.h"
class Reservation
{
public :
	Reservation(int id, Date debut, Date fin, Hotel hotel, Client client, int nb_chambre);
	int getid() const;
	Date getdebut() const;
	Date getfin() const;
	Hotel gethotel() const;
	Client getclient() const;
	int getnb_chambre() const;
	void setdebut(Date debut);
	void setfin(Date fin);
	void setnb_chambre(int nb_chambre);
    float total();
	float total(float remise) const;
	string tostring() const;
	


	


private :
	int _id;
	Date _debut;
	Date _fin;
	Hotel _hotel;
	Client _client;
	int _nb_chambre;
};

