#pragma once
#include <string>
using namespace std;
class Client
{
public:
	Client(int id, string nom, string prenom);
	int getid();
	string getnom();
	string getprenom();
	string tostring();
	int getnb_resa();

	void setid(int id);
	void setnom(string nom);
	void setprenom(string prenom);
	void setnb_resa(int nb_resa);






private :
	int _id;
	string _nom;
	string _prenom;
	int _nb_resa;


};

