#include "cMain.h"


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
 EVT_BUTTON(1000, onexit)
 EVT_BUTTON(1001, onlogin)
 EVT_BUTTON(1002, onclick_liste_joueurs)
 EVT_BUTTON(1003, onclick_instructions)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Qui veut gagner des millions?", wxPoint(300, 100), wxSize(1000, 700)) 
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("pageloula.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	


	btn_login = new wxButton(this, 1001, "Jouer", wxPoint(415, 375), wxSize(160, 40), wxBORDER_NONE);
	btn_login->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	btn_login->SetBackgroundColour(wxColor(0, 0, 0));
	btn_login->SetForegroundColour(wxColor(255, 255, 255));

	bouton_liste_joueurs = new wxButton(this, 1002, "Historique des parties", wxPoint(415, 470), wxSize(165, 40), wxBORDER_NONE);
	bouton_liste_joueurs->SetFont(wxFont(13.5, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	bouton_liste_joueurs->SetBackgroundColour(wxColor(0, 0, 0));
	bouton_liste_joueurs->SetForegroundColour(wxColor(255, 255, 255));

	bouton_instructions= new wxButton(this, 1003, "Instructions", wxPoint(415,560), wxSize(160, 40), wxBORDER_NONE);
	bouton_instructions->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	bouton_instructions->SetBackgroundColour(wxColor(0, 0, 0));
	bouton_instructions->SetForegroundColour(wxColor(255, 255, 255));

	exit = new wxButton(this, 1000, "Exit", wxPoint(700, 600), wxSize(100, 40));
	exit->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));



	//this->SetBackgroundColour(wxColor(0,0,0));

}

cMain::~cMain() {

	delete btn_login;
	delete exit;
	delete bouton_liste_joueurs;
	delete bouton_instructions;

}

void cMain::onexit(wxCommandEvent& evt) {
	this->Close();
	evt.Skip();
}


void cMain::onlogin(wxCommandEvent& evt) {
	loginframe = new Login(); //constructeur de Login
	loginframe->Show();
	this->Close();
	evt.Skip();
}

void cMain::onclick_liste_joueurs(wxCommandEvent& evt) {
	FenetreJoueur_frame = new FenetreJoueur();
	FenetreJoueur_frame->Show();
	this->Close();
	evt.Skip();
}

void cMain::onclick_instructions(wxCommandEvent& evt) {
	Instructions_frame = new FenetreInstructions();
	Instructions_frame->Show();
	this->Close();
	evt.Skip();
}

