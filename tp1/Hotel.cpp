#include "Hotel.h"

Hotel::Hotel(int id, string nom, string ville, vector<Chambre> liste):_id(id),_nom(nom),_ville(ville),_liste(liste){}

int Hotel::getid() const{
	return _id;
}

string Hotel::getnom() const
{
	return _nom;
}

string Hotel::getville() const
{
	return _ville;
}

vector <Chambre> Hotel::getliste() const
{
	return _liste;
}

void Hotel::addChambre(Chambre chambre)
{
	_liste.push_back(chambre);
}

string Hotel::tostring() const{
	string temp = to_string(getid()) + " " + getnom() + " " + getville() + " ";
	for (int i = 0; i < getliste().size(); i++)
	{
		temp += "\n\t- " + getchambre(i).tostring();
	}
	return temp;
}

bool Hotel::chambre_existe(int num) const{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (getchambre(i).getid() == num)
		{
			return true;
		}
	}
	return false;
}

Chambre Hotel::getchambre(int num) const{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return _liste.at(i);
		}
	}
}

vector<Chambre> Hotel::getchambretype(Chambre::_types type) const
{
	vector<Chambre> tri;
	for (int i = 0; i < _liste.size(); i++)
	{
		if (getchambre(i).gettype() == type)
			tri.push_back(getchambre(i));
	}
	return tri; 
}
