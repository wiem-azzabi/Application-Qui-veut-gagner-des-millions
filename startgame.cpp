#include "startgame.h"
#include "background.h"
#include <wx/wx.h>
wxBEGIN_EVENT_TABLE(startgame, wxFrame)
EVT_BUTTON(1000, onnext)
EVT_CLOSE(startgame::onclose)
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
	questiontitle->SetForegroundColour(wxColour(255, 255, 255));

	questioncount_text = new wxStaticText(this, wxID_ANY, "Q.1", wxPoint(215, 458));
	questioncount_text->SetFont(font1);
	questioncount_text->SetForegroundColour(wxColour(255, 255, 255));

	reponse1_btn = new wxRadioButton(this, wxID_ANY, "Reponse 1", wxPoint(300, 625),wxSize(400,45));
	reponse2_btn = new wxRadioButton(this, wxID_ANY, "Reponse 2", wxPoint(300, 725), wxSize(400, 45));
	reponse3_btn = new wxRadioButton(this, wxID_ANY, "Reponse 3", wxPoint(900, 625), wxSize(400, 45));
	reponse4_btn = new wxRadioButton(this, wxID_ANY, "Reponse 4", wxPoint(900, 725), wxSize(400, 45));

	reponse1_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse1_btn->SetFont(font1);
	reponse2_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse2_btn->SetFont(font1);
	reponse3_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse3_btn->SetFont(font1);
	reponse4_btn->SetForegroundColour(wxColour(255, 255, 255));
	reponse4_btn->SetFont(font1);

	switch_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("switch.bmp"),wxBITMAP_TYPE_BMP), wxPoint(100, 200));
	cinquante_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("5050.bmp"), wxBITMAP_TYPE_BMP), wxPoint(300, 200));
	appelami_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("appelami.bmp"), wxBITMAP_TYPE_BMP), wxPoint(1000, 200));
	avispublique_btn = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("avispublique.bmp"), wxBITMAP_TYPE_BMP), wxPoint(1200, 200));

	next = new wxButton(this, 1000, "Next", wxPoint(1200, 500));
	verify_btn = new wxButton(this, wxID_ANY, "verify", wxPoint(727, 675));

	this->SetBackgroundColour(wxColor(0,0,0));
}

startgame::~startgame(){}

void startgame::onnext(wxCommandEvent& evt) {
	question_count++;
	wxString s;
	s << question_count;
	questioncount_text->SetLabel("Q." + s);
	reponse1_btn->SetLabel("reponse 1"+s);
	evt.Skip();
}

void startgame::onclose(wxCloseEvent& event)
{
	//Rewrite these lines whenever this window is about to close. "Exit button ..."
	Destroy();
	this->PopEventHandler(true);
}

