#include "Hôtel.h"

Hôtel::Hôtel(int id, string nom, string ville, vector<Chambre> liste)
{
	_id = id;
	_nom = nom;
	_ville = ville;
	_liste = liste;
}

int Hôtel::getid()
{
	return _id;
}

string Hôtel::getnom()
{
	return _nom;
}

string Hôtel::getville()
{
	return _ville;
}

vector <Chambre> Hôtel::getliste()
{
	return _liste;
}

void Hôtel::addChambre(Chambre chambre)
{
	_liste.push_back(chambre);
}

string Hôtel::tostring()
{

	string temp = to_string(getid()) + " " + getnom() + " " + getville() + " ";
	for (int i = 0; i < getliste().size(); i++)
	{
		temp += "\n\t- " + getliste().at(i).tostring();
	}
	return temp;
}

bool Hôtel::chambre_existe(int num)
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

Chambre Hôtel::getchambre(int num)
{
	for (int i = 0; i < _liste.size(); i++)
	{
		if (_liste.at(i).getid() == num)
		{
			return _liste.at(i);
		}
	}
}
