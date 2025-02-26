#pragma once
/**
 * @file MainFrame.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Definicion de clase de ventana principal que hereda los metodos de wxFrame
*/

#include <wx/wx.h>
/**
* @brief Se hereda desde wxFrame para crear la ventana principal
*/
class MainFrame : public wxFrame
{
public:

	/**
	* @brief Llamada del metodo constructor de la ventana
	* @param tittle ¨tittle¨ se encarga de generarnos el titulo de nuestra ventana
	*/
	MainFrame(const wxString& tittle);
	
	
	// Un event Handler es un metodo que se llama en respuesta a un evento

	/**
	* @brief Metodo encargado de crear una nueva ventana llamando al archivo CFrame
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene información sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnOpenNewFrame1(wxCommandEvent& event);

	/**
	* @brief Metodo encargado de crear una nueva ventana llamando al archivo OOP
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene información sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnOpenNewFrame2(wxCommandEvent& event);

	/**
	* @brief Metodo encargado de crear una nueva ventana llamando al archivo EFrame
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene información sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnOpenNewFrame3(wxCommandEvent& event);

	/**
	* @brief Metodo encargado de cerrar la ventana principal y todas sus dependencias
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene información sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnExitButtonClick(wxCommandEvent& event);
	
	/**
	* @brief Metodo encargado de crear una nueva ventana llamando al archivo QFrame
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene información sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnOpenNewFrame4(wxCommandEvent& event);
	
	/**
	* @brief Metodo encargado de llamar al manejador de eventos y que este llame a la ventan
	*/ 
	void OnQFrameClosed(wxCommandEvent& event);

	/**
	* @brief Metodo encargado de llamar al manejador de eventos y que este llame a la ventan
	*/
	void OnCFrameClosed(wxCommandEvent& event);


	
public:
	/**
	* @param main_text Parametro que inicia el texto de pantalla
	*/
	wxStaticText* main_text;
	/**
	* @param image Objeto de la imagen que se muestra
	*/
	wxStaticBitmap* image;
	
};

