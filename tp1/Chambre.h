#ifndef CHAMBRE_H
#define CHAMBRE_H




enum type {
    Single,
    Double,
    Suite
};
class Chambre{
    public:
        Chambre(int id,int prix,type type);

    private:
        int _id;
        type _type;
        int _prix;

};

#endif