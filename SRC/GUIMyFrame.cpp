#include "GUIMyFrame.h"
#include <wx/textctrl.h>
#include <wx/textfile.h>
#include <string>

int increment;

GUIMyFrame::GUIMyFrame(wxWindow *parent)
	: MyFrame(parent, wxID_ANY, "Animacje"),
	  m_chosenAnimation{start},
	  m_isNew{true},
	  m_isStopActived{false},
	  m_isMusicActived{false},
	  m_brushColor{wxColor(255, 255, 255)},
	  m_penSize{1},
	  m_pen{wxPen(wxColor(0, 0, 0), m_penSize)},
	  m_fontTextOnAnimation{wxFont(10, 74, 90, 90)},
	  m_panelX{600},
	  m_panelY{500},
	  m_image{new wxBitmap(wxNullBitmap)},
	  m_imageHandler{new wxPNGHandler()},
	  m_isImage{false},
	  m_allAnimation{wxNullBitmap},
	  m_timeFrames{0},
	  m_frame{0},
	  m_numberOfFrames{0}
{
	increment = 1;
	wxImage::AddHandler(m_imageHandler);
}

GUIMyFrame::~GUIMyFrame() {}

void GUIMyFrame::FormUpdate(wxUpdateUIEvent &event)
{
	Repaint();
}

