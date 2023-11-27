#include "CFrame.h"
#include <wx/wx.h>
#include <string>


int i = 1;

wxDEFINE_EVENT(wxEVT_CFRAME_CLOSED, wxCommandEvent);

/* Se define el constructor de la sub ventana */
CFrame::CFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(parent, wxID_ANY, title, pos, size)
{

    
    panel = new wxPanel(this);
    this-> button1 = new wxButton(panel, wxID_ANY, "DataType", wxPoint(20, 50), wxSize(100, 50));
    this-> button2 = new wxButton(panel, wxID_ANY, "Operadores", wxPoint(20, 55 + 50), wxSize(100, 50));
    this-> button3 = new wxButton(panel, wxID_ANY, "Toma decisiones", wxPoint(20, 55 + 50 + 55), wxSize(100, 50));
    this-> button4 = new wxButton(panel, wxID_ANY, "Loops", wxPoint(20, 55 + 50 + 55 + 55), wxSize(100, 50));
    this-> button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(650, 550), wxSize(200, 50));
    this-> button6 = new wxButton(panel, wxID_ANY, "Siguiente", wxPoint(200, 550), wxSize(200, 50));

    this->button6->Show(false);
    
    
    button1->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button4->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);
    button5->Bind(wxEVT_BUTTON, &CFrame::CloseClicked, this);
    button6->Bind(wxEVT_BUTTON, &CFrame::OnButtonClick, this);


    // Establecer color gris RGB: (128, 128, 128) en el objeto panel
    panel->SetBackgroundColour(wxColour(128, 128, 128));

  this->m_textCtrl = new wxStaticText(panel, wxID_ANY, R"(C++ combina programación orientada a objetos, programación genérica y características de 
programación de bajo nivel. Es una extensión del lenguaje C con características adicionales, 
lo que le permite un mayor nivel de abstracción y una manipulación eficiente de recursos de 
hardware.)", wxPoint(140, 30), wxSize(400, 300), wxALIGN_LEFT);

    // Creamos un objeto para definir el tamaño de letra, la familia de estilos, tipo de letra, grosor de la letra
    wxFont font(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRAHEAVY);

    // Establecer la fuente en el objeto wxStaticText aplicando el metodo SetFont
    this->m_textCtrl->SetFont(font);

    wxPNGHandler* handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    this->image = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("Images/C++.png", wxBITMAP_TYPE_PNG), wxPoint(150, 125), wxSize(500, 250));


}



// Se define el metodo para cerrar la ventana hija
void CFrame::CloseClicked(wxCommandEvent& evt) {
    wxCommandEvent closeEvent(wxEVT_CFRAME_CLOSED);
    wxPostEvent(this, closeEvent);
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
    // Textos principales de cada pestaña

    // DataType
    wxString datatype_text = R"(En C++, los "datatypes" (tipos de datos) se refieren a los distintos tipos de valores que pueden
ser almacenados y manipulados en un programa. Estos tipos de datos determinan la naturaleza
de los datos que una variable puede contener

Algunos de los tipos de datos básicos en C++ incluyen:

Enteros (integers): Representan números enteros sin parte decimal. 
Pueden ser con signo (positivos o negativos) o sin signo (únicamente positivos).

Punto flotante (floating-point): Representan n?meros con parte decimal.

Caracteres y Cadenas: Almacenan caracteres individuales o secuencias de caracteres.

Booleanos: Representan valores lógicos verdadero o falso.

Void: Tipo especial que indica la ausencia de tipo.
)";

    //Operadores
    wxString operadores_text = R"(En C++, los operadores son símbolos especiales que permiten realizar operaciones sobre variables
 y valores. Estos operadores pueden ser aritméticos, de asignación, de comparación, 
lógicos, entre otros.)";

    // Toma de decisiones

    wxString decisiones_text = R"(En C++, las sentencias de toma de decisiones permiten controlar el flujo de un programa basado en
ciertas condiciones. Las más comunes son:

- Sentencia if:
La sentencia if se utiliza para ejecutar un bloque de código si una condición es verdadera.

- Operador Ternario ? ::
Es una forma compacta de expresar una sentencia if-else.

- Sentencia switch:
Es útil cuando se deben tomar decisiones basadas en el valor de una variable.

