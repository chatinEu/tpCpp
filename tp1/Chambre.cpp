#include "Chambre.h"

Chambre::Chambre(int id, _types type_chambre, int prix):_id(id),_type(type_chambre),_prix(prix){}

int Chambre::getId() const
{
	return _id;
}

int Chambre::getPrix() const
{
	return _prix;
}

string Chambre::toString() const
{
	return to_string(getId()) + " " + to_string(getPrix()) + " " + to_string(getType()) ;
}

Chambre::_types Chambre::getType() const
{
	return _type;
}

void Chambre::setId(int id)
{
	_id = id;
}

void Chambre::setPrix(int prix)
{
	_prix = prix;
}

void Chambre::setType(_types type_chambre)
{
	_type = type_chambre;
}

