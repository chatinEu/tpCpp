#include <string>

class Date{
public:
	//Date();
	Date(int d,int m,int y);
	int compare (Date d)const;
	void set(int d,int m,int y);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	std::string toString();
private:
	int _jour;
	int _mois;
	int _annee;
};
