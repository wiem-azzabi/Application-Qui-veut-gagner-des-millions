#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <iomanip>//time
#include <ctime>
#include <Windows.h>//gotoxy
#include <conio.h>//getch et _getch
#include <MMsystem.h>//sound
#include "joueur.h"

using namespace std;
void gotoXY(int x, int y) 	//function to decide location of the screem
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

enum color{ //enumeration is a user-defined data type
	NONE,DARK_BLUE,GREEN,DARK_CYAN,DARK_RED,PURPLE,
	DARK_YELLOW,NORMAL,GRAY,BLUE,LIME,CYAN,RED,PINK,
	YELLOW,WHITE
};

void setcolor(color newColor)//couleur du texte
{
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (newColor ) );
};




void jeu(joueur j1)
     {
      string ligne;
    string ligne2;//les proposition apres 50/50
    string ligne3;//les lignes du fichier avix publique;

ifstream entree ("questions.txt",ios::in );
ifstream entree2("avispublique.txt",ios::in);
cout<<"\n \n"<<endl;
      if(entree && entree2)
                {
            std::clock_t start;
            start = std::clock();
            double duration=0;
            double maxtime=60;//en secondes
            int n=0;
            while(duration<maxtime)
            {

               while(n<15)//pour chaque question
                {doo:

                string* tab=new string[3];
                int i=0;
                while(i<3)
                    {getline(entree, ligne); //On lit une ligne complète et l'enregistre dans "ligne"
                    getline(entree2,ligne3);
                    tab[i]=ligne3;
                    setcolor(DARK_YELLOW);
                    cout<<"         "<<ligne<<endl;
                    ligne2=ligne;
                    i++;
                    }
                setcolor(WHITE);
                getline(entree,ligne);
                jocker:
                cout<<"\n         tapez numero jocker \n         |0) aucun jocker | 1) switch | 2) 50/50 | 3)appel ami | 4) avis publique"<<endl;
                cout<<"         vous disposez de: \n         ||switch ("<<j1.tabjocker[0]<<") ||50/50 ("<<j1.tabjocker[1]<<") ||appel ami ("<<j1.tabjocker[2]<<") ||avis publique ("<<j1.tabjocker[3]<<")"<<endl;

          int x;
          do
          {
              cin>>x;
          }while (x!=0&&x!=1&&x!=2&&x!=3&&x!=4);


          switch(x)
          {case 0:
              goto rep;
          case 1:
                if(j1.verif(0))
                    {j1.settabjocker(0);
                    n++;
                    goto doo;}
                else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                break;

          case 2:
            //jocker 50/50
               if(j1.verif(1))
               {j1.settabjocker(1);
                setcolor(DARK_YELLOW);cout<<"              "<<ligne2<<endl;setcolor(WHITE);
                goto rep;}
               else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
            break;

           case 3:
           //appel ami
                if (j1.verif(2))
                {
                j1.settabjocker(2);
               cout<<"         Votre ami dit: «Je suis tenté de vous laisser pendre parce que c'est trop facile. Comment pouvez-vous être confus? La bonne réponse est " ;
               setcolor(DARK_YELLOW);cout<<ligne<<endl;setcolor(WHITE);
               goto rep;}
                else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
            break;
          case 4:
                //avispublic
                if (j1.verif(3))
                {j1.settabjocker(3);
                for(int i=1;i<3;i++)
                {setcolor(DARK_YELLOW);cout<<"                   "<<tab[i]<<endl;setcolor(WHITE);}
                goto rep;
                }


                 else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                     break;
          }


                rep:

                cout<<"                 entrer votre reponse "<<endl;
                string reponse;
                cin>>reponse;

                if (ligne.rfind(reponse)==0)
                    {setcolor(GREEN); cout<<"            bonne reponse"<<endl;
                     j1.setgain(j1.level);///***
                     //cout<<"level "<<level<<endl;
                    }
                else
                    {
                        setcolor(RED); cout<<"            mauvaise reponse"<<endl;
                        j1.setscore(j1.level);///***
                        n=15;
                    }
                duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                setcolor(BLUE);
                cout << "          temps restant: "<<maxtime-duration<<endl;
                if (duration>=maxtime)
                    {cout<<"time out"<<endl;
                    break;
                    };

                if ((n+1)%5==0) ///****
                {
                    j1.level++;
                };

                n++;};//while n
            break;}//while time
        }//if entree

    int score=j1.getscore();
    string nom=j1.getnom();
    int id=j1.getid();
    ofstream sortie ("joueur.txt",ios::app);
    sortie<<"nom:  "<<nom<<setw(10)<<"id:  "<<id<<setw(10)<<"score:  "<<score<<endl;
    sortie.close();
    entree.close();
    entree2.close();


    system("CLS");///***affichage score****


		setcolor(BLUE);
		gotoXY(20,5);
	    cout<<"***************FIN DU JEU******************"<<endl;
	    gotoXY(20,6);
        cout<<j1.getnom()<<"  ,  vous avez gagné   "<<j1.getscore()<<" TND "<<endl;
        gotoXY(20,7);
        cout<<"**************************************"<<endl;
        setcolor(WHITE);
     };//fin jeu


     void jeuduel(joueur j1, joueur j2 )
     {
      string ligne;
    string ligne2;//les proposition apres 50/50
    string ligne3;//les lignes du fichier avix publique;

ifstream entree ("questions.txt",ios::in );
ifstream entree2("avispublique.txt",ios::in);
cout<<"\n \n"<<endl;
      if(entree && entree2)
                {
            std::clock_t start;
            start = std::clock();
            double duration=0;
            double maxtime=120;//en secondes
            int n=0;
            int x1=0;
            int x2=0;
            while(duration<maxtime)
            {

               while(n<15)//pour chaque question
                {doo:
                string* tab=new string[3];
                int i=0;
                while(i<3)
                    {getline(entree, ligne); //On lit une ligne compl�te et l'enregistre dans "ligne"
                    getline(entree2,ligne3);
                    tab[i]=ligne3;
                    setcolor(DARK_YELLOW);
                    cout<<"         "<<ligne<<endl;
                    ligne2=ligne;
                    i++;
                    }
                setcolor(WHITE);
                getline(entree,ligne);

            foo:
          setcolor(BLUE);cout<<" Cliquez pour decrocher votre tour "<<endl;setcolor(WHITE);
          char player=0; ///tour du quel joueur
          do
          {
              player=_getch();
          }
          while (player!=97&& player!=112 ); /// saisie de A ou P

          if (player==97)
            cout<<"c'est le tour du joueur 1 "<<j1.getnom()<<endl;
          else
          cout<<"c'est le tour du joueur 2 "<<j2.getnom()<<endl;
          jocker:
         cout<<"\n         tapez numero jocker(0: aucun jocker 1:switch 2: 50/50 3:appel ami 4: avis publique)"<<endl;
          if (player==97)
           cout<<"         vous disposez de: \n         ||switch ("<<j1.tabjocker[0]<<") ||50/50 ("<<j1.tabjocker[1]<<") ||appel ami ("<<j1.tabjocker[2]<<") ||avis publique ("<<j1.tabjocker[3]<<")"<<endl;

          else
            cout<<"         vous disposez de: \n         ||switch ("<<j2.tabjocker[0]<<") ||50/50 ("<<j2.tabjocker[1]<<") ||appel ami ("<<j2.tabjocker[2]<<") ||avis publique ("<<j2.tabjocker[3]<<")"<<endl;
          int x;///numero jocker
          do
          {
              cin>>x;
          }while (x!=0&&x!=1&&x!=2&&x!=3&&x!=4);
         switch(x)
          {case 0:
              switch(player)
              {
                case 97: goto rep;
                case 112: goto rep ;}
          case 1://jocker switch
               switch(player)
               {case 97:
                  if(j1.verif(0))
                    {j1.settabjocker(0);
                    ///*
                    setcolor(DARK_YELLOW);cout<<"De l’œuvre de quel écrivain est tirée la célèbre question « Que sais-je ? » "
                    <<"a)Diderot b)Voltaire c)Montaigne d)Étienne de la Boétie"<<endl;setcolor(WHITE);

                    cout<<"                 entrer votre reponse "<<endl<<"     ";
                string reponse;
                string ligne="c";
                cin>>reponse;
                if (ligne.rfind(reponse)==0)
                    {setcolor(GREEN); cout<<"            bonne reponse"<<endl;
                        j1.setgain(j1.level);}
                else
                    {setcolor(RED); cout<<"            mauvaise reponse"<<endl;
                    j1.setscore(j1.level);break;}
                    }

                  else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                break;
                case 112:
                  if(j2.verif(0))
                    {j2.settabjocker(0);

                    setcolor(DARK_YELLOW);cout<<"Où est né Mozart ? a)Venise b)Turin c)Vienne d)Salzbourg"<<endl;setcolor(WHITE);

                    cout<<"                 entrer votre reponse "<<endl<<"     ";
                string reponse;
                string ligne="d";
                cin>>reponse;
                if (ligne.rfind(reponse)==0)
                    {setcolor(GREEN); cout<<"            bonne reponse"<<endl;
                        x2++;
                        j2.setgain(j2.level);}
                else
                    {setcolor(RED); cout<<"            mauvaise reponse"<<endl;
                    j2.setscore(j2.level);
                    break;
                    }}
                  else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                break;
               }
            goto doo;
            break;
          case 2:
            //jocker 50/50
                switch(player)
               {case 97:
                  if(j1.verif(1))
                    {j1.settabjocker(0);
                    setcolor(DARK_YELLOW);cout<<"              "<<ligne2<<endl;setcolor(WHITE);
                     goto rep;}
                  else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilis� ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                case 112:
                  if(j2.verif(1))
                    {j2.settabjocker(0);
                   setcolor(DARK_YELLOW);cout<<"              "<<ligne2<<endl;setcolor(WHITE);
                   goto rep;}
                else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilis� ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}};


            break;
           case 3:
           //appel ami
           switch(player)
               {case 97:
                  if(j1.verif(2))
                    {j1.settabjocker(0);
                    cout<<"         Votre ami dit: �Je suis tent� de vous laisser pendre parce que c'est trop facile. Comment pouvez-vous �tre confus? La bonne r�ponse est " ;
                    setcolor(DARK_YELLOW);cout<<ligne<<endl;setcolor(WHITE);
                    goto rep;}
                  else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilis� ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                case 112:
                  if(j2.verif(2))
                    {j2.settabjocker(0);
                   cout<<"         Votre ami dit: �Je suis tent� de vous laisser pendre parce que c'est trop facile. Comment pouvez-vous �tre confus? La bonne r�ponse est " ;
                   setcolor(DARK_YELLOW);cout<<ligne<<endl;setcolor(WHITE);
                   goto rep;}
                else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilis� ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}};
            break;
          case 4: //avispublic
            switch(player)
               {case 97:
                  if(j1.verif(3))
                    {j1.settabjocker(0);
                     for(int i=1;i<3;i++)
                    {setcolor(DARK_YELLOW);cout<<"                   "<<tab[i]<<endl;setcolor(WHITE);}
                    goto rep;;}
                  else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}
                case 112:
                  if(j2.verif(3))
                    {j2.settabjocker(0);
                    for(int i=1;i<3;i++)
                     {setcolor(DARK_YELLOW);cout<<"                   "<<tab[i]<<endl;setcolor(WHITE);}
                      goto rep;}
                else
                    {setcolor(DARK_RED);cout<<"         jocker deja utilisé ! retapez un jocker "<<endl;setcolor(WHITE);
                     goto jocker;}};}break;


                rep:

                cout<<"                 entrer votre reponse "<<endl;
                string reponse;
                cin>>reponse;
                if (ligne.rfind(reponse)==0)
                    {setcolor(GREEN); cout<<"            bonne reponse"<<endl;
                     switch (player)
                        {case 97 :
                                {x1++;
                                j1.setgain(j1.level);
                                break;
                                }
                         case 112 :
                             {  x2++;
                                j2.setgain(j2.level);
                                break;}
                        };
                    }
                else
                    {setcolor(RED); cout<<"            mauvaise reponse"<<endl;
                    switch (player)
                        {case 97 : {j1.setscore(j1.level);break;}
                         case 112 :  {j2.setscore(j2.level);break;}
                        };

                    }
                duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                setcolor(BLUE);
                cout << "          temps restant: "<<maxtime-duration<<endl;
                if (duration>=maxtime)
                    {cout<<"time out"<<endl;
                    break;
                    };
                if ((x1+1)%5==0) ///****
                {
                    j1.level++;
                };
                 if ((x2+1)%5==0) ///****
                {
                    j2.level++;
                };
                n++; };//while n
            }//while time
        }//if entree
    int score=j1.getscore();
    int score2=j2.getscore();
    string nom=j1.getnom();
    string nom2=j2.getnom();
    int id=j1.getid();
    int id2=j2.getid();
    ofstream sortie ("joueur.txt",ios::app);
    sortie<<"nom:  "<<nom<<setw(10)<<"id:  "<<id<<setw(10)<<"score:  "<<score<<endl;
    sortie<<"nom:  "<<nom2<<setw(10)<<"id:  "<<id2<<setw(10)<<"score:  "<<score2<<endl;
    sortie.close();
    entree.close();
    entree2.close();


    system("CLS");///***affichage score****



	    if (j1.getscore()>j2.getscore())
        {
        setcolor(BLUE);
		gotoXY(20,5);
	    cout<<"**************************************"<<endl;
	    gotoXY(20,6);
	    setcolor(YELLOW);
	    cout<<"Felicitations "<<j1.getnom()<<" !!,  vous avez gagn�   "<<j1.getscore()<<" TND "<<endl;
	    gotoXY(20,7);
	    setcolor(BLUE);
	    cout<<j2.getnom()<<" votre score est "<<j2.getscore()<<"  ,  Ne perdez pas espoir! "<<endl;
        gotoXY(20,8);
        cout<<"**************************************"<<endl;
        setcolor(WHITE);
        }
        else
        {
        setcolor(BLUE);
		gotoXY(20,5);
	    cout<<"**************************************"<<endl;
	    gotoXY(20,6);
	    setcolor(YELLOW);
	    cout<<"Felicitations "<<j2.getnom()<<"  ,  vous avez gagné   "<<j2.getscore()<<" TND "<<endl;
	    gotoXY(20,7);
	    setcolor(BLUE);
	    cout<<j1.getnom()<<"votre score est "<<j1.getscore()<<"  ,  Ne perdez pas espoir! "<<endl;
        gotoXY(20,8);
        cout<<"**************************************"<<endl;
        setcolor(WHITE);
        }
     };///fin jeuduel

