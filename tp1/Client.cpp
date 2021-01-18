#include "Client.h"


Client::Client(int id, string nom, string prenom):_id(id),_nom(nom),_prenom(prenom),_nb_resa(0){}

int Client::getId() const
{
	return _id;
}

string Client::getNom() const
{
	return _nom;
}

string Client::getPrenom() const
{
	return _prenom;
}

void Client::setId(int id) 
{
	_id = id;
}

void Client::setNom(string nom)
{
	_nom = nom;
}

void Client::setPrenom(string prenom)
{
	_prenom = prenom;
}

void Client::setNb_resa(int nb_resa)
{
	_nb_resa = nb_resa;
}

string Client::toString() const
{
	return getNom() + " " + getPrenom() + " " + to_string(getId()) + " " + to_string(getNb_resa());
}

int Client::getNb_resa() const
{
	return _nb_resa;
}

