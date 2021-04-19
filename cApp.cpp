#include "cApp.h"
wxIMPLEMENT_APP(cApp);  //sert à inclure tout le code nécessaire au démarrage de l'application.

cApp::cApp()
{
}
cApp::~cApp()
{
}
bool cApp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();
	return true;
}