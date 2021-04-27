#pragma once
#include "background.h"
#include <wx/wx.h>
using namespace std;
class Fenetre_resultat:public wxFrame
{
	wxStaticText* text = nullptr;
	public:
	Fenetre_resultat(string,double);
	~Fenetre_resultat();


};

