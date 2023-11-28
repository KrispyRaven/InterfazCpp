#include "OOP.h"
#include <wx/wx.h>






OOP::OOP(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : CFrame(parent, title, pos, size)
{

    //wxPanel* panel = new wxPanel(this);
    button2->Show(false);
    button1->SetLabel("Clases");
    button3->SetLabel("Herencia");
    button4->SetLabel("Polimorfismo");
    
    button1->SetPosition(wxPoint(20, 50 + 130));
    button3->SetPosition(wxPoint(20, 55 + 50 + 130));
    button4->SetPosition(wxPoint(20, 55 + 50 + 55 + 130));

   

    button6->Show(false);

    
    button1->Bind(wxEVT_BUTTON, &OOP::OnButtonClick1, this);
    button3->Bind(wxEVT_BUTTON, &OOP::OnButtonClick1, this);
    button4->Bind(wxEVT_BUTTON, &OOP::OnButtonClick1, this);
    button6->Bind(wxEVT_BUTTON, &OOP::OnButtonClick1, this);

    m_textCtrl->SetLabel(R"( La Programación Orientada a Objetos (POO) es un paradigma de programación 
que se basa en el concepto de "objetos" para organizar y estructurar el código. 
Se centra en modelar entidades del mundo real como objetos con atributos (datos) 
y comportamientos (métodos o funciones).)");

    m_textCtrl->SetPosition(wxPoint(170, 50));

    Updateimage("Images/OOP.png", 439, 330, 250, 150);

}



void OOP::OnButtonClick1(wxCommandEvent& event)
{
    wxString clases_text = R"(Las clases son como plantillas o moldes que definen las características y comportamientos
de un objeto. Los objetos son instancias individuales de estas clases. A continuación 
se muestra un ejemplo de cómo se implementa. En el archivo .hpp declaramos 4 atributos 
de la clase NotaStd y colocamos los prototipos de dos métodos que esta clase posee. Uno
de ellos es el constructor, el cual debe llevar el mismo nombre de la clase. En el archivo
.cpp debemos implementar los métodos y atributos definidos anteriormente en el .hpp.
)";

    wxString abstraccion_text = R"(Permite representar características esenciales de un objeto sin mostrar todos los
detalles complejos de su implementación.)";

    wxString herencia_text = R"(Permite que una clase (llamada subclase o clase derivada) herede atributos y métodos
de otra clase (llamada superclase o clase base), facilitando la reutilización de código
y la creación de jerarquías. En el ejemplo mostrado, se tienen lo siguientes archivos :
Shape.h, Rectangle.hpp, Shape.cpp y Shape.cpp. En este caso, la clase madre sería 
Shape y la clase hija sería Rectangle. Dado que la clase hija hereda los métodos 
de la clase madre, se podrían utilizar los métodos setWidth y setHeight para defi-
nir los atributos de la clase Shape, los cuales también son hereados por la clase 
hija. Finalmente, se podría utilizar el método getArea de la clase Rectangle para
obtener el area del objeto creado.)";

    wxString poli_text = R"(Permite que los objetos de diferentes clases sean tratados de manera uniforme a través de
interfaces comunes, lo que permite que un objeto sea usado como si fuera de otro tipo.
Por ejemplo, note que se crea un puntero objeto tipo Base, el cual apunta a un objeto 
tipo Derivada en memoria dinámica. El métodoOne existe en ambas clases, no obstante, 
se decide darle prioridad al MetodoOne() de la clase derivada, debido a que esta no es
virtual. Por el contrario, el métodoTwo( ) se elige de la clase base, ya que originalmente
el objeto es de tipo Base. )";
    
    
    
    
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if (button)
    {
        wxString buttonText = button->GetLabel();
        
        
        // Segun el boton presionado, ejecute una funcionalidad particular
        
        
        if (buttonText == "Clases") {
            i = 1;
            // Actualizamos el label y mostramos el objeto en pantalla
            button6->SetLabel("Ver .cpp");
            button6->Show(true);

            // Actualizamos el valor del objeto imagen
            Updateimage("Images/hppclases.png", 600, 327, 180, 180);

            UpdateText(clases_text);
        }
        else if (buttonText == "Herencia") {
            i = 4;
            UpdateText(herencia_text);
            button6->SetLabel("Ver .cpp");
            button6->Show(true);

            Updateimage("Images/herenciahpp.png", 650, 187, 180, 300);
        }
        else if (buttonText == "Polimorfismo") {
            button6->Show(false);
            UpdateText(poli_text);
            Updateimage("Images/poli.png", 700, 162, 140, 200);

        }
        else if (buttonText == "Ver .cpp" || buttonText == "Ver .hpp") {

            button6->SetLabel("Ver .hpp");
            button6->Show(true);

            if (i == 2) {
                button6->SetLabel("Ver .cpp");
                button6->Show(true);
                i = 0;
            }

            if (i == 5) {
                button6->SetLabel("Ver .cpp");
                button6->Show(true);
                i = 3;

            }


            // Posibles imagenes a desplegar en las pestañas Toma de decisiones (index 0 y 1) y Loops (index 2 y 3)

            int pixY[] = { 327, 280,1, 187, 161 };
            int pixX[] = { 600, 600 ,1, 650, 650 };
            int possY[] = { 180, 180,1, 300, 300 };
            int possX[] = { 180, 180,1, 180, 180 };

            wxString imagenes[] = { "Images/hppclases.png", "Images/cppclases.png"," ", "Images/herenciahpp.png", "Images/herenciacpp.png"};
            Updateimage(imagenes[i], pixX[i], pixY[i], possX[i], possY[i]);

            i += 1;


        }
       
    }
}