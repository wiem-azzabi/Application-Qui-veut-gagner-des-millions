#pragma once
#include <wx/wx.h>
#include "joueur.h"
#include "startgame.h"
#include "background.h"
#include <wx/wx.h>
#include <string>
#include <fstream>
#include <wx/msgdlg.h>

class startgame : public wxFrame
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


	wxString T[15][6];
	int question_count =1;
	size_t i =0;
	
	int level = 1;
public:
	startgame();
	~startgame();
	void onverify(wxCommandEvent& evt);
	void onnext(wxCommandEvent& evt);
	void temps(wxCommandEvent& evt);
	void onclose(wxCloseEvent&);


	wxDECLARE_EVENT_TABLE();
};


