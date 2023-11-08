#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {

	MainFrame* mainFrame = new MainFrame("Encarta IE-0217");

	// Ajusta el tamaño de la Ventan
	mainFrame->SetClientSize(800,600);

	// Centra la ventana
	mainFrame->Center();

	//La ventana al inicio esta oculta, se llama el metodo show para mostrarla
	mainFrame->Show();

	// Se devuelve un True para que aplicacion continue. Si sw devuelve False cierra
	return true;

}