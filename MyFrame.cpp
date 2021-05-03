#include "MyFrame.h"
#include <wx/wx.h>
#include <wx/timer.h>


    MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "wxTimer example")
    {
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        m_startStopTimerBtn = new wxButton(this, wxID_ANY, "&Start timer");
        m_startStopTimerBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MyFrame::OnStartStopTimer, this);
        mainSizer->Add(m_startStopTimerBtn, 0, wxEXPAND | wxALL, 5);

        wxTextCtrl* logCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH2);
        mainSizer->Add(logCtrl, 1, wxEXPAND | wxALL, 5);
        wxLog::SetActiveTarget(new wxLogTextCtrl(logCtrl));

        SetSizer(mainSizer);

        m_timer.Bind(wxEVT_TIMER, &MyFrame::OnTimer, this);
    }


    void MyFrame::OnStartStopTimer(wxCommandEvent&)
    {
        if (m_timer.IsRunning())
        {
            m_timer.Stop();
            wxLogMessage("Timer stopped.");
            m_startStopTimerBtn->SetLabel("&Start timer");
        }
        else
        {
            m_timer.Start(timerInterval);
            wxLogMessage("Timer started.");
            m_startStopTimerBtn->SetLabel("&Stop timer");
        }
    }

    void MyFrame::OnTimer(wxTimerEvent&)
    {
        wxLogMessage("OnTimer called.");
    }

