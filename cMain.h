#pragma once
#include "wx/wx.h"
#include "Login.h"
#include "FenetreJoueur.h"
#include "FenetreInstructions.h"
#include "background.h"


class cMain : public wxFrame
{
private:
	FenetreJoueur* FenetreJoueur_frame = nullptr;
	Login* loginframe = nullptr;
	FenetreInstructions* Instructions_frame = nullptr;

	// Controls
	wxButton* bouton_liste_joueurs = nullptr;
	wxButton* btn_login = nullptr;
	wxButton* bouton_instructions = nullptr;
	wxButton* exit = nullptr;
	wxButton* btn_login2 = nullptr;


	
public:
	cMain();
	~cMain();

	void onexit(wxCommandEvent& evt);
	void onclick_liste_joueurs(wxCommandEvent& evt);
	void onclick_instructions(wxCommandEvent& evt);

	void onlogin(wxCommandEvent& evt);
	void onclose(wxCloseEvent& event);

	wxDECLARE_EVENT_TABLE();
};