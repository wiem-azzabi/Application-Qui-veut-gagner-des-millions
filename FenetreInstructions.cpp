#include "FenetreInstructions.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
#include"cMain.h"

using namespace std;
wxBEGIN_EVENT_TABLE(FenetreInstructions, wxFrame)
EVT_BUTTON(2000, onClick)
wxEND_EVENT_TABLE()

FenetreInstructions::FenetreInstructions():wxFrame(nullptr, wxID_ANY, "Instructions", wxPoint(300, 100), wxSize(1000, 700))
{
	string ch = "Instructions \n   ______________________________________________________________________________________ \n                                                                                                       \n Dans ce jeu vous allez trouvez 8 questions que vous devez les repondre correctement \n afin de gagner le maximum de score  \n ce jeu est limité par un temps (120s ) \n Vous allez le choix de choisir un joker parmi 4 pour chaque question \n chaque joker doit etre utilise une seul fois \n le premier joker : le switch(autoriser le changement de la question \n le deuxieme joker:LE 50/50 :ELIMINATION DE DEUX RÉPONSES FAUSSES \n le troisieme joker :apppel d'un ami \n le quatriéme joker : le vote du public ceci va etre afficher en pourcentage \n Si vous n'avez pas besoin de joker vous pouvez entrer zero \n                    Bonne chance                               \n   ______________________________________________________________________________________ \n tapez pour revenir a la page d'acceuil";
	text = new wxStaticText(this, wxID_ANY, ch,wxPoint(200,70));
	bouton_exit = new wxButton(this, 2000, "Retour", wxPoint(500, 500), wxSize(70, 40));
}

FenetreInstructions::~FenetreInstructions()
{
	delete text;
	delete bouton_exit;
}
void FenetreInstructions::onClick(wxCommandEvent& evt)
{
	this->Close();
	cMain* retour_frame=new cMain();
	retour_frame->Show();
	evt.Skip();
}


