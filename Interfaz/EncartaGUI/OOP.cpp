#include "OOP.h"
#include <wx/wx.h>

OOP::OOP(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, title, pos, size)
{

	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Clases", wxPoint(20, 50), wxSize(100, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Atributoss", wxPoint(20, 55 + 50), wxSize(100, 50));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "Herencia", wxPoint(20, 55 + 50 + 55), wxSize(100, 50));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "Polimorfismo", wxPoint(20, 55 + 50 + 55 + 55), wxSize(100, 50));
	wxButton* button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(550, 400), wxSize(200, 50));

    m_textCtrl = new wxStaticText(panel, wxID_ANY, "Texto inicial", wxPoint(140, 50), wxSize(400, 600), wxALIGN_LEFT);

	button5->Bind(wxEVT_BUTTON, &OOP::CloseClicked, this);
    button1->Bind(wxEVT_BUTTON, &OOP::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &OOP::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &OOP::OnButtonClick, this);
    button4->Bind(wxEVT_BUTTON, &OOP::OnButtonClick, this);
}

void OOP::CloseClicked(wxCommandEvent& evt) {
	Close();
}

void OOP::UpdateText(const wxString& newText)
{
    m_textCtrl->SetLabel(newText);
}

void OOP::OnButtonClick(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());

    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aquí puedes personalizar el texto según el botón presionado
        if (buttonText == "Clases") {
            UpdateText("Nuevo Texto 1");
        }
        else if (buttonText == "Atributoss") {
            UpdateText("Nuevo Texto 2");
        }
        else if (buttonText == "Herencia") {
            UpdateText("Nuevo Texto 3");
        }
        else if (buttonText == "Polimorfismo") {
            UpdateText("Nuevo Texto 4");
        }
        // Puedes agregar más condiciones según la lógica que desees
    }
}