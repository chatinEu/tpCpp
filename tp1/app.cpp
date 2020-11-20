#include "Date.h"
#include <iostream>
#include "Client.h"
int main(){
	Date date=Date(5,5,1998);
	//std::cout<<date.toString()<<std::endl;
	int iterator=0;
	Client::_idIterator=iterator;

}