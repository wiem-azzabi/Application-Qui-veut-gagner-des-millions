#pragma once
#include "wx/wx.h"

class FenetreJoueur: public wxFrame
{
	wxListBox* listejoueur = nullptr;
	wxButton* bouton_exit = nullptr;
public:
	FenetreJoueur();
	~FenetreJoueur();
	void onClick(wxCommandEvent&);
	wxDECLARE_EVENT_TABLE();
};

