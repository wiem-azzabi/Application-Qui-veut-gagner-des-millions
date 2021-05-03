
#include "startgameduel.h"

using namespace std;

wxBEGIN_EVENT_TABLE(startgameduel, wxFrame)
EVT_BUTTON(1000, onnext)
EVT_BUTTON(1001, onverify)
EVT_BUTTON(100, onswitch)
EVT_BUTTON(200, oncinquante)
EVT_BUTTON(300, onappelami)
EVT_BUTTON(400, onavispublique)
EVT_CLOSE(startgameduel::onclose)
EVT_TIMER(1111, addsecond)
EVT_KEY_DOWN(onkeyboard)
END_EVENT_TABLE()

startgameduel::startgameduel(wxString nomjoueur, wxString nomjoueur2) : wxFrame(nullptr, wxID_ANY, "", wxPoint(0, 0), wxSize(2000, 900)) {
	wxFont font1 = wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	///background
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("jeubg.jpg"), wxBITMAP_TYPE_JPEG);
	m_bitmap_j1 = new wxStaticBitmap(this, 6020, wxBitmap(wxT("j1.png"), wxBITMAP_TYPE_PNG), wxPoint(1155, 405));
	m_bitmap_j2 = new wxStaticBitmap(this, 6020, wxBitmap(wxT("j2.png"), wxBITMAP_TYPE_PNG), wxPoint(1180, 405));

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);

	///tableau des questions
	ifstream entree("questions2.txt", ios::in);
	if (entree)
	{
		string ligne;
		for (int i = 0; i < 17; i++)		//i:numeroquestion 
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
	j1 = new joueur(nomjoueur.ToStdString());
	j1->setid();
	j2 = new joueur(nomjoueur2.ToStdString());
	j2->setid();

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

	timetext = new wxStaticText(this, 1111, inttotime(300), wxPoint(125, 65), wxSize(-1, -1));
	timetext->SetFont(font1);
	timetext->SetForegroundColour(wxColor(255, 255, 255));
	datetime = new wxTimer(this, 1111);

	///boutons jockers
	switch_btn = new wxBitmapButton(this, 100, wxBitmap(wxT("switchjp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(50, 350));
	cinquante_btn = new wxBitmapButton(this, 200, wxBitmap(wxT("5050jp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(150, 350));
	appelami_btn = new wxBitmapButton(this, 300, wxBitmap(wxT("appelamijp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(250, 350));
	avispublique_btn = new wxBitmapButton(this, 400, wxBitmap(wxT("avispubliquejp.jpg"), wxBITMAP_TYPE_JPEG), wxPoint(350, 350));

	//boutons next et verifier
	next = new wxButton(this, 1000, "Commencer", wxPoint(100, 180), wxSize(200, 20), wxBORDER_NONE);
	scoretxt = new wxStaticText(this, wxID_ANY, "", wxPoint(100, 180), wxSize(200, 20), wxBORDER_NONE);
	scoretxt->Show(false);
	scoretxt->SetForegroundColour(wxColor(255, 188, 15));
	scoretxt->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	verify_btn = new wxButton(this, 1001, "verifier", wxPoint(125, 290), wxSize(-1, -1), wxBORDER_NONE);
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

	wxString s1;
	s1 << j1->getscore();
	wxString s2;
	s2 << j2->getscore();
	scoretxt->SetLabel("j1: " + s1 + "  j2: " + s2);

}
startgameduel::~startgameduel() {
	int score = j1->getscore();
	int score2 = j2->getscore();
	string nom = j1->getnom();
	string nom2 = j2->getnom();
	int id = j1->getid();
	int id2 = j2->getid();

	ofstream sortie("joueur.txt", ios::app);
	sortie << "nom:  " << nom << "   id:  " << id << "   score:  " << score << endl;
	sortie << "nom:  " << nom2 << "   id:  " << id2 << "   score:  " << score2 << endl;
	sortie.close();
}

void startgameduel::onnext(wxCommandEvent& evt) {
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

void startgameduel::onverify(wxCommandEvent& evt)
{
	//Sound->Play();
	bool ans_select = true; //s'assurer qu'on selectionne un joueur avant de cliquer "verifier"

	if (player != 2) {
		if (!(reponse1_btn->GetValue() || reponse2_btn->GetValue() || reponse3_btn->GetValue() || reponse4_btn->GetValue()))
		{
			wxMessageBox(wxT("Choisissez une reponse"));
			ans_select = false;
		}
		else {
			if ((T[i][5].rfind("a") == 0 && reponse1_btn->GetValue()) || (T[i][5].rfind("b") == 0 && reponse2_btn->GetValue())
				|| (T[i][5].rfind("c") == 0 && reponse3_btn->GetValue()) || (T[i][5].rfind("d") == 0 && reponse4_btn->GetValue()))
			{
				wxMessageBox(wxT("correct answer"));
				if (player == 0)
				{
					x1++;
					j1->setgain(level[0]);
					level[0] = x1 / 5 + 1;
					int y = m_bitmap_j1->GetPosition().y - 25;
					delete m_bitmap_j1;
					m_bitmap_j1 = new wxStaticBitmap(this, 6020, wxBitmap(wxT("j1.png"), wxBITMAP_TYPE_PNG), wxPoint(1473, y));

				}
				else
				{
					x2++;
					j2->setgain(level[1]);
					level[1] = x2 / 5 + 1;
					int y = m_bitmap_j2->GetPosition().y - 25;
					delete m_bitmap_j2;
					m_bitmap_j2 = new wxStaticBitmap(this, 6020, wxBitmap(wxT("j2.png"), wxBITMAP_TYPE_PNG), wxPoint(1498, y));
				}
				wxString s1;
				s1 << j1->getscore();
				wxString s2;
				s2 << j2->getscore();
				scoretxt->SetLabel("j1: " + s1 + "  j2: " + s2);
				clap->Play();
				clap->SetVolume(0.5f);
			}
			else
			{
				wxMessageBox(wxT("WRONG ANSWER !"));
			}
		}
		/*
		if (x1 % 5 == 0)
		{
			x1 = 0;
			level[0]++;
		}

		if (x2 % 5 == 0)
		{
			x2 = 0;
			level[1]++;
		}
		*/

		if (ans_select) {
			i++;
			question_count++;
			if (i < 16)
			{
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
				if (j1->tabjocker[0] == 1 && j2->tabjocker[0]== 1) 
				{
					datetime->Stop();
					Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(), j1->getscore(), j2->getnom(), j2->getscore());
					result_frame->Show();
					this->Close();
				}
				else {
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
						
					if(i==17)
					{
						datetime->Stop();
						Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(), j1->getscore(), j2->getnom(), j2->getscore());
						result_frame->Show();
						this->Close();
					}
				}
			}
			selectplayer = !selectplayer;
		}
	}
	else {
		wxMessageBox("S'il vous plait désigner le tour à un jour tout d'abord !");
	}
	this->SetFocus();
	if (ans_select) player = 2; //needed to make sure to select a player before verifying an answer...

}

void startgameduel::onclose(wxCloseEvent& event)
{
	//Rewrite these lines whenever this window is about to close. "Exit button ..."
	Destroy();
	this->PopEventHandler(true);
}
void startgameduel::addsecond(wxTimerEvent& evt) {
	wxString s;
	s = inttotime(time1111);
	time1111--;
	if (time1111 <= 0)
	{
		datetime->Stop();
		wxMessageBox("Timeout");
		this->Close();
		Fenetre_resultat* result_frame = new Fenetre_resultat(j1->getnom(), j1->getscore());
		result_frame->Show();
	}
	timetext->SetLabel(s);
	evt.Skip();
}
wxString startgameduel::inttotime(int x) {
	wxString  m, s;
	int  mm, ss;
	ss = x % 60;
	x = x / 60;
	mm = x % 60;
	x = x / 60;
	m << mm;
	s << ss;
	wxString res;
	if (ss < 10 && mm < 10) res = "0" + m + ":0" + s;
	else if (ss < 10 && mm >= 10) res = "0" + m + ":0" + s;
	else if (ss >= 10 && mm < 10) res = "0" + m + ":" + s;
	else res = m + ":" + s;
	return res;
}

void startgameduel::oncinquante(wxCommandEvent& evt)
{
	switch (player)
	{
	case 0:
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
		};
		break;
	}
	case 1:
	{
		if (j2->tabjocker[1] == 1)
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
			j2->tabjocker[1] = 0;
		}
		else
		{
			wxMessageBox("Jocker utilisé!");
		};
		break;
	}
	}


	evt.Skip();
}
void startgameduel::onappelami(wxCommandEvent& evt)
{
	switch (player)
	{
	case 0:
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
		break;
	}
	case 1:
	{if (j2->tabjocker[2] == 1)
	{
		wxMessageBox("Votre ami pense que c'est: " + T[i][5]); //affiche caractere
		j2->tabjocker[2] = 0;
	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
	break;
	}
	}
}
void startgameduel::onswitch(wxCommandEvent& evt)
{
	switch (player)
	{
	case 0:
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
	break;
	}
	case 1:
	{if (j2->tabjocker[0] == 1)
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
		j2->tabjocker[0] = 0;


	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
	break;
	}
	}

}
void startgameduel::onavispublique(wxCommandEvent& evt) {
	switch (player)
	{
	case 0:
	{
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
		break; }
	case 1:
	{if (j2->tabjocker[3] == 1)
	{
		stats* stats_frame = new stats();
		stats_frame->Show();
		j2->tabjocker[3] = 0;

	}
	else
	{
		wxMessageBox("Jocker utilisé!");
	}
	break; }
	}
	evt.Skip();
}

void startgameduel::onkeyboard(wxKeyEvent& evt) {
	wxString key = evt.GetUnicodeKey();
	if (!selectplayer) {
		if (key == 'A') {
			player = 0;
			wxMessageBox("Joueur 1");
			selectplayer = !selectplayer;
		}
		else if (key == 'B') {
			player = 1;
			wxMessageBox("Joueur 2");
			selectplayer = !selectplayer;
		}
		else {
			wxMessageBox("Appuiez sur A pour le joueur 1 et B pour le joueur 2.");
		}
	}
	else
	{
		if (key == 'A')
			reponse1_btn->SetValue(true);
		if (key == 'B')
			reponse2_btn->SetValue(true);
		if (key == 'C')
			reponse3_btn->SetValue(true);
		if (key == 'D')
			reponse4_btn->SetValue(true);
	}
	this->SetFocus();
	evt.Skip();
}
