#include "Hotel.h"

Hotel::Hotel(int id, string nom, string ville, vector<Chambre> liste)
{
	_id = id;
	_nom = nom;
	_ville = ville;
	_liste = liste;
}

int Hotel::getid()
{
	return _id;
}

string Hotel::getnom()
{
	return _nom;
}

string Hotel::getville()
{
	return _ville;
}

vector <Chambre> Hotel::getliste()
{
	return _liste;
}

void Hotel::addChambre(Chambre chambre)
{
	_liste.push_back(chambre);
}

string Hotel::tostring()
{

	string temp = to_string(getid()) + " " + getnom() + " " + getville() + " ";
	for (int i = 0; i < getliste().size(); i++)
	{
		temp += "\n\t- " + getliste().at(i).tostring();
	}
	return temp;
}

bool Hotel::chambre_existe(int num)
{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return true;
		}
	}
	return false;
}

Chambre Hotel::getchambre(int num)
{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return _liste.at(i);
		}
	}
}

vector<Chambre> Hotel::getchambretype(Chambre::_types type)
{
	vector<Chambre> tri;
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).gettype() == type)
			tri.push_back(_liste.at(i));
	}
	return tri; 
}
