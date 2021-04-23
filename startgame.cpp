
#include "startgame.h"


using namespace std;

wxBEGIN_EVENT_TABLE(startgame, wxFrame)
EVT_BUTTON(1000, onnext)
EVT_BUTTON(1001, onverify)
EVT_CLOSE(startgame::onclose)
END_EVENT_TABLE()
startgame::startgame() : wxFrame(nullptr, wxID_ANY, "", wxPoint(0, 0), wxSize(2000, 900)) {
	wxFont font1 = wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	///background
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("pattern.bmp"), wxBITMAP_TYPE_BMP);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);

	///tableau des questions
	ifstream entree("questions2.txt", ios::in);
	if (entree)
	{
		string ligne;
		for (int i = 0; i < 15; i++)		//i:numeroquestion 
			for (int j = 0; j < 6; j++)
			{
				getline(entree, ligne);
				T[i][j] = ligne;
			}
	}
	else
	{
		wxMessageBox(wxT("ERREUR: Impossible d'ouvrir le fichier en lecture."), "Warning!", wxICON_WARNING);
	};

	///initialiser joueur 
	j1=new joueur("nom");
	j1->setid();
	wxMessageBox(j1->getnom());


	///les elements du frame
	questiontitle = new wxStaticText(this, wxID_ANY, "", wxPoint(300, 458));
	questiontitle->SetFont(font1);
	questiontitle->SetForegroundColour(wxColour(255, 255, 255));

	questioncount_text = new wxStaticText(this, wxID_ANY, "", wxPoint(215, 458));
	questioncount_text->SetFont(font1);
	questioncount_text->SetForegroundColour(wxColour(255, 255, 255));

	

	reponse1_btn = new wxRadioButton(this, wxID_ANY, "a", wxPoint(300, 625), wxSize(400, 45));
	reponse2_btn = new wxRadioButton(this, wxID_ANY, "b", wxPoint(900, 625), wxSize(400, 45));
	reponse3_btn = new wxRadioButton(this, wxID_ANY, "c", wxPoint(300, 725), wxSize(400, 45));
	reponse4_btn = new wxRadioButton(this, wxID_ANY, "d", wxPoint(900, 725), wxSize(400, 45));

	reponse1_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse1_btn->SetFont(font1);
	reponse2_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse2_btn->SetFont(font1);
	reponse3_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse3_btn->SetFont(font1);
	reponse4_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse4_btn->SetFont(font1);

	///boutons jockers
	switch_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("switch.bmp"), wxBITMAP_TYPE_BMP), wxPoint(100, 200));
	cinquante_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("5050.bmp"), wxBITMAP_TYPE_BMP), wxPoint(300, 200));
	appelami_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("appelami.bmp"), wxBITMAP_TYPE_BMP), wxPoint(1000, 200));
	avispublique_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("avispublique.bmp"), wxBITMAP_TYPE_BMP), wxPoint(1200, 200));

	//boutons next et verifier
	next = new wxButton(this, 1000, "Next", wxPoint(1200, 500));
	verify_btn = new wxButton(this,1001, "verify", wxPoint(727, 675));

	this->SetBackgroundColour(wxColor(0, 0, 0));
}

startgame::~startgame(){}

void startgame::onnext(wxCommandEvent& evt) {
		questioncount_text->SetLabel("Q.1");
		questiontitle->SetLabel(T[0][0]);
		reponse1_btn->SetLabel(T[0][1]);
		reponse2_btn->SetLabel(T[0][2]);
		reponse3_btn->SetLabel(T[0][3]);
		reponse4_btn->SetLabel(T[0][4]);
		next->Show(false);
	evt.Skip();
}
void startgame::onverify(wxCommandEvent& evt)
{ 	
	if (!(reponse1_btn->GetValue() || reponse2_btn->GetValue() || reponse3_btn->GetValue() || reponse4_btn->GetValue()))
	{
		wxMessageBox(wxT("choisissez une reponse"));
	}
	else {
		if ((T[i][5].rfind("a") == 0 && reponse1_btn->GetValue()) || (T[i][5].rfind("b") == 0 && reponse2_btn->GetValue())
			|| (T[i][5].rfind("c") == 0 && reponse3_btn->GetValue()) || (T[i][5].rfind("d") == 0 && reponse4_btn->GetValue()))
		{
			wxMessageBox(wxT("correct answer"));
			j1->setgain(level);
			
		}
		else
		{
			wxMessageBox(wxT("WRONG ANSWER !"));
		}
	};
	if ((i + 1) % 5 == 0)
	{
		level++;
	};
	i++;
	question_count++;
	if (i < 15)
	{
		wxString s1;
		s1 << level;
		wxMessageBox(s1);
		wxString s;
		s << question_count;
		questioncount_text->SetLabel("Q." + s);
		questiontitle->SetLabel(T[i][0]);
		reponse1_btn->SetLabel(T[i][1]);
		reponse2_btn->SetLabel(T[i][2]);
		reponse3_btn->SetLabel(T[i][3]);
		reponse4_btn->SetLabel(T[i][4]);
		reponse1_btn->SetValue(false);
		reponse2_btn->SetValue(false);
		reponse3_btn->SetValue(false);
		reponse4_btn->SetValue(false);
	}
	else {
		int score = j1->getscore();
		string nom = j1->getnom();
		int id = j1->getid();

		ofstream sortie("joueur.txt", ios::app);
		sortie << "nom:  " << nom << "   id:  " << id << "   score:  " << score << endl;
		sortie.close();
		
		}
	evt.Skip();
}

void startgame::onclose(wxCloseEvent& event)
{
	//Rewrite these lines whenever this window is about to close. "Exit button ..."
	Destroy();
	this->PopEventHandler(true);
}

