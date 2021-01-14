#pragma once
#include "Date.h"
#include "Chambre.h"
#include "Hôtel.h"
#include "Client.h"
class Reservation
{
public :
	Reservation(int id, Date& debut, Date& fin, Hôtel& hotel, Client& client, int nb_chambre);
	int getid();
	Date getdebut();
	Date getfin();
	Hôtel gethotel();
	Client getclient();
	int getnb_chambre();
	void setdebut(Date debut);
	void setfin(Date fin);
	void setnb_chambre(int nb_chambre);
    float total();
	float total(float remise);
	


	


private :
	int _id;
	Date& _debut;
	Date& _fin;
	Hôtel& _hotel;
	Client& _client;
	int _nb_chambre;

	
};

