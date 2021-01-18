#pragma once
#include <string>
#include <vector>
#include "Chambre.h"
using namespace std;

class Hotel
{
public :
	Hotel(int id, string nom, string ville, vector <Chambre> liste);
	int getid();
	string getnom();
	string getville();
	vector <Chambre> getliste();
	void addChambre(Chambre chambre);
	string tostring();
	bool chambre_existe(int num);
	Chambre getchambre(int num);
	vector <Chambre> getchambretype(Chambre::_types type);

private :
	int _id;
	string _nom;
	string _ville;
	vector <Chambre> _liste;

};

