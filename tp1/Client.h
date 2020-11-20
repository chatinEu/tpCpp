

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
class Client{
public:
	Client(std::string nom,std::string prenom);
	Client(std::string nom,std::string prenom,int id);
	int getId()const;
private:
	static int 	_idIterator;
	const int 	_id;
	std::string _nom;
	std::string _prenom;
	int pastReservationNumber;

};

#endif