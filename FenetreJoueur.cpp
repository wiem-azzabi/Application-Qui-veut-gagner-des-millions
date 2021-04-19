#include "FenetreJoueur.h"
#include <iostream>
#include <fstream>
#include"cMain.h"
using namespace std;

wxBEGIN_EVENT_TABLE(FenetreJoueur, wxFrame)
EVT_BUTTON(2001, onClick)
wxEND_EVENT_TABLE()


FenetreJoueur::FenetreJoueur(): wxFrame(nullptr, wxID_ANY, "Scores", wxPoint(300, 100), wxSize(1000, 700))
{
	listejoueur = new wxListBox(this, wxID_ANY, wxPoint(50, 50),wxSize(700,300));

ifstream entree("joueur.txt", ios::in);
if (entree)
{
	string ligne;

	while (getline(entree, ligne))
	{
		listejoueur->AppendString(ligne);
	}
	//button
}
else
{
	wxMessageBox(wxT("ERREUR: Impossible d'ouvrir le fichier en lecture."), "Warning!", wxICON_WARNING);
}

bouton_exit = new wxButton(this, 2001, "Retour", wxPoint(300, 400), wxSize(70, 40));
}

FenetreJoueur::~FenetreJoueur()
{
	delete listejoueur;
}

void FenetreJoueur::onClick(wxCommandEvent& evt)
{
	this->Close();
	cMain* retour_frame = new cMain();
	retour_frame->Show();
	evt.Skip();

}