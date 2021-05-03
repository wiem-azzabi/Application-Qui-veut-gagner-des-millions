#pragma once
#include "wx/wx.h"
class FenetreInstructions:public wxFrame
{
	

	wxButton* bouton_exit = nullptr;
public:
	FenetreInstructions();
	~FenetreInstructions();
	void onClick(wxCommandEvent&);
	void onclose(wxCloseEvent&);

	wxDECLARE_EVENT_TABLE();
};

