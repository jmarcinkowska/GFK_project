///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////


class MyFrame : public wxFrame
{
private:

protected:
	wxPanel* m_panel;
	wxButton* m_buttonSave;
	wxStaticText* m_staticText;
	wxChoice* m_choiceAnimation;
	wxCheckBox* m_checkBoxMusic;
	wxCheckBox* m_checkBoxStopAnimation;
	wxTimer m_timer;

	// Virtual event handlers, overide them in your derived class
	virtual void FormUpdate(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void OnButtonClickSave(wxCommandEvent& event) { event.Skip(); }
	virtual void OnChoiceAnimation(wxCommandEvent& event) { event.Skip(); }
	virtual void OnCheckBoxMusic(wxCommandEvent& event) { event.Skip(); }
	virtual void OnCheckBoxStopAnimation(wxCommandEvent& event) { event.Skip(); }
	virtual void OnTimer(wxTimerEvent& event) { event.Skip(); }


public:

	MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Animacje"), const wxPoint& pos = wxPoint(-1, -1), const wxSize& size = wxSize(800, 550), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame();

};

#endif //__NONAME_H__
