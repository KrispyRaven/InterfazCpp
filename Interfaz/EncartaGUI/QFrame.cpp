#include "QFrame.h"
#include <wx/wx.h>

wxDEFINE_EVENT(wxEVT_QFRAME_CLOSED, wxCommandEvent);

int e = 0;
string temita = "";

/* Se define el constructor de la sub ventana */
QFrame::QFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(parent, wxID_ANY, title, pos, size)
{

    wxPanel* panel = new wxPanel(this);
    this->button1 = new wxButton(panel, wxID_ANY, "Tema 1: C/C++", wxPoint(20, 50), wxSize(120, 50));
    this->button2 = new wxButton(panel, wxID_ANY, "Tema 2: OPP", wxPoint(20, 55 + 50), wxSize(120, 50));
    this->button3 = new wxButton(panel, wxID_ANY, "Tema 3: Estructuras", wxPoint(20, 55 + 50 + 55), wxSize(120, 50));
    this->button5 = new wxButton(panel, wxID_ANY, "Regresar al menu principal", wxPoint(550, 400), wxSize(200, 50));
    this->button6 = new wxButton(panel, wxID_ANY, "Siguiente", wxPoint(200, 400), wxSize(200, 50));

    this->button6->Show(false);


    this->buttonA = new wxCheckBox(panel, wxID_ANY, "A)", wxPoint(260, 105));
    this->buttonB = new wxCheckBox(panel, wxID_ANY, "B)", wxPoint(260, 140));
    this->buttonC = new wxCheckBox(panel, wxID_ANY, "C)", wxPoint(260, 175));
    this->buttonD = new wxCheckBox(panel, wxID_ANY, "D)", wxPoint(260, 210));

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

}




// Se define el metodo para cerrar la ventana hija
void QFrame::CloseClicked(wxCommandEvent& evt) {
    wxCommandEvent closeEvent(wxEVT_QFRAME_CLOSED);
    wxPostEvent(this, closeEvent);
    Close();
}

// Metodo que se encarga de actualizar la imagen del objeto image creado en el constructor
void QFrame::Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY) {
    image->SetBitmap(wxBitmap(newimage, wxBITMAP_TYPE_PNG));
    image->SetPosition(wxPoint(posX, posY));
    image->SetSize(wxSize(pixX, pixY));
}



