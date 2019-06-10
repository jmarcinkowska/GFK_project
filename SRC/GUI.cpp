#include "GUI.h"

MyFrame::MyFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(800, 550), wxDefaultSize);

	wxBoxSizer *bSizer_all;
	bSizer_all = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer *bSizer_panel;
	bSizer_panel = new wxBoxSizer(wxVERTICAL);

	m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));
	m_panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));

	bSizer_panel->Add(m_panel, 1, wxALL | wxEXPAND, 5);

	bSizer_all->Add(bSizer_panel, 1, wxEXPAND | wxLEFT, 5);

	wxBoxSizer *bSizer_menu;
	bSizer_menu = new wxBoxSizer(wxVERTICAL);

	m_buttonSave = new wxButton(this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer_menu->Add(m_buttonSave, 0, wxALL | wxEXPAND, 20);

	m_staticText = new wxStaticText(this, wxID_ANY, wxT("Animacja:"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText->Wrap(-1);
	m_staticText->SetFont(wxFont(14, 74, 90, 90, false, wxT("Arial")));

	bSizer_menu->Add(m_staticText, 0, wxALL, 5);

	wxString m_choice_animacjaChoices[] = {wxT("*-*-*-*"), wxT("Gitarzysta"), wxT("Perkusista"), wxT("Tr�bacz"), wxT("Tancerz"), wxT("Krzysztof Krawczyk"), wxT("Niebo")};
	int m_choice_animacjaNChoices = sizeof(m_choice_animacjaChoices) / sizeof(wxString);
	m_choiceAnimation = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_animacjaNChoices, m_choice_animacjaChoices, 0);
	m_choiceAnimation->SetSelection(0);
	m_choiceAnimation->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	m_choiceAnimation->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT));

	bSizer_menu->Add(m_choiceAnimation, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxEXPAND, 10);

	m_checkBoxMusic = new wxCheckBox(this, wxID_ANY, wxT("Muzyka"), wxDefaultPosition, wxDefaultSize, 0);
	m_checkBoxMusic->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));

	bSizer_menu->Add(m_checkBoxMusic, 0, wxALL | wxEXPAND, 5);

	m_checkBoxStopAnimation = new wxCheckBox(this, wxID_ANY, wxT("Zatrzymanie animacji"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer_menu->Add(m_checkBoxStopAnimation, 0, wxALL | wxEXPAND, 5);

	bSizer_all->Add(bSizer_menu, 0, wxALL | wxTOP | wxEXPAND, 5);

	this->SetSizer(bSizer_all);
	this->Layout();
	m_timer.SetOwner(this, wxID_ANY);

	this->Centre(wxBOTH);

	// Connect Events
	m_panel->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::FormUpdate), NULL, this);
	m_buttonSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonClickSave), NULL, this);
	m_choiceAnimation->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::OnChoiceAnimation), NULL, this);
	m_checkBoxMusic->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnCheckBoxMusic), NULL, this);
	m_checkBoxStopAnimation->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnCheckBoxStopAnimation), NULL, this);
	this->Connect(wxID_ANY, wxEVT_TIMER, wxTimerEventHandler(MyFrame::OnTimer));
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_panel->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame::FormUpdate), NULL, this);
	m_buttonSave->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonClickSave), NULL, this);
	m_choiceAnimation->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::OnChoiceAnimation), NULL, this);
	m_checkBoxMusic->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnCheckBoxMusic), NULL, this);
	m_checkBoxStopAnimation->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnCheckBoxStopAnimation), NULL, this);
	this->Disconnect(wxID_ANY, wxEVT_TIMER, wxTimerEventHandler(MyFrame::OnTimer));
}