La elección entre ellas depende de la lógica específica que necesites 
implementar. La sentencia if es la más versátil y se puede usar en la mayoría de los
casos, mientras que switch es útil cuando se necesitan comparaciones directas con un
conjunto limitado de valores para una variable. 
)";

    // Loops

    wxString Loops_text = R"(En C++, los bucles (loops) permiten ejecutar un bloque de código repetidamente mientras se cumpla
 una condición específica o durante un número predeterminado de iteraciones. Los bucles 
más comunes son:

- Bucle for:
El bucle for se utiliza para ejecutar un bloque de código un número específico de veces.

- Bucle while:
El bucle while se utiliza para ejecutar un bloque de código mientras se cumpla una condición.

- Bucle do-while:
El bucle do-while es similar al while, pero garantiza que el bloque de código se ejecute
al menos una vez antes de verificar la condición.

La elección del bucle depende de
la lógica y los requisitos de tu 
programa. El bucle for es útil 
cuando sabes cuantas veces se de-
be ejecutar el código, while es 
apropiado cuando la condición pa-
ra detenerse no se conoce de ante-
mano y do-while es útil cuando 
quieres que el código se ejecute 
al menos una vez antes de verifi-
car la condición.)";

    // Ejemplo en Toma de decisiones

    wxString decisiones_example = R"( En la figura se muestra un codigo decisionesss
)";

    // Ejemplo en Loops

    wxString Loops_example = R"( En la figura se muestra un codigo Lopps
)";










    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    this->button6->Show(false);


    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aquí puedes personalizar el texto según el bot?n presionado
        if (buttonText == "DataType") {
            UpdateText(datatype_text);

            Updateimage("Images/datatypes.png",400, 190, 140, 350);
        }

        else if (buttonText == "Operadores") {
            UpdateText(operadores_text);
            
            i = 1;
            button6->SetLabel("Siguiente");
            button6->Show(true);
            Updateimage("Images/aritmeticos.png", 650, 260, 155, 100);

        }
        else if (buttonText == "Toma decisiones") {
            i = 1;
            UpdateText(decisiones_text);
            button6->SetLabel("Ver ejemplo");
            button6->Show(true);

            Updateimage("Images/decisiones.png", 400, 194, 140, 330);


        }
        else if (buttonText == "Loops") {
            i = 4;
            UpdateText(Loops_text);
            button6->SetLabel("Ver ejemplo");
            button6->Show(true);

            Updateimage("Images/loops.png", 450, 270, 410, 270);
        }
        else if (buttonText == "Siguiente") {

            this->button6->Show(true);
            
            if (i == 4) {
                i = 0;
            }

            wxString lista[] = { "Images/aritmeticos.png", "Images/asignacion.png", "Images/comparacion.png", "Images/logicos.png" };

            int pixelY[] = {260,401,268,143};
            

            Updateimage(lista[i], 650 , pixelY[i], 155, 100);
            
            i += 1;
        }
        else if (buttonText == "Ver ejemplo" || buttonText == "Mostrar info again"  ) {

            button6->SetLabel("Mostrar info again");
            button6->Show(true);

            if (i == 2) {
                button6->SetLabel("Ver ejemplo");
                button6->Show(true);
                i = 0;
            }

            if (i == 5) {
                button6->SetLabel("Ver ejemplo");
                button6->Show(true);
                i = 3;

            }

            //Posibles textos a desplegar en las pestañas Toma de decisiones (index 0 y 1) y Loops (index 2 y 3)
            wxString textos[] = { decisiones_text, decisiones_example," ", Loops_text, Loops_example};

            UpdateText(textos[i]);
            
            // Posibles imagenes a desplegar en las pestañas Toma de decisiones (index 0 y 1) y Loops (index 2 y 3)
            
            int pixY[] = { 194, 242,1, 270, 450 };
            int pixX[] = { 400, 650 ,1, 450, 304};
            int posiY[] = { 330, 180,1, 270, 70 };
            int posiX[] = { 250, 140,1, 410, 350 };

            wxString imagenes[] = {"Images/decisiones.png", "Images/decisionesEj.png"," ", "Images/loops.png", "Images/loopsEj.png"  };
            Updateimage(imagenes[i], pixX[i], pixY[i], posiX[i], posiY[i]);
            
            i += 1;

        }
    }
}