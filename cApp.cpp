#include "cApp.h"
wxIMPLEMENT_APP(cApp);  //sert � inclure tout le code n�cessaire au d�marrage de l'application.

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