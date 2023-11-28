#include "QFrame.h"
#include <wx/wx.h>

wxDEFINE_EVENT(wxEVT_QFRAME_CLOSED, wxCommandEvent);

int e = 0;
string temita = "";

/* Se define el constructor de la sub ventana */
QFrame::QFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(parent, wxID_ANY, title, pos, size)
{
    this->parent = parent;
    wxPanel* panel = new wxPanel(this);
    this->button1 = new wxButton(panel, wxID_ANY, "Tema 1: C/C++", wxPoint(20, 50), wxSize(120, 50));
    this->button2 = new wxButton(panel, wxID_ANY, "Tema 2: OPP", wxPoint(20, 55 + 50), wxSize(120, 50));
    this->button3 = new wxButton(panel, wxID_ANY, "Tema 3: Estructuras", wxPoint(20, 55 + 50 + 55), wxSize(120, 50));
    this->button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(560, 400), wxSize(230, 50));
    this->button6 = new wxButton(panel, wxID_ANY, "Siguiente", wxPoint(200, 400), wxSize(200, 50));
    this->Bind(wxEVT_CLOSE_WINDOW, &QFrame::OnCerrarVentana, this);
    this->button6->Show(false);

    this->buttonA = new wxCheckBox(panel, wxID_ANY, "A)", wxPoint(180, 105));
    this->buttonB = new wxCheckBox(panel, wxID_ANY, "B)", wxPoint(180, 140));
    this->buttonC = new wxCheckBox(panel, wxID_ANY, "C)", wxPoint(180, 175));
    this->buttonD = new wxCheckBox(panel, wxID_ANY, "D)", wxPoint(180, 210));

    this->pastButton = nullptr;

    this->buttonA->Show(false); 
    this->buttonB->Show(false);
    this->buttonC->Show(false);
    this->buttonD->Show(false);


 // Establecer color gris RGB: (128, 128, 128) en el objeto panel
    panel->SetBackgroundColour(wxColour(128, 128, 128));


// Este objeto representa el texto principal mostrado en la ventana actual (objeto)
    this->m_textCtrl = new wxStaticText(panel, wxID_ANY, R"(EVALUACIÓN DE SUS CONOCIMIENTOS)", wxPoint(300, 100), wxSize(250, 100), wxALIGN_LEFT);

// Creamos un objeto para definir el tamaño de letra, la familia de estilos, tipo de letra, grosor de la letra
    wxFont font(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRAHEAVY);

// Establecer la fuente en el objeto wxStaticText aplicando el metodo SetFont
    this->m_textCtrl->SetFont(font);



// Este objeto representa el texto secundario u opcional que se podría mostrar en la ventana actual
    this->extra_text = new wxStaticText(panel, wxID_ANY,"", wxPoint(350, 330), wxSize(300, 50), wxALIGN_LEFT);
    extra_text->Hide();
    this->extra_text->SetFont(font);



// Bindigs de botones normales
    button1->Bind(wxEVT_BUTTON, &QFrame::OnButtonClick, this);
    button2->Bind(wxEVT_BUTTON, &QFrame::OnButtonClick, this);
    button3->Bind(wxEVT_BUTTON, &QFrame::OnButtonClick, this);
    button5->Bind(wxEVT_BUTTON, &QFrame::CloseClicked, this);
    button6->Bind(wxEVT_BUTTON, &QFrame::OnButtonClick, this);

// Bindings de check boxes
    buttonA->Bind(wxEVT_CHECKBOX, &QFrame::ABCDClick, this);
    buttonB->Bind(wxEVT_CHECKBOX, &QFrame::ABCDClick, this);
    buttonC->Bind(wxEVT_CHECKBOX, &QFrame::ABCDClick, this);
    buttonD->Bind(wxEVT_CHECKBOX, &QFrame::ABCDClick, this);

    // Creamos un nuevo objeto (image)
    wxPNGHandler* handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    this->image = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("Images/quices.png", wxBITMAP_TYPE_PNG), wxPoint(250, 200), wxSize(285, 350));


}





// Se define el metodo para cerrar la ventana hija
void QFrame::CloseClicked(wxCommandEvent& evt) {
    // Ocultar la ventana secundaria
    this->Hide();

    // Mostrar la ventana principal nuevamente
    if (parent && !parent->IsBeingDeleted()) {
        parent->Show();
    };
}


