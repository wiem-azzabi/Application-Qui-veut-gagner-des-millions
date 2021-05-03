#include"Login.h"
#include"cMain.h"

using namespace std;

wxBEGIN_EVENT_TABLE(Login, wxFrame)
EVT_BUTTON(3001, onretour)
EVT_BUTTON(3002, onstartgame)
EVT_CLOSE(Login::onclose)
wxEND_EVENT_TABLE()


Login::Login(int mode) : wxFrame(nullptr, wxID_ANY, "Inscription", wxPoint(300, 100), wxSize(1000, 700))
{
	this->mode = mode;
	if (mode == 1)
	{
		wxInitAllImageHandlers();
		wxBitmap TempBitmap;
		TempBitmap.LoadFile(wxT("login.jpg"), wxBITMAP_TYPE_JPEG);

		background* bg = new background(TempBitmap);
		this->PushEventHandler(bg);
		bouton_retour = new wxButton(this, 3001, "Retour", wxPoint(375, 505), wxSize(70, 35), wxBORDER_NONE);
		bouton_retour->SetBackgroundColour(wxColor(0, 0, 0));
		bouton_retour->SetForegroundColour(wxColor(255, 255, 255));
		bouton_retour->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


		bouton_startgame = new wxButton(this, 3002, "Jouer", wxPoint(580, 505), wxSize(70, 35), wxBORDER_NONE);
		bouton_startgame->SetBackgroundColour(wxColor(0, 0, 0));
		bouton_startgame->SetForegroundColour(wxColor(255, 255, 255));
		bouton_startgame->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

		champs_nom = new wxTextCtrl(this, 3003, wxEmptyString, wxPoint(400, 395), wxSize(250, 44), wxBORDER_NONE);
		champs_nom->SetHint("Inscrire Votre nom");
		champs_nom->SetBackgroundColour(wxColor(0, 0, 0));
		champs_nom->SetForegroundColour(wxColor(255, 255, 255));
		champs_nom->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	}
	else
	{
		wxInitAllImageHandlers();
		wxBitmap TempBitmap;
		TempBitmap.LoadFile(wxT("login.jpg"), wxBITMAP_TYPE_JPEG);

		background* bg = new background(TempBitmap);
		this->PushEventHandler(bg);
		bouton_retour = new wxButton(this, 3001, "Retour", wxPoint(375, 505), wxSize(70, 35), wxBORDER_NONE);
		bouton_retour->SetBackgroundColour(wxColor(0, 0, 0));
		bouton_retour->SetForegroundColour(wxColor(255, 255, 255));
		bouton_retour->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));


		bouton_startgame = new wxButton(this, 3002, "Jouer", wxPoint(580, 505), wxSize(70, 35), wxBORDER_NONE);
		bouton_startgame->SetBackgroundColour(wxColor(0, 0, 0));
		bouton_startgame->SetForegroundColour(wxColor(255, 255, 255));
		bouton_startgame->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

		champs_nom = new wxTextCtrl(this, 3003, wxEmptyString, wxPoint(400, 395), wxSize(250, 44), wxBORDER_NONE);
		champs_nom->SetHint("Nom du joueur 1");
		champs_nom->SetBackgroundColour(wxColor(0, 0, 0));
		champs_nom->SetForegroundColour(wxColor(255, 255, 255));
		champs_nom->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

		champs_nom2 = new wxTextCtrl(this, 3004, wxEmptyString, wxPoint(100, 495), wxSize(250, 44), wxBORDER_NONE);
		champs_nom2->SetHint("Nom du joueur 2");
		champs_nom2->SetBackgroundColour(wxColor(0, 0, 0));
		champs_nom2->SetForegroundColour(wxColor(255, 255, 255));
		champs_nom2->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	}
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


}
void Login::onstartgame(wxCommandEvent& evt)
{
	if (mode == 1)
	{
		this->Close();
		startgame* startgame_frame = new startgame(champs_nom->GetValue());
		startgame_frame->Show();
	}
	else
	{
		this->Close();
		startgameduel* startgame_frame = new startgameduel(champs_nom->GetValue(), champs_nom2->GetValue());
		startgame_frame->Show();
	}


}
void Login::onclose(wxCloseEvent& event)
{
	Destroy();
	this->PopEventHandler(true);
}