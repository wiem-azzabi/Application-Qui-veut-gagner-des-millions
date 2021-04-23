#pragma once
#include "wx/wx.h"
#include "startgame.h"
#include "background.h"

class Login : public wxFrame
{
	wxTextCtrl* champs_nom = nullptr;
	wxButton* bouton_retour = nullptr;
	wxButton* bouton_startgame = nullptr;

	startgame* startgame_frame = nullptr;

public:
	Login();
	~Login();
	void onretour(wxCommandEvent&);
	void onstartgame(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};

