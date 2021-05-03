#include "Fenetre_resultat.h"
wxBEGIN_EVENT_TABLE(Fenetre_resultat, wxFrame)
EVT_CLOSE(Fenetre_resultat::onclose)
wxEND_EVENT_TABLE()
Fenetre_resultat::Fenetre_resultat(string nom,double score) : wxFrame(nullptr, wxID_ANY, "Resultat", wxPoint(300, 100), wxSize(1000, 700))
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("finals.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);

	string ch;
	if (score <= 500)
	{
		ch = "\n \n Malheureusement vous avez perdu";
	}
	else
	{
		if ((score < 1000000) && (score>500))
		{
			int s2 = score;
			string s = to_string(s2);
			ch = "\n \n Bien joué, vous avez gagné " + s +"TND";
		}
		else
		{
			ch = "\n \n Félicitations! Vous êtes un MILLIONNAIRE!!";
		}
	};
	text = new wxStaticText(this, wxID_ANY, ch, wxPoint(390, 400), wxSize(200, 100), wxALIGN_CENTRE_HORIZONTAL);
	text->SetBackgroundColour(wxColor(237, 206, 106));
}
Fenetre_resultat::Fenetre_resultat(string nom, double score,string nom2, double score2) : wxFrame(nullptr, wxID_ANY, "Resultat", wxPoint(300, 100), wxSize(1000, 700))
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("finals.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);

	string ch;
	ch = "resultat duel";
	text = new wxStaticText(this, wxID_ANY, ch, wxPoint(390, 400), wxSize(200, 100), wxALIGN_CENTRE_HORIZONTAL);
	text->SetBackgroundColour(wxColor(237, 206, 106));
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
