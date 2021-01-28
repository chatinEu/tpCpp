#include <iostream>
#include "magasin.h"
using namespace std;

int main()
{
    //Q3
    Magasin magasin;
    Produit p("ps4","console",2,500);
    Produit p2("ps5","console",0,500);
    Produit p3("xbox","console",100,400);
    magasin.addProduct(&p);
    magasin.addProduct(&p2);
    magasin.addProduct(&p3);
    magasin.showProduits("ps4");
    magasin.showProduits();
    std::cout <<endl;


    //Q4
    Client c1("g","guy");
    c1.addToPanier(p,2);
    c1.addToPanier(p3,10);
    c1.changeQuantityFromPanier(p,5);
    std::cout << c1;
    std::cout <<endl;


    //Q5
    Client c2("r","nop");
    c2.addToPanier(p3);
    c2.addToPanier(p);
    magasin.addClient(&c1);
    magasin.addClient(&c2);
    magasin.showClients();

    Client c3("r","encore moins");
    c3.addToPanier(p2);
    magasin.addClient(&c3);
    cout<<"cherche nom r \n";
    magasin.showClients("r");

    std::cout<<endl;
    magasin.deleteProductFromClientPanier(c2,p);
    magasin.showClients("r");
    magasin.modifyProductQuantityFromClientPanier(c2,p3,10);
    magasin.showClients(c2.getId());



    return 0;
}
//reste q5+
