#include "CFrame.h"
#include <wx/wx.h>


/* Se define el constructor de la sub ventana */
CFrame::CFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, title, pos, size)
{

	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "DataType", wxPoint(20, 50), wxSize(100, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Operadores", wxPoint(20, 55 + 50), wxSize(100, 50));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "Toma decisiones", wxPoint(20, 55 + 50 + 55), wxSize(100, 50));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "Loops", wxPoint(20, 55 + 50 + 55 + 55), wxSize(100, 50));
	wxButton* button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(550, 400), wxSize(200, 50));

    m_textCtrl = new wxStaticText(panel, wxID_ANY, "Texto inicial", wxPoint(140, 50), wxSize(400, 600), wxALIGN_LEFT);

	button5->Bind(wxEVT_BUTTON, &CFrame::CloseClicked, this);
    button1->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button4->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
}

// Se define el metodo para cerrar la ventana hija
void CFrame::CloseClicked(wxCommandEvent& evt) {
	Close();
}

void CFrame::UpdateText(const wxString& newText)
{
	m_textCtrl->SetLabel(newText);
}

void CFrame::OnButtonClick(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());

    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aquí puedes personalizar el texto según el botón presionado
        if (buttonText == "DataType") {
            UpdateText("Nuevo Texto 1");
        }
        else if (buttonText == "Operadores") {
            UpdateText("Nuevo Texto 2");
        }
        else if (buttonText == "Toma decisiones") {
            UpdateText("Nuevo Texto 3");
        }
        else if (buttonText == "Loops") {
            UpdateText("Nuevo Texto 4");
        }
        // Puedes agregar más condiciones según la lógica que desees
    }
}