#include "Fenetre_resultat.h"

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
			ch = "\n \n Bien jou�, vous avez gagn� " + s +"TND";
		}
		else
		{
			ch = "\n \n F�licitations! Vous �tes un MILLIONNAIRE!!";
		}
	};
	text = new wxStaticText(this, wxID_ANY,ch, wxPoint(300, 250), wxSize(200, 100),wxALIGN_CENTRE_HORIZONTAL);
	text->SetBackgroundColour(wxColor(237, 206, 106));
}
Fenetre_resultat::~Fenetre_resultat()
{
	delete text;
}
