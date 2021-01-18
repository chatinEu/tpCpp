
#include <iostream>
#include <vector>
#include "Client.h"
#include "Chambre.h"
#include "Hotel.h"
#include "Reservation.h"
#include <cassert>
using namespace std;
int main(){
	Date date=Date(5,5,1998);
	Date date2=Date(5,5,1999);
	//std::cout<<date.toString()<<std::endl;
	int iterator=0;
	//Client::_idIterator=iterator;
	Client c1(4,"roar","boat");
	Client c2(2,"bwate","rwar");
	std::cout<<"test"<<std::endl;
	std::cout<<c1.getId()<<"  "<<c2.getId()<<std::endl;
	assert(c1.getId()==4);
	assert(c2.getId()==2);

	
	Chambre ch1(1100,Chambre::_types::Suite,300);
	Chambre ch2(400,Chambre::_types::Simple,50);
	Chambre ch3(200,Chambre::_types::Double,120);
	std::vector<Chambre> chList;
	chList.push_back(ch1);
	chList.push_back(ch2);
	chList.push_back(ch3);
	for (auto &&i : chList){	std::cout<<i.getId()<<"\n";}
	


	Hotel hotel(0,"hotel de bwate","los on roar",chList);
	Reservation reserv(1,date,date2,hotel,c1,1);
	std::cout<<"price = "<<reserv.total()<<std::endl;
	
	
}