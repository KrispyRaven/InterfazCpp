#pragma once
#include <wx/wx.h>
#include "CFrame.h"




class OOP : public CFrame
{

public:
	OOP(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
	
	void OnButtonClick1(wxCommandEvent& event);

};




