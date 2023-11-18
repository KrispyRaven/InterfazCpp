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

    m_textCtrl = new wxStaticText(panel, wxID_ANY, R"(La Programación Orientada a Objetos (POO) es un paradigma de programación que se basa en el concepto de "objetos" para organizar y estructurar el código. Se centra en modelar entidades del mundo real como objetos con atributos (datos) y comportamientos (métodos o funciones).)", wxPoint(140, 50), wxSize(400, 300), wxALIGN_LEFT);

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
            UpdateText(R"(Las clases son como plantillas o moldes que definen las características y comportamientos
de un objeto. Los objetos son instancias individuales de estas clases)");
        }
        else if (buttonText == "Abstraccion") {
            UpdateText( R"(Permite representar características esenciales de un objeto sin mostrar todos los
detalles complejos de su implementación.)");
        }
        else if (buttonText == "Herencia") {
            UpdateText(R"(Permite que una clase (llamada subclase o clase derivada) herede atributos y métodos
de otra clase (llamada superclase o clase base), facilitando la reutilización de código
y la creación de jerarquías.)");
        }
        else if (buttonText == "Polimorfismo") {
            UpdateText(R"(Permite que los objetos de diferentes clases sean tratados de manera uniforme a través
 de interfaces comunes, lo que permite que un objeto sea usado como si fuera de otro tipo.)");
        }
        // Puedes agregar más condiciones según la lógica que desees
    }
}