void pageinstructions()
{
	setcolor(RED);
	gotoXY(56,4);
		cout<<"Instruction"<<endl;

		setcolor(BLUE);
		gotoXY(20,6);
		cout<<"   ______________________________________________________________________________________"<<endl;
		gotoXY(28,7);
		cout<<" Selection==>                                                                                                       "<<endl;
		gotoXY(28,9);
		cout<<"Dans ce jeu vous allez trouvez 8 questions que vous devez les repondre correctement "<<endl;
		gotoXY(28,10);
		cout<<"afin de gagner le maximum de score  "<<endl;
		gotoXY(28,11);
		cout<<"ce jeu est limit� par un temps (120s )"<<endl;
		gotoXY(28,13);
		cout<<"Vous allez le choix de choisir un joker parmi 4 pour chaque question"<<endl;
		gotoXY(28,14);
		cout<<"chaque joker doit etre utilise une seul fois"<<endl;
		gotoXY(28,15);
		cout<<"le premier joker : le switch(autoriser le changement de la question "<<endl;
		gotoXY(28,16);
		cout<<"le deuxieme joker:LE 50/50 :ELIMINATION DE DEUX R�PONSES FAUSSES"<<endl;
		gotoXY(28,17);
		cout<<"le troisieme joker :apppel d'un ami"<<endl;
		gotoXY(28,18);
		cout<<"le quatri�me joker : le vote du public ceci va etre afficher en pourcentage"<<endl;
		gotoXY(28,19);
		cout<<"Si vous n'avez pas besoin de joker vous pouvez entrer zero"<<endl;
		gotoXY(28,21);
		setcolor(RED);
		cout<<"                   Bonne chance                               "<<endl;
		gotoXY(20,22);
		setcolor(BLUE);
	    cout<<"   ______________________________________________________________________________________"<<endl;
		gotoXY(31,25);
		setcolor(YELLOW);
		cout<<"tapez pour revenir a la page d'acceuil";

}//fin page instructions

