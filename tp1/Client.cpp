#include "Client.h"
using namespace std;
int Client::_idIterator=0;
Client::Client(string nom,string prenom): _nom(nom),_prenom(prenom),_id(_idIterator){}
Client::Client(string nom,string prenom,int id): _nom(nom),_prenom(prenom),_id(id){}

int Client::getId() const{
    return _id;
}