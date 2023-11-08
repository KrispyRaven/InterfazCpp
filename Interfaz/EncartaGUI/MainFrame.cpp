#include "MainFrame.h"
#include <wx/wx.h>
#include "CFrame.h"


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

	button1 -> Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewFrame, this);
}

void MainFrame::OnOpenNewFrame(wxCommandEvent& event)
{
	CFrame* nCFrame = new CFrame(this, "Nuevo Marco", wxPoint(0, 0), wxSize(800, 600));
	nCFrame->Show(true);
}