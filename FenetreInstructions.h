#pragma once
#include "wx/wx.h"
class FenetreInstructions:public wxFrame
{
	wxStaticText* text = nullptr;

	wxButton* bouton_exit = nullptr;
public:
	FenetreInstructions();
	~FenetreInstructions();
	void onClick(wxCommandEvent&);

	wxDECLARE_EVENT_TABLE();
};

