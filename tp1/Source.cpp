#include "Client.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;



void print_space()
{
	for (int i = 0; i < 3; i++)
		cout << endl;
}


ostream& operator<<(ostream& ss, Chambre& c)
{
	ss << c.tostring();
	return ss;
}

ostream& operator<<(ostream& ss, Hotel& c)
{
	ss << c.tostring();
	return ss;
}
ostream& operator<<(ostream& ss, Client& c)
{
	ss << c.tostring();
	return ss;
}
ostream& operator<<(ostream& ss, Reservation& c)
{
	ss << c.tostring();
	return ss;
}



Date entree_date(string msg)
{
	cout << "Rentrez une date de " << msg << " :" << endl;
	cout << "\t- Jour : ";
	int jour, mois, annee;
	cin >> jour;
	cout << "\t- Mois : ";
	cin >> mois;
	cout << "\t- Ann�e : ";
	cin >> annee;
	Date date(mois, jour, annee);
	if (date.checkDate(mois, jour))
	{
		return date;
    }
	else {
		cout << "Date invalide" << endl;
		return entree_date(msg);
	}
}

Chambre::_types entree_type()
{
	print_space();
	cout << "Choisissez un type de chambre " << endl;
	cout << "\t" << Chambre::_types::Simple << "- Simple" << endl;
	cout << "\t" << Chambre::_types::Double << "- Double" << endl;
	cout << "\t" << Chambre::_types::Suite << "- Suite" << endl;
	
	int choix;
	cin >> choix;
	switch (choix)
	{
	case Chambre::_types::Simple:
		return Chambre::_types::Simple;
		break;
	case Chambre::_types::Double:
		return Chambre::_types::Double;
		break;
	case Chambre::_types::Suite:
		return Chambre::_types::Suite;
		break;

	default:
		cout << "Type de chambre invalide" << endl;
		return entree_type();
		break;
	}
}

int menu()
{
	print_space();
	vector<string> options = {
		"Creer une reservation",
		"Afficher toutes les reservations",
		"Afficher une reservation",
		"Afficher les reservations d'un client",
		"Modifier une reservation",
		"Annuler une reservation",
		"Afficher les reservations a la date"
	};

	cout << endl << endl << endl << endl;
	cout << "Gestion de r�servation :" << endl;
	for (unsigned int i = 0; i < options.size(); i++)
		cout << "\t" << i + 1 << "- " << options.at(i) << endl;
	cout << "\t0- Quitter" << endl;

	int choix;
	cin >> choix;
	if (choix >= 0 && choix <= options.size())
	{
		return choix;
	}
	else
	{
		cout << "Choix invalide" << endl;
		return menu();
	}
}



Client &choisirClient(vector <Client> &clients)
{
	print_space();
	if (clients.size() > 0)
	{
		cout << "*---- Liste des clients ----* " << endl;
		for (int i = 0; i < clients.size(); i++)
			cout << i << " - " << clients.at(i) << endl;

		cout << "*---- Choix du client ---- *" << endl;
		cout << "\t1- Choix par ID" << endl;
		cout << "\t2- Filtrer par nom" << endl;
		int choix = 0;
		while (choix == 0)
		{
			cout << "Votre choix : ";
			cin >> choix;
			if (choix != 1 && choix != 2)
			{
				cout << "Choix invalide" << endl;
				choix = 0;
			}
		}

		if (choix == 1)
		{
			cout << "choisissez le numero du client";
			int choix;

			cin >> choix;
			if (choix >= 0 && choix <= clients.size())
			{
				return clients.at(choix);
			}
			else
			{
				cout << "Choix invalide" << endl;
				return choisirClient(clients);
			}
		}
		else if (choix == 2)
		{
			cout << "Entrer le nom � filtrer : ";
			string nom;
			cin >> nom;
			vector<Client> filtre;
			for (int i = 0; i < clients.size(); i++)
				if (clients.at(i).getnom().find(nom) != string::npos || clients.at(i).getprenom().find(nom) != string::npos)
					filtre.push_back(clients.at(i));
			return choisirClient(filtre);
		}
	}
	else
	{
		cout << "Aucun client !" << endl;
		Client c(-1, "Dummy", "Dummy");
		return c;
	}
}




