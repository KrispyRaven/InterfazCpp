#include "MainFrame.h"
#include <wx/wx.h>
#include "CFrame.h"
#include "OOP.h"
#include "EFrame.h"


/* Se define el conmstructor de la ventana */
MainFrame::MainFrame(const wxString& tittle): wxFrame(nullptr, wxID_ANY, tittle) {

	/* Se debe crear un entry point en el cual se visualizara la ventana
	Usualmente en c++ es la funcion int main.
	*/
	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "C/C++", wxPoint(20, 50), wxSize(100, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "OOP", wxPoint(20, 55+50+150), wxSize(100, 50));
	wxButton* button3 = new wxButton(panel, wxID_ANY, "Estructuras", wxPoint(20, 55 + 50 + 55+150+150), wxSize(100, 50));
	wxButton* button4 = new wxButton(panel, wxID_ANY, "Salir", wxPoint(670, 530), wxSize(100, 50));

	// Bind es un metodo que proviene de la clase: evt handler. Cualquier clase boton hereda de esta clase dicho metodo.

	button1 -> Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame1, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame2, this);
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame3, this);
	button4->Bind(wxEVT_BUTTON, &MainFrame::OnExitButtonClick, this);
}

// Implementamos el metodo: event handler
void MainFrame::OnOpenNewFrame1(wxCommandEvent& event)
{
	CFrame* nCFrame = new CFrame(this, "C++", wxPoint(0, 0), wxSize(800, 600));
	nCFrame->Show(true);
}

void MainFrame::OnOpenNewFrame2(wxCommandEvent& event)
{
	OOP* nOOP = new OOP(this, "OOP", wxPoint(0, 0), wxSize(800, 600));
	nOOP->Show(true);
}

void MainFrame::OnOpenNewFrame3(wxCommandEvent& event)
{
	EFrame* nEFrame = new EFrame(this, "Estructuras dinámicas de datos y criterios de algoritmos", wxPoint(0, 0), wxSize(800, 600));
	nEFrame->Show(true);
}

void MainFrame::OnExitButtonClick(wxCommandEvent& event)
{
	// Cierra la aplicación
	Close(true);
}

// There are two principal ways to handle events in wxWidgets. 
// 
// One of them uses event table macros and allows you to define the binding between 
// events and their handlers only statically, i.e., during program compilation. 
// The other one uses wxEvtHandler::Bind<>() call and can be used to bind and unbind, 
// the handlers dynamically, i.e. during run-time depending on some conditions