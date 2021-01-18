#include <iostream>
#include "magasin.h"
using namespace std;

int main()
{
    Magasin magasin;
    Produit p("ps4","console",2,500);
    Produit p2("ps5","console",0,500);
    Produit p3("xbox","console",100,400);
    magasin.addProduct(&p);
    magasin.addProduct(&p2);
    magasin.addProduct(&p3);
    //magasin.showProduits("ps4");
    magasin.showProduits();
    return 0;
}
