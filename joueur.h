#include "wx/wx.h"
#include <fstream>

using namespace std;
class joueur
{
private:
    int id;
    string nom;
    double score;

public:
    int tabjocker[4] = { 1,1,1,1 };


public:
    joueur(string);
    void setscore(int&);
    void setgain(int&);

    int getid() const;
    void setid();

    string getnom() const;
    int getscore() const;
    void afficher() const;

    bool verif(const int&)const; ///verif si jocker numero i est encore disponible (valeur 1)
    void settabjocker(const int&);///supprime le jocker numero i (valeur 0)

    //friend class startgame;

};
