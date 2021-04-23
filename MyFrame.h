#pragma once
#include "wx/wx.h"

class MyFrame:public wxFrame
{public:
	MyFrame();
private:
	static const int timerInterval = 1000; // 1000 ms
	wxTimer   m_timer;
	wxButton* m_startStopTimerBtn;
	void OnTimer(wxTimerEvent&);
	void OnStartStopTimer(wxCommandEvent&);
};

