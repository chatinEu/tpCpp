#include "Hotel.h"

Hotel::Hotel(int id, string nom, string ville, vector<Chambre> liste):_id(id),_nom(nom),_ville(ville),_liste(liste){}

int Hotel::getId() const{
	return _id;
}

string Hotel::getNom() const
{
	return _nom;
}

string Hotel::getVille() const
{
	return _ville;
}

vector <Chambre> Hotel::getListe() const
{
	return _liste;
}

void Hotel::addChambre(Chambre chambre)
{
	_liste.push_back(chambre);
}

string Hotel::toString() const{
	string temp = to_string(getId()) + " " + getNom() + " " + getVille() + " ";
	for (int i = 0; i < getListe().size(); i++)
	{
		temp += "\n\t- " + getChambre(i).toString();
	}
	return temp;
}

bool Hotel::chambre_existe(int num) const{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (getChambre(i).getId() == num)
		{
			return true;
		}
	}
	return false;
}

Chambre Hotel::getChambre(int num) const{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getId() == num)
		{
			return _liste.at(i);
		}
	}
}

vector<Chambre> Hotel::getChambreType(Chambre::_types type) const
{
	vector<Chambre> tri;
	for (int i = 0; i < _liste.size(); i++)
	{
		if (getChambre(i).getType() == type)
			tri.push_back(getChambre(i));
	}
	return tri; 
}
