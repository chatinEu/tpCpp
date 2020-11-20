#include "Date.h"
#include <iostream>
#include "Client.h"
int main(){
	Date date=Date(5,5,1998);
	//std::cout<<date.toString()<<std::endl;
	int iterator=0;
	//Client::_idIterator=iterator;
	Client c1("roar","boat",4);
	Client c2("bwate","rwar",2);
	std::cout<<"test"<<std::endl;
	std::cout<<c1.getId()<<"  "<<c2.getId()<<std::endl;
	

}