void GUIMyFrame::OnButtonClickSave(wxCommandEvent &event)
{
	wxFileDialog saveFile(this, "Choose a file", "", "", "BMP files (*.bmp)|*.bmp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	saveFile.ShowModal();

	for (int i = 0; i < m_allAnimation.size(); i++)
	{
		wxImage image = m_allAnimation[i].ConvertToImage();
		wxString number = wxString::Format(wxT("%i"), i + 1);
		wxString prefix;
		if (i < 9)
			prefix = "000";
		else if (i < 99)
			prefix = "00";
		else if (i < 999)
			prefix = "0";
		wxString name = prefix + number + ".bmp";
		saveFile.SetFilename(name);
		wxString pathh = saveFile.GetPath();
		image.SaveFile(pathh, wxBITMAP_TYPE_BMP);
	}
}

void GUIMyFrame::OnChoiceAnimation(wxCommandEvent &event)
{
	m_chosenAnimation = event.GetSelection();
	m_numberOfFrames = 0;
	m_isNew = true;

	if (m_isNew)
	{
		m_checkBoxMusic->SetValue(false);
		if (m_sound.Play())
			m_sound.Stop();
	}

	switch (m_chosenAnimation)
	{

	case start:
	{
		m_nameTextFile = wxT("animationscode/start.txt");
		m_tekst = wxT("Wybierz Animacje");
		m_fontTextOnAnimation = wxFont(25, 74, 90, 90, false, wxT("Arial Black"));
		m_isImage = false;
		break;
	}

	case gitarzysta:
	{
		m_nameTextFile = wxT("animationscode/gitarzysta.txt");
		m_isImage = true;
		wxImage imageTemp = wxImage(wxSize(10, 80));
		imageTemp.LoadFile("images/guitar.png", wxBITMAP_TYPE_PNG);
		m_image = new wxBitmap(imageTemp);
		break;
	}

	case perkusista:
	{
		m_nameTextFile = wxT("animationscode/perkusista.txt");
		m_isImage = true;
		wxImage imageTemp = wxImage(wxSize(10, 80));
		imageTemp.LoadFile("images/drums.png", wxBITMAP_TYPE_PNG);
		m_image = new wxBitmap(imageTemp);
		break;
	}

	case trebacz:
	{
		m_nameTextFile = wxT("animationscode/trebacz.txt");
		m_isImage = true;
		wxImage imageTemp = wxImage(wxSize(200, 80));
		imageTemp.LoadFile("images/trumpet.png", wxBITMAP_TYPE_PNG);
		m_image = new wxBitmap(imageTemp);
		break;
	}

	case tancerz:
	{
		m_nameTextFile = wxT("animationscode/dancer.txt");
		m_isImage = false;
		break;
	}

	case krzysztof:
	{
		m_nameTextFile = wxT("animationscode/krzysztof.txt");
		m_isImage = true;
		wxImage imageTemp = wxImage(wxSize(60, 30));
		imageTemp.LoadFile("images/krzysztof.png", wxBITMAP_TYPE_PNG);
		m_image = new wxBitmap(imageTemp);
		break;
	}

	case niebo:
	{
		m_nameTextFile = wxT("animationscode/niebo.txt");
		m_isImage = true;
		wxImage imageTemp = wxImage(wxSize(60, 30));
		imageTemp.LoadFile("images/niebo.png", wxBITMAP_TYPE_PNG);
		m_image = new wxBitmap(imageTemp);
		break;
	}

	default:
		break;
	}

	Draw();

	if (!m_isStopActived)
		m_timer.Start(m_timeFrames[m_frame]);
	else
		m_timer.Stop();
}

void GUIMyFrame::OnCheckBoxMusic(wxCommandEvent &event)
{
	m_isMusicActived = event.IsChecked();

	if (m_isMusicActived == true && !m_checkBoxStopAnimation->GetValue())
	{

		switch (m_chosenAnimation)
		{
		case start:
		{
			m_sound.Create("music/swtheme.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case gitarzysta:
		{
			m_sound.Create("music/guitar.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case perkusista:
		{
			m_sound.Create("music/drums.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case trebacz:
		{
			m_sound.Create("music/trumpet.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case tancerz:
		{
			m_sound.Create("music/disco.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case krzysztof:
		{
			m_sound.Create("music/krzysztof.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		case niebo:
		{
			m_sound.Create("music/niebo.wav");
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
			break;
		}

		default:
			break;
		}
	}

	else
		m_sound.Stop();

	Refresh();
}

void GUIMyFrame::OnCheckBoxStopAnimation(wxCommandEvent &event)
{
	m_isStopActived = event.IsChecked();

	if (m_isStopActived)
	{
		m_checkBoxMusic->Enable(false);
		m_isMusicActived = false;
		m_sound.Stop();
	}
	else
	{
		m_checkBoxMusic->Enable(true);
		m_isMusicActived = true;

		if (m_checkBoxMusic->IsChecked())
			m_sound.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
	}

	if (!m_isStopActived)
		m_timer.Start(m_timeFrames[m_frame]);
	else
		m_timer.Stop();
}

void GUIMyFrame::OnTimer(wxTimerEvent &event)
{
	m_frame = m_frame + increment;
	if (m_frame < 0)
		m_frame = 0;
	if (m_frame == 0)
		increment = 1;
	if (m_frame == (m_allAnimation.size() - 1))
		increment = -1;
	Repaint();
}

void GUIMyFrame::Repaint()
{
	if (m_timer.IsRunning())
	{
		wxClientDC dc(m_panel);
		wxBufferedDC dcBuffered(&dc);
		m_panel->SetSize(m_panelX, m_panelY);
		this->SetSize(m_panelX + 250, m_panelY + 30);
		dcBuffered.DrawBitmap(m_allAnimation[m_frame], wxPoint(0, 0), true);
	}
}

std::string returnWord(int index, std::string str)
{
	std::string word;
	int count = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			if (str[i + 1] != ' ')
			{
				count++;
				if (count == index)
					return word;
				word = "";
			}
		}
		else
			word += str[i];
	}
	return word;
}

void GUIMyFrame::Draw()
{
	wxTextFile tfile;
	tfile.Open(m_nameTextFile);

	wxString sizePanel;

	if (tfile.IsOpened())
		sizePanel = tfile.GetFirstLine();

	m_panelX = std::atoi(returnWord(1, sizePanel.ToStdString()).c_str());
	m_panelY = std::atoi(returnWord(2, sizePanel.ToStdString()).c_str());

	m_allAnimation.reserve(200);
	m_timeFrames.reserve(200);

	wxMemoryDC dcTemp;
	wxBitmap bitmapTemp(m_panelX, m_panelY);

	wxString strLine;
	wxString word;

	int i_while = -1;
	while (i_while < 0)
	{
		strLine = tfile.GetNextLine();
		word = returnWord(1, strLine.ToStdString());

		if (isdigit(word[0]))
		{
			if (m_isNew)
			{
				m_timeFrames.clear();
				m_frame = 0;
			}

			dcTemp.SelectObject(bitmapTemp);
			dcTemp.Clear();
			m_timeFrames.push_back(std::stoi(returnWord(2, strLine.ToStdString()).c_str()));
		}

		//INSTRUKCJE RYSUJACE

		//ROZMIAN PIORA
		if ((word == "RP") || (word == "rozmiar_piora"))
		{
			m_penSize = std::stoi(returnWord(2, strLine.ToStdString()));
			dcTemp.SetPen(wxPen(wxColor(0, 0, 0), m_penSize));
		}

		//KOLOR PIORA
		if ((word == "KP") || (word == "kolor_piora"))
		{
			int r, g, b;
			r = std::stoi(returnWord(2, strLine.ToStdString()));
			g = std::stoi(returnWord(3, strLine.ToStdString()));
			b = std::stoi(returnWord(4, strLine.ToStdString()));

			dcTemp.SetPen(wxPen(wxColor(r, g, b), m_penSize));
			m_pen = wxPen(wxColor(r, g, b), m_penSize);
		}

		//KOLOR WYPELNIENIA
		if ((word == "KW") || (word == "kolor_wypelnienia"))
		{
			int r, g, b;
			r = std::stoi(returnWord(2, strLine.ToStdString()));
			g = std::stoi(returnWord(3, strLine.ToStdString()));
			b = std::stoi(returnWord(4, strLine.ToStdString()));

			dcTemp.SetBrush(wxBrush(wxColor(r, g, b)));
			m_brushColor = wxBrush(wxColor(r, g, b));
		}

		//LINIA
		if ((word == "LN") || (word == "linia"))
		{
			int x1, y1, x2, y2;
			x1 = std::stoi(returnWord(2, strLine.ToStdString()));
			y1 = std::stoi(returnWord(3, strLine.ToStdString()));
			x2 = std::stoi(returnWord(4, strLine.ToStdString()));
			y2 = std::stoi(returnWord(5, strLine.ToStdString()));

			dcTemp.DrawLine(x1, y1, x2, y2);
		}

		//PUNKT
		if ((word == "PT") || (word == "punkt"))
		{
			int x, y;
			x = std::stoi(returnWord(2, strLine.ToStdString()));
			y = std::stoi(returnWord(3, strLine.ToStdString()));

			dcTemp.DrawPoint(x, y);
		}

		//ELIPSA
		if ((word == "EL") || (word == "elipsa"))
		{
			int x1, y1, x2, y2, flag;
			x1 = std::stoi(returnWord(2, strLine.ToStdString()));
			y1 = std::stoi(returnWord(3, strLine.ToStdString()));
			x2 = std::stoi(returnWord(4, strLine.ToStdString()));
			y2 = std::stoi(returnWord(5, strLine.ToStdString()));
			flag = std::stoi(returnWord(6, strLine.ToStdString()));

			if (flag)
			{
				dcTemp.SetBrush(m_brushColor);
				dcTemp.DrawEllipse(x1, y1, x2, y2);
			}
			else
			{
				dcTemp.SetBrush(wxBrush(wxColor(255, 255, 255)));
				dcTemp.DrawEllipse(x1, y1, x2, y2);
				dcTemp.SetBrush(m_brushColor);
			}
		}

		//PROSTOKAT
		if ((word == "PR") || (word == "prostokat"))
		{
			int x1, y1, x2, y2, flag;
			x1 = std::stoi(returnWord(2, strLine.ToStdString()));
			y1 = std::stoi(returnWord(3, strLine.ToStdString()));
			x2 = std::stoi(returnWord(4, strLine.ToStdString()));
			y2 = std::stoi(returnWord(5, strLine.ToStdString()));
			flag = std::stoi(returnWord(6, strLine.ToStdString()));

			if (flag)
			{
				dcTemp.SetBrush(m_brushColor);
				dcTemp.DrawRectangle(x1, y1, x2, y2);
			}
			else
			{
				dcTemp.SetBrush(wxBrush(wxColor(255, 255, 255)));
				dcTemp.DrawRectangle(x1, y1, x2, y2);
				dcTemp.SetBrush(m_brushColor);
			}
		}

		//TROJKAT
		if ((word == "TR") || (word == "trojkat"))
		{
			int x1, y1, x2, y2, x3, y3;
			x1 = std::stoi(returnWord(2, strLine.ToStdString()));
			y1 = std::stoi(returnWord(3, strLine.ToStdString()));
			x2 = std::stoi(returnWord(4, strLine.ToStdString()));
			y2 = std::stoi(returnWord(5, strLine.ToStdString()));
			x3 = std::stoi(returnWord(6, strLine.ToStdString()));
			y3 = std::stoi(returnWord(7, strLine.ToStdString()));

			wxPoint triangle[3]{
				wxPoint(x1, y1),
				wxPoint(x2, y2),
				wxPoint(x3, y3)};

			dcTemp.DrawPolygon(3, triangle);
		}

		//DO PODTRZYMYWANIA TEKSTU
		if ((word == "TT") || (word == "trzymaj_tekst"))
		{
			int x, y;
			x = std::stoi(returnWord(2, strLine.ToStdString()));
			y = std::stoi(returnWord(3, strLine.ToStdString()));
			dcTemp.SetFont(m_fontTextOnAnimation);
			dcTemp.DrawText(m_tekst, x, y);
		}

		//DO PODTRZYMYWANIA GRAFIK
		if ((word == "TG") || (word == "trzymaj_grafike"))
		{
			int x, y;
			x = std::stoi(returnWord(2, strLine.ToStdString()));
			y = std::stoi(returnWord(3, strLine.ToStdString()));
			dcTemp.DrawBitmap(*m_image, x, y);
		}

		//KONIEC KLATKI, ZAPIS DO VECTORA BITMAP
		if ((word == "ST") || (word == "stop"))
		{
			if (m_isNew)
			{
				m_allAnimation.clear();
				m_isNew = false;
			}
			dcTemp.SelectObject(wxNullBitmap);
			m_allAnimation.push_back(bitmapTemp);
			m_numberOfFrames++;
			dcTemp.Clear();
		}

		if (word == wxT("KONIEC"))
		{
			i_while = 1;
			if (m_isImage)
			{
				delete m_image;
				m_isImage = false;
			}
		}
	}

	m_penSize = 1;
	m_brushColor = wxColor(255, 255, 255);
	m_pen = wxPen(wxColor(0, 0, 0), m_penSize);
}