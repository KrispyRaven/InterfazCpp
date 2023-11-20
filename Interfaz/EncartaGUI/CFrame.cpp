#include "CFrame.h"
#include <wx/wx.h>
#include <string>


int i = 1;

/* Se define el constructor de la sub ventana */
CFrame::CFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(parent, wxID_ANY, title, pos, size)
{

    wxPanel* panel = new wxPanel(this);
    this-> button1 = new wxButton(panel, wxID_ANY, "DataType", wxPoint(20, 50), wxSize(100, 50));
    this-> button2 = new wxButton(panel, wxID_ANY, "Operadores", wxPoint(20, 55 + 50), wxSize(100, 50));
    this-> button3 = new wxButton(panel, wxID_ANY, "Toma decisiones", wxPoint(20, 55 + 50 + 55), wxSize(100, 50));
    this-> button4 = new wxButton(panel, wxID_ANY, "Loops", wxPoint(20, 55 + 50 + 55 + 55), wxSize(100, 50));
    this-> button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(550, 400), wxSize(200, 50));
    this-> button6 = new wxButton(panel, wxID_ANY, "Siguiente", wxPoint(200, 400), wxSize(200, 50));

    this->button6->Show(false);
    
    

    this->m_textCtrl = new wxStaticText(panel, wxID_ANY, R"(C++ combina programación orientada a objetos, programación genérica y
características de programación de bajo nivel. Es una extensión del lenguaje
C con caracter?sticas adicionales, lo que le permite un mayor nivel de
abstracci?n y una manipulaci?n eficiente de recursos de hardware.)", wxPoint(140, 50), wxSize(400, 300), wxALIGN_LEFT);

    wxPNGHandler* handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    this->image = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("Images/C++.png", wxBITMAP_TYPE_PNG), wxPoint(150, 125), wxSize(500, 250));

    
    button1->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button4->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button5->Bind(wxEVT_BUTTON, &CFrame::CloseClicked, this);
    button6->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);

}

// Se define el metodo para cerrar la ventana hija
void CFrame::CloseClicked(wxCommandEvent& evt) {
    Close();
}

// Metodo que se encarga de actualizar la imagen del objeto image creado en el constructor
void CFrame::Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY) {
    image->SetBitmap(wxBitmap(newimage, wxBITMAP_TYPE_PNG));
    image->SetPosition(wxPoint(posX, posY));
    image->SetSize(wxSize(pixX, pixY));
}


void CFrame::UpdateText(const wxString& newText)
{
    m_textCtrl->SetLabel(newText);
}



void CFrame::OnButtonClick(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    this->button6->Show(false);


    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aquí puedes personalizar el texto según el bot?n presionado
        if (buttonText == "DataType") {
            UpdateText(R"(En C++, los "datatypes" (tipos de datos) se refieren a los distintos tipos de valores que pueden
ser almacenados y manipulados en un programa. Estos tipos de datos determinan la naturaleza
de los datos que una variable puede contener

Algunos de los tipos de datos básicos en C++ incluyen:

Enteros (integers): Representan números enteros sin parte decimal. 
Pueden ser con signo (positivos o negativos) o sin signo (?nicamente positivos).

Punto flotante (floating-point): Representan n?meros con parte decimal.

Caracteres y Cadenas: Almacenan caracteres individuales o secuencias de caracteres.

Booleanos: Representan valores l?gicos verdadero o falso.

Void: Tipo especial que indica la ausencia de tipo.
)");

            Updateimage("Images/datatypes.png",400, 190, 140, 350);
        }

        else if (buttonText == "Operadores") {
            UpdateText(R"(En C++, los operadores son s?mbolos especiales que permiten realizar operaciones sobre variables
 y valores. Estos operadores pueden ser aritm?ticos, de asignaci?n, de comparaci?n, l?gicos, entre otros.)");
            
            
            this->button6->Show(true);
            Updateimage("Images/aritmeticos.png", 450, 168, 140, 100);

        }
        else if (buttonText == "Toma decisiones") {
            UpdateText(R"(En C++, las sentencias de toma de decisiones permiten controlar el flujo de un programa basado en
ciertas condiciones. Las m?s comunes son:

Sentencia if:
La sentencia if se utiliza para ejecutar un bloque de c?digo si una condici?n es verdadera.

Operador Ternario ? ::
Es una forma compacta de expresar una sentencia if-else.

Sentencia switch:
Es ?til cuando se deben tomar decisiones basadas en el valor de una variable.

La elecci?n entre ellas depende de la l?gica espec?fica que necesites 
implementar. La sentencia if es la m?s vers?til y se puede usar en la mayor?a de los
casos, mientras que switch es ?til cuando se necesitan comparaciones directas con un
conjunto limitado de valores para una variable. 
)");

        
        }
        else if (buttonText == "Loops") {
            UpdateText(R"(En C++, los bucles (loops) permiten ejecutar un bloque de c?digo repetidamente mientras se cumpla
 una condición espec?fica o durante un n?mero predeterminado de iteraciones. Los bucles m?s comunes son:

Bucle for:
El bucle for se utiliza para ejecutar un bloque de c?digo un n?mero espec?fico de veces.

Bucle while:
El bucle while se utiliza para ejecutar un bloque de c?digo mientras se cumpla una condici?n.

Bucle do-while:
El bucle do-while es similar al while, pero garantiza que el bloque de c?digo se ejecute
al menos una vez antes de verificar la condición.

La elecci?n del bucle depende de la l?gica y los requisitos de tu programa. El bucle
for es ?til cuando sabes cu?ntas veces se debe ejecutar el c?digo, while es apropiado
 cuando la condici?n para detenerse no se conoce de antemano y do-while es ?til cuando
quieres que el c?digo se ejecute al menos una vez antes de verificar la condición.)");
        }
        else if (buttonText == "Siguiente") {

            this->button6->Show(true);
            
            if (i == 4) {
                i = 0;
            }

            wxString lista[] = { "Images/aritmeticos.png", "Images/asignacion.png", "Images/comparacion.png", "Images/logicos.png" };

            int pixelY[] = {168,255,175,103};
            

            Updateimage(lista[i], 450 , pixelY[i], 140, 100);
            
            i += 1;
        }
        // Puedes agregar más condiciones seg?n la lógica que desees
    }
}