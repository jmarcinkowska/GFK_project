#include "GUI.h"

#include <iostream>
#include <string>
#include <vector>
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
#include <wx/image.h>
#include <wx/sound.h>



class GUIMyFrame : public MyFrame 
{
private:

	virtual void FormUpdate(wxUpdateUIEvent& event);
	virtual void OnButtonClickSave(wxCommandEvent& event);
	virtual void OnChoiceAnimation(wxCommandEvent& event);
	virtual void OnCheckBoxMusic(wxCommandEvent& event);
	virtual void OnCheckBoxStopAnimation(wxCommandEvent& event);
	virtual void OnTimer(wxTimerEvent& event);

	void Draw();
	void Repaint();

	enum m_animation
	{
		start = 0,
		gitarzysta = 1,
		perkusista = 2,
		trebacz = 3,
		tancerz = 4,
		krzysztof = 5,
		niebo = 6
	};										

	int m_chosenAnimation;									
	bool m_isNew;												
	wxString m_nameTextFile;																	

	bool m_isStopActived;										
	bool m_isMusicActived;										
	wxSound m_sound;											

	wxBrush m_brushColor;										
	int m_penSize;											
	wxPen m_pen;							
	wxString m_tekst;								
	wxFont m_fontTextOnAnimation;
	int m_panelX;
	int m_panelY;
	
	wxBitmap *m_image;										
	wxImageHandler * m_imageHandler;						
	bool m_isImage;												

	std::vector<wxBitmap> m_allAnimation;					
	std::vector<int> m_timeFrames;							
	int m_frame;								
	int m_numberOfFrames;

public:	

	GUIMyFrame(wxWindow* parent);
	virtual ~GUIMyFrame();

};