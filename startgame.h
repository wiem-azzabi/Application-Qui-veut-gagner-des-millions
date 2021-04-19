#pragma once
#include "wx/wx.h"

class startgame : public wxFrame
{
private:

	wxStaticText* questiontitle = nullptr;
	wxStaticText* questiocount_text = nullptr;

	wxButton* reponse1_btn = nullptr;
	wxButton* reponse2_btn = nullptr;
	wxButton* reponse3_btn = nullptr;
	wxButton* reponse4_btn = nullptr;

	wxCheckBox* reponse1_check = nullptr;
	wxCheckBox* reponse2_check = nullptr;
	wxCheckBox* reponse3_check = nullptr;
	wxCheckBox* reponse4_check = nullptr;

	wxButton* next = nullptr;

	wxButton* verify_btn = nullptr;
	int question_count = 1;
public:
	startgame();
	~startgame();
	void onnext(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};


