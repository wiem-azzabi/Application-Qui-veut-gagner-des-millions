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
    int tabjocker[4]={1,1,1,1};
    int level=1;



    public:
    joueur(string);
    void setscore(int& );
    void setgain(int& );

    int getid() const;
    void setid();

    string getnom() const;
	int getscore() const;
	void afficher() const;

	bool verif(const int&)const;
    void settabjocker(const int&);

};
#endif // JOUEUR_H
