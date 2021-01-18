#include "Chambre.h"

Chambre::Chambre(int id, _types type_chambre, int prix):_id(id),_type(type_chambre),_prix(prix){}

int Chambre::getid() const
{
	return _id;
}

int Chambre::getprix() const
{
	return _prix;
}

string Chambre::tostring() const
{
	return to_string(getid()) + " " + to_string(getprix()) + " " + to_string(gettype()) ;
}

Chambre::_types Chambre::gettype() const
{
	return _type;
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

