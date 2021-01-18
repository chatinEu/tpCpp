#pragma once
#include "Date.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Client.h"
class Reservation
{
public :
	Reservation(int id, Date debut, Date fin, Hotel hotel, Client client, int nb_chambre);
	int getid();
	Date getdebut();
	Date getfin();
	Hotel gethotel();
	Client getclient();
	int getnb_chambre();
	void setdebut(Date debut);
	void setfin(Date fin);
	void setnb_chambre(int nb_chambre);
    float total();
	float total(float remise);
	string tostring();
	


	


private :
	int _id;
	Date _debut;
	Date _fin;
	Hotel _hotel;
	Client _client;
	int _nb_chambre;
};

