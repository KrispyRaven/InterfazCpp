#pragma once
#include <wx/wx.h>




class CFrame : public wxFrame
{
public:
	CFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
	void CloseClicked(wxCommandEvent& evt);
	void Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY);
	void UpdateText(const wxString& newText);
	void OnButtonClick(wxCommandEvent& event);
	void SpecialClick(wxCommandEvent& event);

public:
	wxStaticText* m_textCtrl;
	wxStaticBitmap* image;
	wxButton* button1;
	wxButton* button2;
	wxButton* button3;
	wxButton* button4;
	wxButton* button5; 
	wxButton* button6;
};

// Declaración de la variable global 
extern int i;
