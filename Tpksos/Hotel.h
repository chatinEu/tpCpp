#pragma once
#include <string>
#include <vector>
#include "Chambre.h"
using namespace std;

class Hotel
{
public :
	Hotel(int id, string nom, string ville, vector <Chambre> liste);
	int getid() const;
	string getnom() const;
	string getville() const;
	vector <Chambre> getliste() const;
	void addChambre(Chambre chambre);
	string tostring() const;
	bool chambre_existe(int num) const;
	Chambre getchambre(int num) const;
	vector <Chambre> getchambretype(Chambre::_types type) const;

private :
	int _id;
	string _nom;
	string _ville;
	vector <Chambre> _liste;

};