Chambre chambre_dispo(Chambre::_types type_chambre, Hotel hotel, Date date_debut, Date date_fin, vector <Reservation> reservations)

{
	vector <Chambre> chambres = hotel.getchambretype(type_chambre); // recupere les chambres du bon type
	if (reservations.size() > 0)
	{
		for (int i = 0; i < chambres.size(); i++)
		{
			bool dispo = true;
			for (int j = 0; j < reservations.size(); j++)
			{
				if (reservations.at(j).getnb_chambre() == chambres.at(i).getid())
				{
					if (!(date_debut < reservations.at(j).getfin()) && !(date_fin > reservations.at(j).getdebut()))
					{
						// chambre dispo
					}
					else
					{
						// chambre pas dispo
						dispo = false;
					}
				}
			}
			if (dispo)
				return chambres.at(i);
		}
		return Chambre(-1, Chambre::_types::Simple, 0); // chambre qui n'existe pas
	}
	else
	{
		if(chambres.size() > 0)
			return chambres.at(0);
		else
			return Chambre(-1, Chambre::_types::Simple, 0); // chambre qui n'existe pas
	}
}











Reservation creer_reservation(int id, Hotel &hotel, vector <Client> &clients, vector <Reservation> reservations)
{
	print_space();
	cout << "*----- Creation de reservation -----*" << endl;
	Date date_debut = entree_date("debut");
	Date date_fin = entree_date("fin");
	while (!(date_debut < date_fin))
	{
		cout << "dates invalides" << endl;
		date_debut = entree_date("debut");
		date_fin = entree_date("fin");

	}
	cout << "Reservation de " << date_fin - date_debut << " nuits" << endl;

	// demander le type de chambre
	Chambre::_types type_chambre = entree_type();
	// cici on a une chambre de l'hotel
	Chambre chambre_trouvee = chambre_dispo(type_chambre, hotel, date_debut, date_fin, reservations);
	if (chambre_trouvee.getid() == -1) // pas de chambre dispo
	{
		cout << "Pas de chambre disponible" << endl;
		return Reservation(-1, date_debut, date_fin, hotel, clients.at(0), 0); // resa invalide
	}
	else {
		Reservation resa(id, date_debut, date_fin, hotel, choisirClient(clients), chambre_trouvee.getid());
		cout << "prix du s�jour : "  << resa.total() << endl;
		return resa;
	}
}

void afficher_resa(vector <Reservation> &reservations)
{
	for (int i = 0; i < reservations.size(); i++)
	{
		cout << reservations.at(i) << endl;
	}
}


void afficher_resa_spec(vector<Reservation> reservations)
{
	print_space();
	for (int i = 0; i < reservations.size(); i++)
	{
		cout << "\tReservation ref " << reservations.at(i).getid();
		if (i % 2 == 1)
			cout << endl;
	}
	cout << endl << "Entrer la ref de la reservation a afficher : ";
	int id;
	cin >> id;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations.at(i).getid() == id)
		{
			cout << reservations.at(i) << endl;
			return;
		}
	}
	cout << "Aucune reservation correspondant a cette reference !" << endl;
}


void afficher_resa_client(vector<Reservation> reservations, vector<Client> clients)
{
	print_space();
	Client c = choisirClient(clients);
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations.at(i).getclient().getid() == c.getid())
			cout << reservations.at(i) << endl;
	}
}


int choisirReservationNum(vector<Reservation> resas)
{
	cout << "*---- Liste des reservations ----*" << endl;
	for (int i = 0; i < resas.size(); i++)
	{
		cout << "\t" << resas.at(i) << endl;
	}
	int choix = -1;
	while (choix == -1)
	{
		cout << "Choisir une reservation par ref : ";
		cin >> choix;
		if (choix < 0 || choix >= resas.size())
		{
			cout << "Choix invalide, veuillez reessayer" << endl;
				choix = -1;
		}
	}
	return choix;
}



