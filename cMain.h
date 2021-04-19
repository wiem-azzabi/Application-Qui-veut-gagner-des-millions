#pragma once
#include "wx/wx.h"
#include "startgame.h"
#include "FenetreJoueur.h"
#include "FenetreInstructions.h"

class cMain : public wxFrame
{
private:
	FenetreJoueur* FenetreJoueur_frame = nullptr;
	startgame* startgame_frame = nullptr;
	FenetreInstructions* Instructions_frame = nullptr;

	wxStaticText* title = nullptr;

	wxButton* bouton_liste_joueurs = nullptr;
	wxButton* btn_startgame = nullptr;
	wxButton* bouton_instructions = nullptr;
	wxButton* exit = nullptr;
	
public:
	cMain();
	~cMain();

	void onexit(wxCommandEvent& evt);
	void onstartgame(wxCommandEvent& evt);
	void onclick_liste_joueurs(wxCommandEvent& evt);
	void onclick_instructions(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};