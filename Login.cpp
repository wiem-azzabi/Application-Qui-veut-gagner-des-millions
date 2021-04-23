#include"Login.h"
#include"cMain.h"

using namespace std;

wxBEGIN_EVENT_TABLE(Login, wxFrame)
EVT_BUTTON(3001,onretour)
EVT_BUTTON(3002,onstartgame)
wxEND_EVENT_TABLE()


Login::Login() : wxFrame(nullptr, wxID_ANY, "Inscription", wxPoint(300, 100), wxSize(1000, 700))
{
	bouton_retour = new wxButton(this, 3001, "Retour", wxPoint(400, 300), wxSize(70, 40));
	bouton_startgame = new wxButton(this, 3002, "Jouer", wxPoint(500, 300), wxSize(70, 40));
	champs_nom = new wxTextCtrl(this, 3003,"Inscrire Votre nom",wxPoint(300,200),wxSize(400,44));
	this->SetBackgroundColour(wxColor(143, 132, 255));

}

Login::~Login()
{
	delete champs_nom;
	delete bouton_retour;
	delete bouton_startgame;
}

void Login::onretour(wxCommandEvent& evt)
{
	this->Close();
	cMain* retour_frame = new cMain();
	retour_frame->Show();
	evt.Skip();

}
void Login::onstartgame(wxCommandEvent& evt)
{
	this->Close();
	startgame* startgame_frame = new startgame();
	startgame_frame->Show();
	evt.Skip();

}
/*void cMain::onstartgame(wxCommandEvent& evt) {
	startgame_frame = new startgame(); //constructeur de startgame
	startgame_frame->Show();
	this->Close();
	evt.Skip();
}*/