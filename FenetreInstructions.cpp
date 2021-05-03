#include "FenetreInstructions.h"
#include <iostream>
#include <Windows.h>
#include <string.h>
#include"cMain.h"

using namespace std;
wxBEGIN_EVENT_TABLE(FenetreInstructions, wxFrame)
EVT_BUTTON(2000, onClick)
EVT_CLOSE(FenetreInstructions::onclose)
wxEND_EVENT_TABLE()

FenetreInstructions::FenetreInstructions():wxFrame(nullptr, wxID_ANY, "Instructions", wxPoint(300, 100), wxSize(1000, 700))
{
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("insctructionf.jpg"), wxBITMAP_TYPE_JPEG);

	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
	bouton_exit = new wxButton(this, 2000, "Retour", wxPoint(445, 600), wxSize(100, 40), wxBORDER_NONE);
	bouton_exit->SetBackgroundColour(wxColor(0, 0, 0));
	bouton_exit->SetForegroundColour(wxColor(255, 255, 255));
	bouton_exit->SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	
}

FenetreInstructions::~FenetreInstructions()
{
	
	delete bouton_exit;
}
void FenetreInstructions::onClick(wxCommandEvent& evt)
{
	this->Close();
	cMain* retour_frame=new cMain();
	retour_frame->Show();
}

void FenetreInstructions::onclose(wxCloseEvent& event)
{
	Destroy();
	this->PopEventHandler(true);
}
