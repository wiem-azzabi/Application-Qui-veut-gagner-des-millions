#include "FenetreJoueur.h"
#include <iostream>
#include <fstream>
#include"cMain.h"

using namespace std;

wxBEGIN_EVENT_TABLE(FenetreJoueur, wxFrame)
EVT_BUTTON(2001, onClick)
EVT_CLOSE(FenetreJoueur::onclose)
wxEND_EVENT_TABLE()


FenetreJoueur::FenetreJoueur(): wxFrame(nullptr, wxID_ANY, "Scores", wxPoint(300, 100), wxSize(1000, 700))
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("historique.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	listejoueur = new wxListBox(this, wxID_ANY, wxPoint(170,270),wxSize(700,300));

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

bouton_exit = new wxButton(this, 2001, "Retour", wxPoint(450, 605), wxSize(80,40),wxBORDER_NONE);
bouton_exit->SetBackgroundColour(wxColor(0, 0, 0));
bouton_exit->SetForegroundColour(wxColor(255, 255, 255));
bouton_exit->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
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

}
void FenetreJoueur::onclose(wxCloseEvent& event)
{
	Destroy();
	this->PopEventHandler(true);
}