void pagescores()
{
    ifstream entree ("joueur.txt",ios::in);
    if(entree)
    {
         string ligne;

      while(getline(entree, ligne))
      {
         cout << ligne << endl;
      }
      		cout<<"tapez pour revenir a la page d'acceuil";

   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
}



void home()
{   home:
    void pagejeu();
    void pagejeuduel();
    void pageinstructions();
    void pagescores();
	system("CLS");
						setcolor(DARK_YELLOW);


cout<<"$$\\      $$\\   $$$$$$$$\\   $$\\         $$$$$$\\     $$$$$$\\    $$\\      $$\\   $$$$$$$$\\ "<<endl;
cout<<"$$ | $\\  $$ |  $$  _____|  $$ |       $$  __$$\\   $$  __$$\\   $$$\\    $$$ |  $$  _____|"<<endl;
cout<<"$$ |$$$\\ $$ |  $$ |        $$ |       $$ /  \\__|  $$ /  $$ |  $$$$\\  $$$$ |  $$ |      "<<endl;
cout<<"$$ $$ $$\\$$ |  $$$$$\\      $$ |       $$ |        $$ |  $$ |  $$\\$$\\$$ $$ |  $$$$$\\    "<<endl;
cout<<"$$$$  _$$$$ |  $$  __|     $$ |       $$ |        $$ |  $$ |  $$ \\$$$  $$ |  $$  __|   "<<endl;
cout<<"$$$  / \\$$$ |  $$ |        $$ |       $$ |  $$\\   $$ |  $$ |  $$ |\\$  /$$ |  $$ |      "<<endl;
cout<<"$$  /   \\$$ |  $$$$$$$$\\   $$$$$$$$\\  \\$$$$$$  |   $$$$$$  |  $$ | \\_/ $$ |  $$$$$$$$\\ "<<endl;
cout<<"\\__/     \\__|  \\________|  \\________|  \\______/    \\______/   \\__|     \\__|  \\________|"<<endl;




	setcolor(WHITE);

	gotoXY(30,10);
	cout<<"======Menu ======";
	gotoXY(35,12);
	cout<<"1) Nouveau jeu";
	gotoXY(35,13);
	cout<<"2)  Instructions";
	gotoXY(35,14);
	cout<<"3)  Scores";
	gotoXY(25,16);
	cout<<"Tapez chiffre: ";

	go:
	int page;
	gotoXY(40,16);
	cin>>page;
	switch(page)
	{
		case 1:
			{system("CLS");
			gotoXY(50,8);
			cout<<"saisir mode du jeu"<<endl;
			gotoXY(52,9);
			cout<<"1 joueur"<<endl;
			gotoXY(52,10);
			cout<<"2 joueurs"<<endl;
			gotoXY(52,12);
			int n=1;
			do{
			cin>>n;
			}while (n!=1 && n!=2);
			system("CLS");
			switch(n)
			{
			    case 1:
			        pagejeu();
			        break;
                case 2:
                    pagejeuduel();
                    break;

			}

			break;
			}
	    case 2:
			{
			system("CLS");

			pageinstructions();
                _getch();

                goto home;

			break;
			}
        case 3:
			{
			system("CLS");
			pagescores();
			_getch();
			goto home ;
			break;
			}

		 default:

			cout<<"/n INVALID CHOICE";
			goto go;
	}
};//fin home()

 void pagejeu()
    {
    string nom;
    gotoXY(50,12);
    cout<<"entrer votre nom"<<endl;
    gotoXY(53,13);
    cin>>nom;

    joueur j1(nom);
    j1.setid();

    system("CLS");
    jeu(j1);
    };
 void pagejeuduel()
    {
    gotoXY(46,4);
    cout<<"*****************************"<<endl;
    gotoXY(46,5);
    cout<<"joueur 1 utilisera la touche A"<<endl;
    gotoXY(46,6);
    cout<<"joueur 2 utilisera la touche P"<<endl;
    gotoXY(46,7);
    cout<<"*******************************"<<endl;
    gotoXY(50,8);
    cout<<"entrer nom joueur 1"<<endl;
    gotoXY(50,9);
    string nom ;
    cin>>nom;
    gotoXY(50,10);
    cout<<"entrer nom joueur 2"<<endl;
    gotoXY(50,11);
    string nom2 ;
    cin>>nom2;
    joueur j1(nom);
    joueur j2(nom2);
    j1.setid();
    j2.setid();

    system("CLS");
    jeuduel(j1,j2);
    };
int main()
{   //PlaySound(TEXT("Sound.wav"), NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);
    home();
    return 0;
}

