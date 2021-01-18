#pragma once
#include <string>
using namespace std;
class Client
{
public:
	Client(int id, string nom, string prenom);
	int getId() const;
	string getNom() const;
	string getPrenom() const;
	string toString() const;
	int getNb_resa() const;

	void setId(int id);
	void setNom(string nom);
	void setPrenom(string prenom);
	void setNb_resa(int nb_resa);






private :
	int _id;
	string _nom;
	string _prenom;
	int _nb_resa;


};

