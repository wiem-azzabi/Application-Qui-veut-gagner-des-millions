#include "joueur.h"
#include <string.h>
#include <string>
#include <iostream>
#include <cstdlib>//random
using namespace std;

joueur::joueur(string ch,int score)
{
    nom=ch;
}


    void joueur::setscore(int const& a)
    {
        score+=(a+1)*1000;
    }
    int joueur::getid() const
    {
        return id;
    }
    void joueur::setid()
	{int x;

        ifstream entree ("id.txt",ios::in);
    if(entree)
    {
        string ligne;
        string ch;

      while(getline(entree, ligne))
      {
          if(!ligne.empty())
            ch=ligne;
      };
    cout<<ligne;
      x=stoi(ch)+1;
      id=x;
      cout<<x;

   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   entree.close();
   ofstream sortie("id.txt",ios::app);
   sortie<<x<<endl;
   sortie.close();
}


    string joueur::getnom() const
	{
	    return(nom);
    }
	int joueur::getscore() const
	{
	    return(score);
    }
	void joueur::afficher() const
    {
	cout<<id<<setw(15)<<nom<<setw(10)<<score<<setw(6)<<endl;
    }
