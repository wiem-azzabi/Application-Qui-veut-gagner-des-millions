#include "startgame.h"
#include "background.h"
#include <wx/wx.h>
wxBEGIN_EVENT_TABLE(startgame, wxFrame)
EVT_BUTTON(1000, onnext)
EVT_CLOSE(startgame::OnClose)
END_EVENT_TABLE()
startgame::startgame() : wxFrame(nullptr, wxID_ANY, "Questions", wxPoint(0,0), wxSize(2000, 900)) {
	wxFont font1 = wxFont(21, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("pattern.bmp"), wxBITMAP_TYPE_BMP);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);

	questiontitle = new wxStaticText(this, wxID_ANY, "What's the best song of the world?", wxPoint(300, 458));
	questiontitle->SetFont(font1);

	questiocount_text = new wxStaticText(this, wxID_ANY, "Q.1", wxPoint(215, 458));
	questiocount_text->SetFont(font1);

	reponse1_btn = new wxButton(this, wxID_ANY, "Reponse 1", wxPoint(300, 625));
	reponse2_btn = new wxButton(this, wxID_ANY, "Reponse 2", wxPoint(300, 725));
	reponse3_btn = new wxButton(this, wxID_ANY, "Reponse 3", wxPoint(1000, 625));
	reponse4_btn = new wxButton(this, wxID_ANY, "Reponse 4", wxPoint(1000, 725));

	

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

void startgame::OnClose(wxCloseEvent& event)
{
	//Rewrite these lines whenever this window is about to close. "Exit button ..."
	Destroy();
	this->PopEventHandler(true);
}