void QFrame::Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY) {
    image->SetBitmap(wxBitmap(newimage, wxBITMAP_TYPE_PNG));
    image->SetPosition(wxPoint(posX, posY));
    image->SetSize(wxSize(pixX, pixY));
}





void QFrame::UpdateQuestion(const wxString& Question, const wxString& OpcionA, const wxString& OpcionB, const wxString& OpcionC, const wxString& OpcionD, int posX, int posY)
{   // Creamos un objeto para definir el tamaño de letra, la familia de estilos, tipo de letra, grosor de la letra
    wxFont fonti(11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRAHEAVY);
    // Establecer la fuente en el objeto wxStaticText aplicando el metodo SetFont
    this->m_textCtrl->SetFont(fonti);
    const wxString& newText = Question + "\n\n\n" + OpcionA + "\n\n" + OpcionB + "\n\n" + OpcionC + "\n\n" + OpcionD;
    m_textCtrl->SetLabel(newText);
    m_textCtrl->SetPosition(wxPoint(posX, posY));
}




void QFrame::UpdateExtraText(const wxString& text, int posX, int posY)
{
    extra_text->SetLabel(text);
    extra_text->SetPosition(wxPoint(posX, posY));
    extra_text->Show();

}






void QFrame::OnButtonClick(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());

    // Mostramos botones propios de la Ventana
    this->button6->Show(true);
    this->buttonA->Show(true);
    this->buttonB->Show(true);
    this->buttonC->Show(true);
    this->buttonD->Show(true);

    image->Show(false);


    if (button)
    {
        wxString buttonText = button->GetLabel();

        if(buttonText != "Siguiente") {
            e = 0;
        }

        if (pastButton != nullptr) {
            // Reseteo el check del ultimo checkbox estripado
            pastButton->SetValue(false);
        }

        // Ocultamos el ultimo texto extra guardado en el objeto: extra_text
        extra_text->Hide();
        
        // Aquí puedes personalizar el texto según el botón presionado
        if (buttonText == "Tema 1: C/C++"|| (buttonText == "Siguiente"&& temita == "C++")) {
            temita = "C++";
            // Preguntas
            wxString Pregunta1 = "¿Cuál de estos tipos de datos elegiría si desea utilizar un numero con decimales ?";
            wxString Pregunta2 = "Cuál de estos operadores representa la operación lógica AND?";
            wxString Pregunta3 = "Si resultado = 5.5, cual sería el código correcto? (suponga que float A = 2.2)";
            wxString Pregunta4 = "Cuál es la diferencia entre el bucle while y do while?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "float";
            wxString RespuestaA2 = "&&";
            wxString RespuestaA3 = "float resultado = (A > 1) ? 5.5 : 1.4";
            wxString RespuestaA4 = "do-while ejecuta al menos una vez un bloque de código antes de verificar la condición.";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "int";
            wxString RespuestaB2 = "||";
            wxString RespuestaB3 = "float resultado = (A > 1) ? 1.4 : 5.5";
            wxString RespuestaB4 = "No existe ninguna diferencia entre ambos bucles";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "bool";
            wxString RespuestaC2 = "|";
            wxString RespuestaC3 = "float resultado = (A < 1) ? 5.5 : 1.4";
            wxString RespuestaC4 = "while ejecuta al menos una vez un bloque de código antes de verificar la condición.";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "char";
            wxString RespuestaD2 = "+";
            wxString RespuestaD3 = "float resultado = (A < 1) ? 5.0 : 1.4 ";
            wxString RespuestaD4 = "do-while ejecuta al menos 5 veces un bloque de código antes de verificar la condición.";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 218, 50);


            e += 1;

            if (e == 4) {
                e = 0;
            }
        }

        else if (buttonText == "Tema 2: OPP"||(buttonText == "Siguiente" && temita == "OPP")) {
            temita = "OPP";
            this->button6->Show(true);



            wxString Pregunta1 = "Un atributo es lo mismo que un método de un objeto creado?";
            wxString Pregunta2 = "¿Cuál keyword utilizaría para establecer 0 restricciones de acceso a métodos o atributos?";
            wxString Pregunta3 = "Al trabajar con clases, ¿por qué se utiliza un archivo .hpp y otro archivo .cpp?";
            wxString Pregunta4 = "Una clase puede heredar los métodos de otra clase?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "Sí, es lo mismo";
            wxString RespuestaA2 = "protected";
            wxString RespuestaA3 = "En ambos archivos se define lo mismo, por seguridad.";
            wxString RespuestaA4 = "No es posible";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "No, son cosas distintas";
            wxString RespuestaB2 = "public";
            wxString RespuestaB3 = "En el.hpp se inicializan atributos y los métodos. En el .cpp se implementan.";
            wxString RespuestaB4 = "Sí, gracias a la herencia es posible";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "Sí son lo mismo, solo que el usuario solo puede utilizar los métodos de la clase.";
            wxString RespuestaC2 = "private";
            wxString RespuestaC3 = "En el .cpp se inicializan atributos y los métodos. En el .hpp se implementan.";
            wxString RespuestaC4 = "Sí, pero solo puede heredar un método.";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "No son lo mismo, el usuario solo puede utilizar los métodos de la clase.";
            wxString RespuestaD2 = "free";
            wxString RespuestaD3 = "En el.hpp solo se inicializan atributos. En el .cpp se implementan solo los métodos.";
            wxString RespuestaD4 = "Sí, con la condición de que la clase derivada no puede crear métodos dentro esta.";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 218, 50);


            e += 1;

            if (e == 4) {
                e = 0;
            }

            





        }
        else if (buttonText == "Tema 3: Estructuras"|| (buttonText == "Siguiente" && temita == "estructuras")) {
            temita = "estructuras";
            this->button6->Show(true);

            // Preguntas
            wxString Pregunta1 = "¿Cuál de las siguientes opciones es una estructura de datos que permite almacenar \n elementos de manera ordenada y acceder a ellos mediante un índice?";
            wxString Pregunta2 = "¿Cuál de los siguientes algoritmos de ordenamiento tiene una complejidad temporal \npromedio de O(n log n)?";
            wxString Pregunta3 = " ¿Cuál de las siguientes estructuras de datos de la Standard Template Library (STL)\n se utiliza para almacenar elementos sin repetición y garantiza la búsqueda rápida?";
            wxString Pregunta4 = "¿Qué estructura de datos se utiliza para almacenar elementos de manera no ordenada y\n permite el acceso rápido a ellos mediante una clave única?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "Lista";
            wxString RespuestaA2 = "Bubble Sort";
            wxString RespuestaA3 = "std::vector";
            wxString RespuestaA4 = "Árbol binario";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "Pila";
            wxString RespuestaB2 = "Insertion Sort";
            wxString RespuestaB3 = "std::list";
            wxString RespuestaB4 = "Set";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "Set";
            wxString RespuestaC2 = "Quick Sort";
            wxString RespuestaC3 = "std::set";
            wxString RespuestaC4 = "Diccionario";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "Cola";
            wxString RespuestaD2 = "Selection Sort";
            wxString RespuestaD3 = "std::map";
            wxString RespuestaD4 = "Lista enlazada";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 218, 30);


            e += 1;

            if (e == 4) {
                e = 0;
            }
           
        }
        // Puedes agregar más condiciones seg?n la lógica que desees
    }
}





