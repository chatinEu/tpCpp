#pragma once
#include <string>
using namespace std;
class Client
{
public:
	Client(int id, string nom, string prenom);
	int getid() const;
	string getnom() const;
	string getprenom() const;
	string tostring() const;
	int getnb_resa() const;

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

