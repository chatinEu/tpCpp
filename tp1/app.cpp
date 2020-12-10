
#include <iostream>
#include <vector>
#include "Client.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Reservation.h"
int main(){
	Date date=Date(5,5,1998);
	Date date2=Date(5,5,1999);
	//std::cout<<date.toString()<<std::endl;
	int iterator=0;
	//Client::_idIterator=iterator;
	Client c1("roar","boat",4);
	Client c2("bwate","rwar",2);
	std::cout<<"test"<<std::endl;
	std::cout<<c1.getId()<<"  "<<c2.getId()<<std::endl;

	Chambre ch1(1100,type::Suite);
	Chambre ch2(400,type::Single);
	Chambre ch3(200,type::Double);
	std::vector<Chambre> chList;
	chList.push_back(ch1);
	chList.push_back(ch2);
	chList.push_back(ch3);
	for (auto &&i : chList){	std::cout<<i.getId()<<"\n";}
	


	Hotel hotel(0,"hotel de bwate","los on roar",chList);
	Reservation reserv(date,date2,1,2,1);
	std::cout<<"price = "<<reserv.getPrice()<<std::endl;
	

}