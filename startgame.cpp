#include "startgame.h"
wxBEGIN_EVENT_TABLE(startgame, wxFrame)
   EVT_BUTTON(1000, onnext)
END_EVENT_TABLE()
startgame::startgame() : wxFrame(nullptr, wxID_ANY, "Questions", wxPoint(300, 100), wxSize(1000, 700)) {
	wxFont font1 = wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	questiontitle = new wxStaticText(this, wxID_ANY, "What's the best song of the world?", wxPoint(200, 300));
	questiontitle->SetFont(font1);

	questiocount_text = new wxStaticText(this, wxID_ANY, "Q.1", wxPoint(130, 300));
	questiocount_text->SetFont(font1);

	reponse1_btn = new wxButton(this, wxID_ANY, "Reponse 1", wxPoint(200, 450));
	reponse2_btn = new wxButton(this, wxID_ANY, "Reponse 2", wxPoint(300, 450));
	reponse3_btn = new wxButton(this, wxID_ANY, "Reponse 3", wxPoint(400, 450));
	reponse4_btn = new wxButton(this, wxID_ANY, "Reponse 4", wxPoint(500, 450));

	reponse1_check = new wxCheckBox(this, wxID_ANY, "Reponse 1", wxPoint(200, 550)); 
	reponse2_check = new wxCheckBox(this, wxID_ANY, "Reponse 1", wxPoint(300, 550));
	reponse3_check = new wxCheckBox(this, wxID_ANY, "Reponse 1", wxPoint(400, 550));
	reponse4_check = new wxCheckBox(this, wxID_ANY, "Reponse 1", wxPoint(500, 550));

	next = new wxButton(this, 1000, "Next", wxPoint(800, 500));

	verify_btn = new wxButton(this, wxID_ANY, "verify", wxPoint(800, 550));
}

startgame::~startgame(){}

void startgame::onnext(wxCommandEvent& evt) {
	question_count++;
	wxString s;
	s << question_count;
	questiocount_text->SetLabel("Q." + s);
	evt.Skip();
}

