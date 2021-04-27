#include "stats.h"
wxBEGIN_EVENT_TABLE(stats, wxFrame)
EVT_CLOSE(stats::onclose)
END_EVENT_TABLE()

stats::stats() :wxFrame(nullptr, wxID_ANY, "", wxPoint(600,170), wxSize(363, 277)) {
	wxInitAllImageHandlers();
	wxBitmap TempBitmap;
	TempBitmap.LoadFile(wxT("avicpublique.png"), wxBITMAP_TYPE_PNG);
	background* bg = new background(TempBitmap);
	this->PushEventHandler(bg);
}
void stats::onclose(wxCloseEvent& event)
{
	Destroy();
	this->PopEventHandler(true);
}