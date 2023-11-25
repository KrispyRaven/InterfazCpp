#pragma once
#include <wx/wx.h>
#include "MainFrame.h"
#include <iostream>
#include <string>

using namespace std;

wxDECLARE_EVENT(wxEVT_QFRAME_CLOSED, wxCommandEvent);

class QFrame : public wxFrame
{
public:
	QFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
	void CloseClicked(wxCommandEvent& evt);
	void Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY);
	void UpdateQuestion(const wxString& Question, const wxString& OpcionA, const wxString& OpcionB, const wxString& OpcionC, const wxString& OpcionD, int posX, int posY);
	void UpdateExtraText(const wxString& text, int posX, int posY);
	void OnButtonClick(wxCommandEvent& event);
	void ABCDClick(wxCommandEvent& event);
	

public:
	wxStaticText* m_textCtrl;
	wxStaticText* extra_text;
	wxStaticBitmap* image; 
	wxButton* button1;
	wxButton* button2;
	wxButton* button3;
	wxButton* button5;
	wxButton* button6;

	wxCheckBox* buttonA;
	wxCheckBox* buttonB;
	wxCheckBox* buttonC;
	wxCheckBox* buttonD;

	wxCheckBox* pastButton;

};

// Declaración de la variable global para iterar 
extern int e;

extern string temita;

