#pragma once
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& tittle);
private:
	void OnOpenNewFrame(wxCommandEvent& event);
};

