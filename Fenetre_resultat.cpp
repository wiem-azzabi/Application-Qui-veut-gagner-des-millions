#include "Fenetre_resultat.h"
wxBEGIN_EVENT_TABLE(Fenetre_resultat, wxFrame)
EVT_CLOSE(Fenetre_resultat::onclose)
EVT_BUTTON(1000, onexit)

wxEND_EVENT_TABLE()
Fenetre_resultat::Fenetre_resultat(string nom, double score) : wxFrame(nullptr, wxID_ANY, "Resultat", wxPoint(300, 100), wxSize(1000, 700))
{
	exit = new wxButton(this, 1000, "Quitter", wxPoint(800, 605), wxSize(60, 30), wxBORDER_NONE);
	exit->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	exit->SetBackgroundColour(wxColor(0, 0, 0));
	exit->SetForegroundColour(wxColor(255, 255, 255));

	
	string ch;
	if (score == 0)
	{
		wxInitAllImageHandlers();
		wxBitmap TempBitmap;
		TempBitmap.LoadFile(wxT("gameover.jpg"), wxBITMAP_TYPE_JPEG);
		background* bg = new background(TempBitmap);
		this->PushEventHandler(bg);
	
	}
	else
	{
		wxInitAllImageHandlers();
		wxBitmap TempBitmap;
		TempBitmap.LoadFile(wxT("finals.jpg"), wxBITMAP_TYPE_JPEG);

		background* bg = new background(TempBitmap);
		this->PushEventHandler(bg);
		if ((score < 1000000) && (score >0))
		{
			int s2 = score;
			string s = to_string(s2);
			ch = "Bien joué, vous avez gagné " + s + " TND";
			text = new wxStaticText(this, wxID_ANY, ch, wxPoint(160, 300), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
			text->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD));
		}
		else
		{
			ch = "Félicitations! Vous êtes un MILLIONNAIRE!!";
			text = new wxStaticText(this, wxID_ANY, ch, wxPoint(160, 300), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
			text->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		}
	};
	
}

void Fenetre_resultat::onexit(wxCommandEvent& evt) {
	this->Close();
}
Fenetre_resultat::Fenetre_resultat(string nom, double score, string nom2, double score2) : wxFrame(nullptr, wxID_ANY, "Resultat", wxPoint(300, 100), wxSize(1000, 700))
{
	exit = new wxButton(this, 1000, "Exit", wxPoint(750, 600), wxSize(100, 40), wxBORDER_NONE);
	exit->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	exit->SetBackgroundColour(wxColor(0, 0, 0));
	exit->SetForegroundColour(wxColor(255, 255, 255));
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("finals.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	string ch;
	if ((score2 == 0) && (score==0))
	{
		ch = " Malheureusement vous avez perdu ";
	};
	if ((score2 == 0) && (score < 1000000) && (score > 500))
	{
		int s2 = score;
		string s = to_string(s2);
		ch = nom2 + " Malheureusement vous avez perdu \n Félicitations " + nom + " vous avez gagné" + s + "TND";
	};
	if ((score == 0) && (score2 < 1000000) && (score2 > 500))
	{
		int s2 = score2;
		string s = to_string(s2);
		ch = nom + " Malheureusement vous avez perdu \n Félicitations " + nom2 + " vous avez gagné" + s + "TND";
	};
	if ((score < 1000000) && (score > 500) && (score2 < 1000000) && (score2 > 500))
	{
		int s1 = score;
		string s11 = to_string(s1);
		int s2 = score2;
		string s = to_string(s2);
		ch = "Félicitations " + nom + " vous avez gagné" + s11 + "TND \n Félicitations " + nom2 + " vous avez gagné" + s + "TND";
	};
	if (score == 1000000)
	{
		int s2 = score2;
		string s = to_string(s2);
		ch = "Félicitations " + nom + " vous êtes MILLIONNAIRE!! \n Malheureusement pour vous, " + nom2 + " vous avez perdu";
	};
	if (score2 == 1000000)
	{
		int s2 = score;
		string s = to_string(s2);
		ch = "Félicitations " + nom2 + " vous êtes MILLIONNAIRE!! \n Malheureusement pour vous, " + nom + " vous avez perdu";
	};
	text = new wxStaticText(this, wxID_ANY, ch, wxPoint(95, 300), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	text->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

}
Fenetre_resultat::~Fenetre_resultat()
{
	delete text;
}
void Fenetre_resultat::onclose(wxCloseEvent& event)
{
	Destroy();
	this->PopEventHandler(true);
}