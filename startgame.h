#pragma once
#include "wx/wx.h"

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
	int question_count = 1;

public:
	startgame();
	~startgame();
	void onverify(wxCommandEvent& evt);
	void onnext(wxCommandEvent& evt);

	void onclose(wxCloseEvent&);

	wxDECLARE_EVENT_TABLE();
};


