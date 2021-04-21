#include "cMain.h"
#include "startgame.h" // Needed to create startgame frame
#include "startgamedouble.h"
#include "FenetreInstructions.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
 EVT_BUTTON(1000, onexit)
 EVT_BUTTON(1001, onstartgame)
 EVT_BUTTON(1004, onstartgamedouble)
 EVT_BUTTON(1002, onclick_liste_joueurs)
 EVT_BUTTON(1003, onclick_instructions)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Qui veut gagner des millions?", wxPoint(300, 100), wxSize(1000, 700)) 
{
	

	title = new wxStaticText(this, wxID_ANY, "Qui veut ganger des millions?", wxPoint(100, 100));
	title->SetFont(wxFont(44, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	btn_startgame = new wxButton(this, 1001, "Jouer", wxPoint(300, 300), wxSize(400, 40));
	btn_startgame->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	btn_startgame = new wxButton(this, 1004, "Jouer en deux", wxPoint(300, 350), wxSize(400, 40));
	btn_startgame->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


	bouton_liste_joueurs = new wxButton(this, 1002, "Historique des parties", wxPoint(300, 450), wxSize(400, 40));
	bouton_liste_joueurs->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	bouton_instructions= new wxButton(this, 1003, "Instructions", wxPoint(300,500), wxSize(400, 40));
	bouton_instructions->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	exit = new wxButton(this, 1000, "Exit", wxPoint(700, 600), wxSize(100, 40));
	exit->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	this->SetBackgroundColour(wxColor(143,132,255));

}

cMain::~cMain() {
	delete title;
	delete btn_startgame;
	delete exit;
	delete bouton_liste_joueurs;
	delete bouton_instructions;

	delete btn_startgamedouble;
}

void cMain::onexit(wxCommandEvent& evt) {
	this->Close();
	evt.Skip();
}

void cMain::onstartgame(wxCommandEvent& evt) {
	startgame_frame = new startgame(); //constructeur de startgame
	startgame_frame->Show();
	this->Close();
	evt.Skip();
}
void cMain::onstartgamedouble(wxCommandEvent& evt) {
	startgamedouble_frame = new startgamedouble(); //constructeur de startgamedouble
	startgamedouble_frame->Show();
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