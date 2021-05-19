#ifndef __WX_BACKGROUND_BITMAP_H__
#define __WX_BACKGROUND_BITMAP_H__

#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/wxprec.h"
#include <wx/frame.h>
#include <wx/bitmap.h>
#include <wx/event.h>
#endif

class background : public wxEvtHandler
{
	typedef wxEvtHandler Inherited;
public:
	background(const wxBitmap& B) : Bitmap(B), wxEvtHandler() { }
	virtual bool ProcessEvent(wxEvent& Event);
protected:
	wxBitmap Bitmap;
};
#endif