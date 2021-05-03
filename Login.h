#pragma once
#include <wx/wx.h>
#include "startgame.h"
#include "startgameduel.h"
#include "background.h"

class Login : public wxFrame
{
	wxTextCtrl* champs_nom = nullptr;
	wxTextCtrl* champs_nom2 = nullptr;
	wxButton* bouton_retour = nullptr;
	wxButton* bouton_startgame = nullptr;
	startgame* startgame_frame = nullptr;
	int mode = 0;
public:
	Login(int);
	~Login();
	void onretour(wxCommandEvent&);
	void onstartgame(wxCommandEvent&);
	void onclose(wxCloseEvent&);
	wxDECLARE_EVENT_TABLE();
};

