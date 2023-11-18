#include "CFrame.h"
#include <wx/wx.h>
#include <string>

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

    m_textCtrl = new wxStaticText(panel, wxID_ANY, R"(C++ combina programación orientada a objetos, programación genérica y
característicasde programación de bajo nivel. Es una extensión del lenguaje
C con características adicionales, lo que le permite un mayor nivel de
abstracción y una manipulación eficiente de recursos de hardware.)", wxPoint(140, 50), wxSize(400, 300), wxALIGN_LEFT);

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
            UpdateText(R"(En C++, los "datatypes" (tipos de datos) se refieren a los distintos tipos de valores que pueden
ser almacenados y manipulados en un programa. Estos tipos de datos determinan la naturaleza
de los datos que una variable puede contener

Algunos de los tipos de datos básicos en C++ incluyen:

Enteros (integers): Representan números enteros sin parte decimal. 
Pueden ser con signo (positivos o negativos) o sin signo (únicamente positivos).

Punto flotante (floating-point): Representan números con parte decimal.

Caracteres y Cadenas: Almacenan caracteres individuales o secuencias de caracteres.

Booleanos: Representan valores lógicos verdadero o falso.

Void: Tipo especial que indica la ausencia de tipo.
)");
        }

        else if (buttonText == "Operadores") {
            UpdateText(R"(En C++, los operadores son símbolos especiales que permiten realizar operaciones sobre variables
 y valores. Estos operadores pueden ser aritméticos, de asignación, de comparación, lógicos, entre otros.)");
        }
        else if (buttonText == "Toma decisiones") {
            UpdateText(R"(En C++, las sentencias de toma de decisiones permiten controlar el flujo de un programa basado en
ciertas condiciones. Las más comunes son:

Sentencia if:
La sentencia if se utiliza para ejecutar un bloque de código si una condición es verdadera.

Operador Ternario ? ::
Es una forma compacta de expresar una sentencia if-else.

Sentencia switch:
Es útil cuando se deben tomar decisiones basadas en el valor de una variable.

La elección entre ellas depende de la lógica específica que necesites 
implementar. La sentencia if es la más versátil y se puede usar en la mayoría de los
casos, mientras que switch es útil cuando se necesitan comparaciones directas con un
conjunto limitado de valores para una variable. 
)");
        }
        else if (buttonText == "Loops") {
            UpdateText(R"(En C++, los bucles (loops) permiten ejecutar un bloque de código repetidamente mientras se cumpla
 una condición específica o durante un número predeterminado de iteraciones. Los bucles más comunes son:

Bucle for:
El bucle for se utiliza para ejecutar un bloque de código un número específico de veces.

Bucle while:
El bucle while se utiliza para ejecutar un bloque de código mientras se cumpla una condición.

Bucle do-while:
El bucle do-while es similar al while, pero garantiza que el bloque de código se ejecute
al menos una vez antes de verificar la condición.

La elección del bucle depende de la lógica y los requisitos de tu programa. El bucle
for es útil cuando sabes cuántas veces se debe ejecutar el código, while es apropiado
 cuando la condición para detenerse no se conoce de antemano y do-while es útil cuando
quieres que el código se ejecute al menos una vez antes de verificar la condición.)");
        }
        // Puedes agregar más condiciones según la lógica que desees
    }
}