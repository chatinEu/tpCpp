#include "Date.h"


Date::Date(int day,int month,int year){
	_jour=day;
	_mois=month;
	_annee=year;
}

/**
*	compare 2 objets date
*	retourne 0 si meme jour
*	<0 si objet comparé plus loin en date
*
*/
int Date::compare(Date d) const{
	int tmp=0;
	tmp	=	_annee 	- 	d._annee*365;
	tmp+=	_mois 	- 	d._mois*30;
	tmp+=	_jour 	- 	d._jour;
	return tmp;
}

std::string Date::toString(){
	std::string str=std::to_string( getDay() )+"/"+
			std::to_string( getMonth())+"/"+
			std::to_string( getYear());
	return str;
}
int Date::getDay()const{
	return _jour;
}
int Date::getMonth()const{
	return _mois;
}
int Date::getYear()const{
	return _annee;
}

