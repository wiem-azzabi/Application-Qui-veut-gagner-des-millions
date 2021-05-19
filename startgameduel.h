#pragma once
#include <wx/wx.h>
#include <fstream>
#include "joueur.h"
#include "background.h"
#include "stats.h"
#include "Fenetre_resultat.h"
#include "wx/mediactrl.h"
#include "string.h"

using namespace std;

class startgameduel : public wxFrame
{
private:

	wxStaticText* questiontitle = nullptr;
	wxStaticText* questioncount_text = nullptr;

	wxRadioButton* reponse1_btn = nullptr;
	wxRadioButton* reponse2_btn = nullptr;
	wxRadioButton* reponse3_btn = nullptr;
	wxRadioButton* reponse4_btn = nullptr;

	wxBitmapButton* switch_btn = nullptr;
	wxBitmapButton* cinquante_btn = nullptr;
	wxBitmapButton* appelami_btn = nullptr;
	wxBitmapButton* avispublique_btn = nullptr;


	wxButton* next = nullptr;
	wxButton* verify_btn = nullptr;
	wxStaticText* scoretxt = nullptr;


	wxString T[17][6];
	int question_count = 1;
	size_t i = 0;
	int imax = 15;
	int x1 = 0, x2 = 0;

	joueur* j1;
	joueur* j2;
	int level[2] = { 1,1 };

	wxStaticText* timetext = nullptr;
	int time1111 = 300;
	wxTimer* datetime;
	wxMediaCtrl* Sound = nullptr;
	wxMediaCtrl* clap = nullptr;
	wxMediaCtrl* son_echec = nullptr;



	int player = 2;
	bool selectplayer = 0;
	wxStaticBitmap* m_bitmap_j1, * m_bitmap_j2;
	bool theend = false;
public:
	startgameduel(wxString, wxString);
	~startgameduel();
	void onverify(wxCommandEvent& evt);
	void onnext(wxCommandEvent& evt);
	void temps(wxCommandEvent& evt);
	void onclose(wxCloseEvent&);
	void chrono(wxTimerEvent& evt);
	wxString inttotime(int);
	void oncinquante(wxCommandEvent& evt);
	void onswitch(wxCommandEvent& evt);
	void onappelami(wxCommandEvent& evt);
	void onavispublique(wxCommandEvent& evt);
	void onkeyboard(wxKeyEvent& event);



	wxDECLARE_EVENT_TABLE();
};


