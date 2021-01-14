#include "Client.h"
#include "Chambre.h"
#include "Hôtel.h"
#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;


ostream& operator<<(ostream& ss, Chambre& c)
{
	ss << c.tostring();
	return ss;
}

ostream& operator<<(ostream& ss, Hôtel& c)
{
	ss << c.tostring();
	return ss;
}




int main()
{
	Client client1(1,"Montagnier","Gilbert");
	//cout << client1.tostring();
	Chambre Chambre1(1, Chambre::_types::Simple, 180);
	//cout << Chambre1;
	vector <Chambre> Chambres;
	for (int i = 0; i < 3; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Simple, 100));
	for (int i = 3; i < 8; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Double, 125));
	for (int i = 8; i < 10; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Suite, 210));

	
	
	
	
	Hôtel hotel(1, "bon","Roubaix", Chambres);
	//cout << hotel;
	Date d1(1, 1, 1), d2(1, 2, 1);
	Reservation res(1, d1, d2, hotel, client1,1);

	//cout << res.total(0.10) << endl;
	vector <Hôtel> Jacquemard = {  };
	




	return 0;
}