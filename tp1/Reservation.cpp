#include "Reservation.h"

Reservation::Reservation(int id, Date debut, Date fin, Hotel hotel, Client client, int nb_chambre) :
	_id(id), _debut(debut), _fin(fin), _hotel(hotel), _client(client), _nb_chambre(nb_chambre)
{}



int Reservation::getId() const
{
	return _id;
}

Date Reservation::getDebut() const
{
	return _debut;
}

Date Reservation::getFin() const
{
	return _fin;
}

Hotel Reservation::getHotel() const
{
	return _hotel;
}

Client Reservation::getClient() const
{
	return _client;
}

int Reservation::getNb_chambre() const
{
	return _nb_chambre;
}

void Reservation::setDebut(Date debut)
{
	_debut = debut;
	if (debut < getFin())
	{
		_debut = debut;
	}
}

void Reservation::setFin(Date fin)
{
	if (fin > getDebut()) {
		_fin = fin;
	}
}

void Reservation::setNb_chambre(int nb_chambre)
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
		return ((getFin() - getDebut()) * getHotel().getChambre(getNb_chambre()).getPrix() * (1 - remise));
	}
	return 0.0f;
}

string Reservation::toString() const
{
	return "Reservation ref " + to_string(getId()) + " du " + getDebut().toString() + " au " + getFin().toString() + " pour " + getClient().toString();
}
