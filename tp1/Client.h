#include <string>
class Client{
	Client(std::string nom,std::string prenom);

private:
	const int 	_id;
	static int 	_idIterator;
	std::string _nom;
	std::string _prenom;
	int pastReservationNumber;

};