vector<Reservation> modifier_resa(vector<Reservation> reservations)
{
	int resa_num = choisirReservationNum(reservations);
	Reservation resa = reservations.at(resa_num);

	int choix = -1;
	while (choix == -1)
	{
		cout << endl << endl << "*---- Modifier la reservation ref " << resa.getid() << " ----*" << endl;
		cout << "\t0- Changer date debut" << endl
			<< "\t1- Changer date fin" << endl
			<< "\t2- Changer chambre" << endl
			<< "\t3- Enregistrer et quitter" << endl
			<< "Votre choix : " << endl;
		cin >> choix;
		if (choix < 0 || choix > 3)
		{
			cout << "Choix invalide" << endl;
			choix = -1;
		}
		else
		{
			switch (choix)
			{
			case 0:
				resa.setdebut(entree_date("debut"));
				break;
			case 1:
				resa.setfin(entree_date("fin"));
				break;
			case 2:
				Chambre chambre_trouvee = chambre_dispo(resa.gethotel().getchambre(resa.getnb_chambre()).gettype(), resa.gethotel(), resa.getdebut(), resa.getfin(), reservations);
				resa.setnb_chambre(chambre_trouvee.getid());
				break;
			}
			if(choix != 3)
				choix = - 1;
		}
	}
	reservations.at(resa_num) = resa;
	return reservations;
}



vector<Reservation> annuler_reservation(vector<Reservation> reservations)
{
	print_space();
	int resa_num = choisirReservationNum(reservations);
	cout << "Voulez-vous vraiment supprimer la reservation " << reservations.at(resa_num).getid() << " ? [y/n] : ";
	string choix = "";
	while (choix == "")
	{
		cin >> choix;
		if (choix != "y" && choix != "n" && choix != "Y" && choix != "N")
		{
			cout << "Choix invalide, veuillez reessayer : ";
			choix = "";
		}
	}
	if (choix == "y" || choix == "Y")
	{
		reservations.erase(reservations.begin() + resa_num);
	}
	return reservations;
}



void afficher_resa_a_date(vector<Reservation> reservations)
{
	print_space();
	Date date = entree_date("reservation");
	cout << "*---- Reservations a cette date ----*" << endl;
	for (int i = 0; i < reservations.size(); i++)
	{
		if (reservations.at(i).getdebut() < date && reservations.at(i).getfin() > date)
		{
			cout << reservations.at(i) << endl;
		}
	}
}











int main()
{
	vector <Client> clients = { Client(1,"Montagnier","Gilbert"), Client(2,"Renene","Timoth�") };

	vector <Chambre> Chambres;
	for (int i = 0; i < 3; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Simple, 100));
	for (int i = 3; i < 8; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Double, 125));
	for (int i = 8; i < 10; i++)
		Chambres.push_back(Chambre(i, Chambre::_types::Suite, 210));
	vector <Reservation> reservations;
	
	Hotel hotel(1, "bon","Roubaix", Chambres);

	
	int id_resa = 0;
	int choix = 1;
	while (choix != 0)
	{
		choix = menu();

		switch (choix)
		{
		case 0:
			break;

		case 1:
			{
				Reservation resa = creer_reservation(id_resa++, hotel, clients, reservations);
				if (resa.getid() != -1)
					reservations.push_back(resa);
			}
			break;

		case 2:
			afficher_resa(reservations);
			break;

		case 3:
			afficher_resa_spec(reservations);
			break;

		case 4:
			afficher_resa_client(reservations, clients);
			break;

		case 5:
			reservations = modifier_resa(reservations);
			break;

		case 6:
			reservations = annuler_reservation(reservations);
			break;

		case 7:
			afficher_resa_a_date(reservations);
			break;

		default:
			cout << "Choix invalide" << endl;
			break;
		}
	}
	return 0;
}