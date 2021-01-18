#include "Reservation.h"

Reservation::Reservation(int id, Date debut, Date fin, Hotel hotel, Client client, int nb_chambre) :
	_id(id), _debut(debut), _fin(fin), _hotel(hotel), _client(client), _nb_chambre(nb_chambre)
{}



int Reservation::getid() const
{
	return _id;
}

Date Reservation::getdebut() const
{
	return _debut;
}

Date Reservation::getfin() const
{
	return _fin;
}

Hotel Reservation::gethotel() const
{
	return _hotel;
}

Client Reservation::getclient() const
{
	return _client;
}

int Reservation::getnb_chambre() const
{
	return _nb_chambre;
}

void Reservation::setdebut(Date debut)
{
	_debut = debut;
	if (debut < getfin())
	{
		_debut = debut;
	}
}

void Reservation::setfin(Date fin)
{
	if (fin > getdebut()) {
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

float Reservation::total(float remise) const
{
	if (remise >= 0 && remise <= 1)
	{
		return ((getfin() - getdebut()) * gethotel().getchambre(getnb_chambre()).getprix() * (1 - remise));
	}
	return 0.0f;
}

string Reservation::tostring() const
{
	return "Reservation ref " + to_string(getid()) + " du " + getdebut().toString() + " au " + getfin().toString() + " pour " + getclient().tostring();
}
