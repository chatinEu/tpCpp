#include "Chambre.h"

Chambre::Chambre(int id, _types type_chambre, int prix)
{
	_id = id;
	_type = type_chambre;
	_prix = prix;
}

int Chambre::getid()
{
	return _id;
}

int Chambre::getprix()
{
	return _prix;
}

string Chambre::tostring()
{
	return to_string(getid()) + " " + to_string(getprix()) + " " + to_string(gettype()) ;
}

Chambre::_types Chambre::gettype()
{
	return _types();
}

void Chambre::setid(int id)
{
	_id = id;
}

void Chambre::setprix(int prix)
{
	_prix = prix;
}

void Chambre::settype(_types type_chambre)
{
	_type = type_chambre;
}

