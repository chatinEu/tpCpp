#pragma once
#include <iostream>
#include <string>
#include <sstream>	
using namespace std;


class Chambre
{
public :
	enum _types :int { Simple = 1, Double = 2, Suite = 3 };
	Chambre(int id, _types type_chambre, int prix);
	int getId() const;
	int getPrix() const;
	string toString() const;
	_types getType() const;
	void setId(int id);
	void setPrix(int prix);
	void setType(_types type_chambre);





private :
	int _id;
    int _prix;
	_types _type;
};

