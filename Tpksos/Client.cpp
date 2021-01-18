#include "Client.h"


Client::Client(int id, string nom, string prenom):_id(id),_nom(nom),_prenom(prenom),_nb_resa(0){}

int Client::getid() const
{
	return _id;
}

string Client::getnom() const
{
	return _nom;
}

string Client::getprenom() const
{
	return _prenom;
}

void Client::setid(int id) 
{
	_id = id;
}

void Client::setnom(string nom)
{
	_nom = nom;
}

void Client::setprenom(string prenom)
{
	_prenom = prenom;
}

void Client::setnb_resa(int nb_resa)
{
	_nb_resa = nb_resa;
}

string Client::tostring() const
{
	return getnom() + " " + getprenom() + " " + to_string(getid()) + " " + to_string(getnb_resa());
}

int Client::getnb_resa() const
{
	return _nb_resa;
}

