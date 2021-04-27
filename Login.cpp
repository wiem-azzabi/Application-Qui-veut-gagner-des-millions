#include"Login.h"
#include"cMain.h"

using namespace std;

wxBEGIN_EVENT_TABLE(Login, wxFrame)
EVT_BUTTON(3001,onretour)
EVT_BUTTON(3002,onstartgame)
wxEND_EVENT_TABLE()


Login::Login() : wxFrame(nullptr, wxID_ANY, "Inscription", wxPoint(300, 100), wxSize(1000, 700))
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("login.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	bouton_retour = new wxButton(this, 3001, "Retour", wxPoint(380, 495), wxSize(70, 35),wxBORDER_NONE);
	bouton_retour->SetBackgroundColour(wxColor(0, 0, 0));
	bouton_retour->SetForegroundColour(wxColor(255, 255, 255));

	bouton_startgame = new wxButton(this, 3002, "Jouer", wxPoint(580, 495), wxSize(70, 35), wxBORDER_NONE);
	bouton_startgame->SetBackgroundColour(wxColor(0, 0, 0));
	bouton_startgame->SetForegroundColour(wxColor(255, 255, 255));

	champs_nom = new wxTextCtrl(this, 3003,"Inscrire Votre nom",wxPoint(400,395),wxSize(250,44), wxBORDER_NONE);
	champs_nom->SetBackgroundColour(wxColor(0, 0, 0));
	champs_nom->SetForegroundColour(wxColor(255, 255, 255));

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
	startgame* startgame_frame = new startgame(champs_nom->GetValue());
	startgame_frame->Show();
	evt.Skip();

}
