
#include "startgame.h"

using namespace std;

wxBEGIN_EVENT_TABLE(startgame, wxFrame)
EVT_BUTTON(1000, onnext)
EVT_BUTTON(1001, onverify)
EVT_BUTTON(100, onswitch)
EVT_BUTTON(200, oncinquante)
EVT_BUTTON(300, onappelami)
EVT_BUTTON(400, onavispublique)
EVT_CLOSE(startgame::onclose)
EVT_TIMER(1111, addsecond)
END_EVENT_TABLE()

startgame::startgame(wxString nomjoueur) : wxFrame(nullptr, wxID_ANY, "", wxPoint(0, 0), wxSize(2000, 900)) {
	wxFont font1 = wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	///background
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("jeubg.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	fleche_img = new wxStaticBitmap(this, 6020, wxBitmap(wxT("fleche.png"), wxBITMAP_TYPE_PNG), wxPoint(1180, 400));

	///tableau des questions
	ifstream entree("questions2.txt", ios::in);
	if (entree)
	{
		string ligne;
		for (int i = 0; i < 16; i++)		//i:numeroquestion 
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
	j1=new joueur(nomjoueur.ToStdString());
	j1->setid();
	
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

	timetext= new wxStaticText(this, 1111, inttotime(300), wxPoint(125,65),wxSize(-1,-1));
	timetext->SetFont(font1);
	timetext->SetForegroundColour(wxColor(255,255,255));
	datetime = new wxTimer(this, 1111);

	///boutons jockers
	switch_btn = new wxBitmapButton(this, 100, wxBitmap(wxT("switchjp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(50, 350));
	cinquante_btn = new wxBitmapButton(this, 200, wxBitmap(wxT("5050jp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(150, 350));
	appelami_btn = new wxBitmapButton(this, 300, wxBitmap(wxT("appelamijp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(250, 350));
	avispublique_btn = new wxBitmapButton(this, 400, wxBitmap(wxT("avispubliquejp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(350, 350));

	//boutons next et verifier
	next = new wxButton(this, 1000, "Commencer", wxPoint(100, 180), wxSize(200,20),wxBORDER_NONE);
	scoretxt = new wxStaticText(this, wxID_ANY, "", wxPoint(100, 180), wxSize(200, 20), wxBORDER_NONE);
	scoretxt->Show(false);
	scoretxt->SetForegroundColour(wxColor(255, 188, 15));
	scoretxt->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	verify_btn = new wxButton(this,1001, "verifier", wxPoint(125, 290), wxSize(-1, -1),wxBORDER_NONE);
	next->SetBackgroundColour(wxColor(0, 0, 0));
	next->SetForegroundColour(wxColor(255, 255, 255));
	next->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	verify_btn->SetBackgroundColour(wxColor(0, 0, 0));
	verify_btn->SetForegroundColour(wxColor(255, 255, 255));
	verify_btn->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	this->SetBackgroundColour(wxColor(0, 0, 0));

	Sound = new wxMediaCtrl();
	int ok = Sound->Create(this, wxID_ANY, "Sound.wav", wxDefaultPosition);
	if (!ok) wxMessageBox("Couldn't load file.");

	clap = new wxMediaCtrl();
	int ok2 = clap->Create(this, wxID_ANY, "clap.wav", wxDefaultPosition);
	if (!ok2) wxMessageBox("Couldn't load file.");
}
startgame::~startgame(){
	int score = j1->getscore();
	string nom = j1->getnom();
	int id = j1->getid();

	ofstream sortie("joueur.txt", ios::app);
	sortie << "nom:  " << nom << "   id:  " << id << "   score:  " << score << endl;
	sortie.close();
}

void startgame::onnext(wxCommandEvent& evt) {
		questioncount_text->SetLabel("Q.1");
		questiontitle->SetLabel(T[0][0]);
		reponse1_btn->SetLabel(T[0][1]);
		reponse2_btn->SetLabel(T[0][2]);
		reponse3_btn->SetLabel(T[0][3]);
		reponse4_btn->SetLabel(T[0][4]);
		next->Show(false);
		scoretxt->Show();
		datetime->Start(1000); //appel a la fct addsecond chaque 1000ms
		//Sound->Play();
		//Sound->GetVolume(0.5);
	evt.Skip();
}
void startgame::onverify(wxCommandEvent& evt)
{
	//Sound->Play();
	int ok = 0;
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

			int y = fleche_img->GetPosition().y - 25;
			delete fleche_img;
			fleche_img = new wxStaticBitmap(this, 6020, wxBitmap(wxT("fleche.png"), wxBITMAP_TYPE_PNG), wxPoint(1180, y));
			wxString s;
			s << j1->getscore();
			scoretxt->SetLabel(s);
			clap->Play();
			clap->SetVolume(0.5f);

		}
		else
		{
			ok = 1;
			wxMessageBox(wxT("WRONG ANSWER !"));
		}
	};
	if ((i + 1) % 5 == 0)
	{
		level++;
	};
	i++;
	question_count++;
	if (ok == 0)
	{
		if ((i < 15))
		{
			wxString s1;
			s1 << level;
			//wxMessageBox(s1);
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
			reponse1_btn->Show(true);
			reponse2_btn->Show(true);
			reponse3_btn->Show(true);
			reponse4_btn->Show(true);

		}
		else {
			if (j1->tabjocker[0] == 0)
			{
				wxString s1;
				s1 << level;
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
				reponse1_btn->Show(true);
				reponse2_btn->Show(true);
				reponse3_btn->Show(true);
				reponse4_btn->Show(true);
			}
			else
			{
				//this->Close();
				datetime->Stop();
				j1->setscore(level);
				Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(), j1->getscore());
				result_frame->Show();
				this->Close();
			}
		}
		if (ok == 1)
		{
			this->Close();
			datetime->Stop();
			j1->setscore(level);
			Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(), j1->getscore());
			result_frame->Show();
		};

	}
}

void startgame::onclose(wxCloseEvent& event)
{
	//Rewrite these lines whenever this window is about to close. "Exit button ..."
	Destroy();
	this->PopEventHandler(true);
}

void startgame::addsecond(wxTimerEvent& evt) {
	wxString s;
	s = inttotime(time1111);
	time1111--;
	if (time1111 <= 0)
	{
		datetime->Stop();
		wxMessageBox("Timeout");
		this->Close();
		Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(),j1->getscore());
		result_frame->Show();
	}
	timetext->SetLabel(s);
	evt.Skip();
}
wxString startgame::inttotime(int x) {
	wxString  m, s;
	int  mm, ss;
	ss = x % 60;
	x = x / 60;
	mm = x % 60;
	x = x / 60;
	m << mm;
	s << ss;
	wxString res;
	if (ss < 10 && mm < 10) res ="0" +m + ":0" + s;
	else if (ss < 10 && mm >= 10) res = "0"+ m + ":0" + s;
	else if (ss >= 10 && mm < 10) res = "0" + m + ":" + s;
	else res = m + ":" + s;
	return res;
}

void startgame::oncinquante(wxCommandEvent& evt)
{
	if (j1->tabjocker[1] == 1)
	{
		if (T[i][5].rfind("a") == 0)
		{
			reponse2_btn->Show(false);
			reponse4_btn->Show(false);
		};
		if (T[i][5].rfind("b") == 0)
		{
			reponse1_btn->Show(false);
			reponse3_btn->Show(false);
		};
		if (T[i][5].rfind("c") == 0)
		{
			reponse1_btn->Show(false);
			reponse4_btn->Show(false);
		};
		if (T[i][5].rfind("d") == 0)
		{
			reponse1_btn->Show(false);
			reponse3_btn->Show(false);
		};
		j1->tabjocker[1] = 0;
	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
	evt.Skip();
}
void startgame::onappelami(wxCommandEvent& evt)
{
	if (j1->tabjocker[2] == 1)
	{
		wxMessageBox("Votre ami pense que c'est: " + T[i][5]); //affiche caractere
		j1->tabjocker[2] = 0;
	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
}
void startgame::onswitch(wxCommandEvent& evt)
{
	if (j1->tabjocker[0] == 1)
	{
		/// ****
		i++;
		
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
		reponse1_btn->Show(true);
		reponse2_btn->Show(true);
		reponse3_btn->Show(true);
		reponse4_btn->Show(true);
		/// ***
		j1->tabjocker[0] = 0;

	
	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}

}
void startgame::onavispublique(wxCommandEvent& evt) {
	if (j1->tabjocker[3] == 1)
	{
		stats* stats_frame = new stats();
		stats_frame->Show();
		j1->tabjocker[3] = 0;

	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
	evt.Skip();
}