void QFrame::ABCDClick(wxCommandEvent& event)
{
   
    wxCheckBox* ABCD = dynamic_cast<wxCheckBox*>(event.GetEventObject());
    

    if (ABCD)
    {   
        
        
        if (pastButton == nullptr) {
            pastButton = ABCD;
            
        }
        pastButton->SetValue(false);
        pastButton = ABCD;
        


        wxString ABCD_str = ABCD->GetLabel();
        ABCD->SetValue(true);
        
        if(temita == "C++") {
            
            if (ABCD_str == "A)") {
                UpdateExtraText("Respuesta correcta amig@ :)", 350, 300);
            }
            else {
                UpdateExtraText("Respuesta incorrecta amig@ :(", 350, 300);
            }
            
        }
        else if (temita == "OPP") {

            if (ABCD_str == "B)") {
                UpdateExtraText("Respuesta correcta :)", 350, 300);
            }
            else {

                UpdateExtraText("Respuesta incorrecta :(", 350, 300);
            }
    
        }
        else if (temita == "estructuras") {

            if (ABCD_str == "C)") {
                UpdateExtraText("Respuesta correcta ak7 :)", 350, 300);
            }
            else {
                UpdateExtraText("Respuesta incorrecta mae :(", 350, 300);
            }
    
        }
    }
}


void QFrame::OnCerrarVentana(wxCloseEvent& event) {
    // Si la ventana principal aún existe, cerrarla y terminar la aplicación
    if (parent && !parent->IsBeingDeleted()) {
        parent->Close();
        this->Destroy();
    }
}



