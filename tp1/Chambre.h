#ifndef CHAMBRE_H
#define CHAMBRE_H




enum type {
    Single,
    Double,
    Suite
};
class Chambre{
    public:
        static int _idIterator;
        Chambre(int id,int prix,type type);
        Chambre(int prix,type type);
        Chambre();
        int getDailyPrice() const;
        int getId() const;
    private:
        int _id;
        type _type;
        int _prix;
};

#endif