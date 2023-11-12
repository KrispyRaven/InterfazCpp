#pragma once
#include <wx/wx.h>

class OOP : public wxFrame
{

public:
	OOP(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
	void CloseClicked(wxCommandEvent& evt);
	void UpdateText(const wxString& newText);
	void OnButtonClick(wxCommandEvent& event);

private:
	wxStaticText* m_textCtrl;
};