// Los siguientes dos metodos son llamados para actualizar el valor de los objetos: m_textCtrl y extra_text
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
            wxString Pregunta1 = "Que es un entero?";
            wxString Pregunta2 = "Que es la vida";
            wxString Pregunta3 = "Que es un datatype";
            wxString Pregunta4 = "Quien es usted?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "Es un numero sin decimales";
            wxString RespuestaA2 = "Es un despiche";
            wxString RespuestaA3 = "Un tipo de dato jajaj XD";
            wxString RespuestaA4 = " A usted que le importa";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "Es un numero CON decimales";
            wxString RespuestaB2 = "Yo que se";
            wxString RespuestaB3 = "Es una carajada vacilona";
            wxString RespuestaB4 = " Don Pedro";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "I dont know dude";
            wxString RespuestaC2 = "El profe sabe";
            wxString RespuestaC3 = "Pinto";
            wxString RespuestaC4 = " Don Luis";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "La C es la correcta";
            wxString RespuestaD2 = "El profe NO sabe";
            wxString RespuestaD3 = "Pinto con huevooo";
            wxString RespuestaD4 = "El presidente";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 300, 50);


            e += 1;

            if (e == 4) {
                e = 0;
            }
        }

        else if (buttonText == "Tema 2: OPP"||(buttonText == "Siguiente" && temita == "OPP")) {
            temita = "OPP";
            this->button6->Show(true);



            wxString Pregunta1 = "Que es un entXDDDDDDDDDero?";
            wxString Pregunta2 = "Que es la vidXDDDDDDDDDa";
            wxString Pregunta3 = "Que es un datXDDDDDDDDDatype";
            wxString Pregunta4 = "Quien es usteXDDDDDDDDDd?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "Es un numero XDDDDDDDsin decimales";
            wxString RespuestaA2 = "Es un despichXDDDDDDDe";
            wxString RespuestaA3 = "Un tipo de daXDDDDDDDto jajaj XD";
            wxString RespuestaA4 = " A usted que XDDDDDDDle importa";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "Es un XDDDDnumero CON decimales";
            wxString RespuestaB2 = "Yo queXDDDD se";
            wxString RespuestaB3 = "Es unaXDDDD carajada vacilona";
            wxString RespuestaB4 = " Don PXDDDDedro";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "I doXDDDDDDnt know dude";
            wxString RespuestaC2 = "El pXDDDDDDrofe sabe";
            wxString RespuestaC3 = "PintXDDDDDDo";
            wxString RespuestaC4 = " DonXDDDDDD Luis";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "La C es XDDDDDDDDla correcta";
            wxString RespuestaD2 = "El profeXDDDDDDDD NO sabe";
            wxString RespuestaD3 = "Pinto coXDDDDDDDDn huevooo";
            wxString RespuestaD4 = "El presiXDDDDDDDDdente";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 300, 50);


            e += 1;

            if (e == 4) {
                e = 0;
            }

            





        }
        else if (buttonText == "Tema 3: Estructuras"|| (buttonText == "Siguiente" && temita == "estructuras")) {
            temita = "estructuras";
            this->button6->Show(true);

            // Preguntas
            wxString Pregunta1 = "Que es unAAAAAAAAAAA entero?";
            wxString Pregunta2 = "Que es laAAAAAA vida";
            wxString Pregunta3 = "Que es unAAAAAA datatype";
            wxString Pregunta4 = "Quien es AAAAAAusted?";
            wxString Preguntas[] = { Pregunta1, Pregunta2, Pregunta3, Pregunta4 };

            // Respuestas en la opcion A
            wxString RespuestaA1 = "Es un numerAAAAAAo sin decimales";
            wxString RespuestaA2 = "Es un despiAAAAAAche";
            wxString RespuestaA3 = "Un tipo de AAAAAAdato jajaj XD";
            wxString RespuestaA4 = " A usted quAAAAAAe le importa";
            wxString Respuestas_A[] = { RespuestaA1, RespuestaA2, RespuestaA3, RespuestaA4 };

            // Respuestas en la opción B
            wxString RespuestaB1 = "Es un nAAAAAAumero CON decimales";
            wxString RespuestaB2 = "Yo que AAAAAAse";
            wxString RespuestaB3 = "Es una AAAAAAcarajada vacilona";
            wxString RespuestaB4 = " Don PeAAAAAAdro";
            wxString Respuestas_B[] = { RespuestaB1, RespuestaB2, RespuestaB3, RespuestaB4 };


            // Respuestas en la opción C
            wxString RespuestaC1 = "I donAAAAAAAAAt know dude";
            wxString RespuestaC2 = "El prAAAAAAAAAofe sabe";
            wxString RespuestaC3 = "PintoAAAAAAAAA";
            wxString RespuestaC4 = " Don AAAAAAAAALuis";
            wxString Respuestas_C[] = { RespuestaC1, RespuestaC2, RespuestaC3, RespuestaC4 };

            // Respuestas en la opción D
            wxString RespuestaD1 = "La C eAAAAAAAAAAAAAs la correcta";
            wxString RespuestaD2 = "El proAAAAAAAAAAAAAfe NO sabe";
            wxString RespuestaD3 = "Pinto AAAAAAAAAAAAAcon huevooo";
            wxString RespuestaD4 = "El preAAAAAAAAAAAAAsidente";
            wxString Respuestas_D[] = { RespuestaD1, RespuestaD2, RespuestaD3, RespuestaD4 };


            UpdateQuestion(Preguntas[e], Respuestas_A[e], Respuestas_B[e], Respuestas_C[e], Respuestas_D[e], 300, 50);


            e += 1;

            if (e == 4) {
                e = 0;
            }
           
        }
        // Puedes agregar más condiciones seg?n la lógica que desees
    }
}




// Se define el metodo que responde cuando el usuario selecciona alguna opcion: A, B, C o D
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
                UpdateExtraText("Respuesta correcta amigo :)", 350, 300);
            }
            else {
                UpdateExtraText("Respuesta incorrecta amigo :(", 350, 300);
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
                UpdateExtraText("Respuesta correcta :)", 350, 300);
            }
            else {
                UpdateExtraText("Respuesta incorrecta :(", 350, 300);
            }
    
        }
    }
}





