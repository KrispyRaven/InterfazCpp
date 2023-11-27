#pragma once
/**
 * @file MainFrame.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Definicion de clase de ventana hija que hereda los metodos molde CFrame
*/
#include <wx/wx.h>
#include "CFrame.h"
#include <wx/mediactrl.h>

/**
* @brief Se hereda desde EFrame para crear la ventana Secundaria
*/
class EFrame : public CFrame
{
public:
	/**
	* @brief Metodo Constructor de la clase EFrame
	* @param parent Puntero que se debe recibir para indicar la ventana padre
	* @param tittle �tittle� se encarga de generarnos el titulo de nuestra ventana
	* @param pos "pos" nos define la posicion de nuestra ventana
	* @param size "size" nos define el tama�o de nuestra ventana
	*/
	EFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
	
	/**
	* @brief Metodo que nos reconoce el boton que se ha clickeado y ejecuta un metodo asociado
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnButtonClick1(wxCommandEvent& event);



};