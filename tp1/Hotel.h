#pragma once
#include <string>
#include <vector>
#include "Chambre.h"
using namespace std;

class Hotel
{
public :
	Hotel(int id, string nom, string ville, vector <Chambre> liste);
	int getId() const;
	string getNom() const;
	string getVille() const;
	vector <Chambre> getListe() const;
	void addChambre(Chambre chambre);
	string toString() const;
	bool chambre_existe(int num) const;
	Chambre getChambre(int num) const;
	vector <Chambre> getChambreType(Chambre::_types type) const;

private :
	int _id;
	string _nom;
	string _ville;
	vector <Chambre> _liste;

};

