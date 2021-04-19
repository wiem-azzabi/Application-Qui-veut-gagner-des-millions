#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <iomanip>//time
#include <ctime>
#include <Windows.h>//gotoxy
#include <conio.h>//getch
#include <MMsystem.h>
 using namespace std;
class joueur
{   private:
    int id;
	string nom;
	double score;

    public:
    joueur(string,int score=0);
    void setscore(int const&);
    int getid() const;
    void setid();
    string getnom() const;
	int getscore() const;
	void afficher() const;

};
#endif // JOUEUR_H
