#include "MainFrame.h"
#include <wx/wx.h>
#include "CFrame.h"
#include "OOP.h"
#include "EFrame.h"
#include "QFrame.h"


/* Se define el constructor de la ventana */
MainFrame::MainFrame(const wxString& tittle): wxFrame(nullptr, wxID_ANY, tittle) {

	

	// Se crean distintos objetos (botones) provenientes de la clase wxButton
	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "C/C++", wxPoint(20, 50), wxSize(100, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "OOP", wxPoint(20, 55+50+150), wxSize(100, 50));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "Estructuras", wxPoint(20, 55 + 50 + 55+150+150), wxSize(100, 50));
	wxButton* button5 = new wxButton(panel, wxID_ANY, "Quiz", wxPoint(670, 30), wxSize(100, 50));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "Salir", wxPoint(670, 530), wxSize(100, 50));


	// Este es el link entre el evento y el metodo a ser llamado
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame1, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame2, this);
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame3, this);
	button4->Bind(wxEVT_BUTTON, &MainFrame::OnExitButtonClick, this);
	button5->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame4, this);

	// Estos Bind linkean el evento personalizado generado en cada ventana auxiliar con un metodo de esta clase
	Bind(wxEVT_QFRAME_CLOSED, &MainFrame::OnQFrameClosed, this);
	Bind(wxEVT_CFRAME_CLOSED, &MainFrame::OnCFrameClosed, this);


	// Inicializamos atributos
	// Este objeto representa el texto principal mostrado en la ventana actual (objeto)
	this->main_text = new wxStaticText(panel, wxID_ANY, R"(¿Qué desea aprender o recordar?)", wxPoint(200, 100), wxSize(250, 100), wxALIGN_LEFT);


	// Creamos un objeto para definir el tamaño de letra, la familia de estilos, tipo de letra, grosor de la letra
	wxFont font(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRAHEAVY);

	// Establecer la fuente en el objeto wxStaticText aplicando el metodo SetFont
	this->main_text->SetFont(font);

	
	// Establecer color gris RGB: (128, 128, 128) en el objeto panel
	panel->SetBackgroundColour(wxColour(128, 128, 128)); 


	// Creamos un nuevo objeto (image)
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	this->image = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("Images/mainframe.png", wxBITMAP_TYPE_PNG), wxPoint(250, 200), wxSize(333, 300));

}

// Implementamos los metodos: event handler

void MainFrame::OnOpenNewFrame1(wxCommandEvent& event)
{
	CFrame* nCFrame = new CFrame(this, "C++", wxPoint(200, 200), wxSize(900, 680));
	nCFrame->Show(true);

	this->Show(false);
}

void MainFrame::OnOpenNewFrame2(wxCommandEvent& event)
{
	OOP* nOOP = new OOP(this, "OOP", wxPoint(200, 200), wxSize(900, 680));
	nOOP->Show(true);
	this->Show(false); 
}

void MainFrame::OnOpenNewFrame3(wxCommandEvent& event)
{
	EFrame* nEFrame = new EFrame(this, "Estructuras dinámicas de datos y criterios de algoritmos", wxPoint(200, 200), wxSize(900, 680));
	nEFrame->Show(true);

	this->Show(false);
}


void MainFrame::OnOpenNewFrame4(wxCommandEvent& event)
{
	QFrame* nQFrame = new QFrame(this, "Evaluación de conceptos", wxPoint(200, 200), wxSize(900, 600));
	nQFrame->Show(true);

	this->Show(false);
}



void MainFrame::OnExitButtonClick(wxCommandEvent& event)
{
	// Cierra la aplicación
	Close(true);
}

// Metodos llamados cuando ocurre el evento personalizado
void MainFrame::OnQFrameClosed(wxCommandEvent& event) {
	Show(true);
}

void MainFrame::OnCFrameClosed(wxCommandEvent& event) {
	Show(true);
}
