#include "EFrame.h"
#include <wx/wx.h>


/* Se define el constructor de la sub ventana */
EFrame::EFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, title, pos, size)
{

	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Manejo de memoria", wxPoint(20, 50), wxSize(100, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Estructuras", wxPoint(20, 55 + 50), wxSize(100, 50));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "Algoritmos", wxPoint(20, 55 + 50 + 55), wxSize(100, 50));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "STL", wxPoint(20, 55 + 50 + 55 + 55), wxSize(100, 50));
	wxButton* button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(550, 400), wxSize(200, 50));

    m_textCtrl = new wxStaticText(panel, wxID_ANY, "Las estructuras de datos en C++ son formas de organizar y almacenar datos en la memoria de manera eficiente para facilitar su manipulación y acceso. ", wxPoint(140, 50), wxSize(400, 600), wxALIGN_LEFT);

	button5->Bind(wxEVT_BUTTON, &EFrame::CloseClicked, this);
    button1->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick, this);
    button4->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick, this);
}

// Se define el metodo para cerrar la ventana hija
void EFrame::CloseClicked(wxCommandEvent& evt) {
	Close();
}

void EFrame::UpdateText(const wxString& newText)
{
    m_textCtrl->SetLabel(newText);
}

void EFrame::OnButtonClick(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());

    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aquí puedes personalizar el texto según el botón presionado
        if (buttonText == "Manejo de memoria") {
            UpdateText(R"(Nuevo Texto 1)");
        }
        else if (buttonText == "Estructuras") {
            UpdateText("Nuevo Texto 2");
        }
        else if (buttonText == "Algoritmos") {
            UpdateText("Nuevo Texto 3");
        }
        else if (buttonText == "STL") {
            UpdateText("Nuevo Texto 4");
        }
        // Puedes agregar más condiciones según la lógica que desees
    }
}