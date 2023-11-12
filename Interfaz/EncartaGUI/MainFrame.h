#pragma once
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& tittle);
private:
	// Un event Handler es un metodo que se llama en respuesta a un evento
	void OnOpenNewFrame1(wxCommandEvent& event);
	void OnOpenNewFrame2(wxCommandEvent& event);
	void OnOpenNewFrame3(wxCommandEvent& event);
	void OnExitButtonClick(wxCommandEvent& event);
};

