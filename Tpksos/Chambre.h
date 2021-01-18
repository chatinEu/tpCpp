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
	int getid() const;
	int getprix() const;
	string tostring() const;
	_types gettype() const;
	void setid(int id);
	void setprix(int prix);
	void settype(_types type_chambre);





private :
	int _id;
    int _prix;
	_types _type;
};

