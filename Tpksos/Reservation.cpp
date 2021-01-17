#include "Reservation.h"

Reservation::Reservation(int id, Date debut, Date fin, Hôtel hotel, Client client, int nb_chambre) :
	_id(id), _debut(debut), _fin(fin), _hotel(hotel), _client(client), _nb_chambre(nb_chambre)
{
}



int Reservation::getid()
{
	return _id;
}

Date Reservation::getdebut()
{
	return _debut;
}

Date Reservation::getfin()
{
	return _fin;
}

Hôtel Reservation::gethotel()
{
	return _hotel;
}

Client Reservation::getclient()
{
	return _client;
}

int Reservation::getnb_chambre()
{
	return _nb_chambre;
}

void Reservation::setdebut(Date debut)
{
	_debut = debut;
	if (debut < _fin)
	{
		_debut = debut;
	}
}

void Reservation::setfin(Date fin)
{
	if (fin > _debut) {
		_fin = fin;
	}
}

void Reservation::setnb_chambre(int nb_chambre)
{
	if (_hotel.chambre_existe(nb_chambre))
		_nb_chambre = nb_chambre;
}

float Reservation::total()
{
	return total(0);
}

float Reservation::total(float remise)
{
	if (remise >= 0 && remise <= 1)
	{
		return ((_fin - _debut) * _hotel.getchambre(_nb_chambre).getprix() * (1 - remise));
	}
	return 0.0f;
}

string Reservation::tostring()
{
	return "Reservation ref " + to_string(getid()) + " du " + getdebut().toString() + " au " + getfin().toString() + " pour " + getclient().tostring();
}
