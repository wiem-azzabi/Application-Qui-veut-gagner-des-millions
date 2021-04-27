#pragma once
#include "background.h"
#include <wx/wx.h>
class stats:public wxFrame
{
public:
	stats();
	void onclose(wxCloseEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

