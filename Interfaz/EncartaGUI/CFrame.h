#pragma once
/**
 * @file MainFrame.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Definicion de clase de ventana hija que hereda los metodos de wxFrame
*/
#include <wx/wx.h>




class CFrame : public wxFrame
{
public:
	/**
	* @brief Metodo Constructor de la clase CFrame
	* @param parent Puntero que se debe recibir para indicar la ventana padre
	* @param tittle �tittle� se encarga de generarnos el titulo de nuestra ventana
	* @param pos "pos" nos define la posicion de nuestra ventana
	* @param size "size" nos define el tama�o de nuestra ventana
	*/
	CFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);

	/**
	* @brief Metodo que se encarga de cerrar solo la ventan hija en la cual el se encuentra
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void CloseClicked(wxCommandEvent& evt);

	/**
	* @brief Metodo que recibe un nuevo texto para ser modificado
	* @param newText Recibe un nuevo texto para actualizar el actual
	*/

	void Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY);
	void UpdateText(const wxString& newText);

	/**
	* @brief Metodo que nos reconoce el boton que se ha clickeado
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnButtonClick(wxCommandEvent& event);
	void SpecialClick(wxCommandEvent& event);

private:
	/**
	* @param m_textCtrl "m_textCtrl" Es un control de texto estatico no copiable por el usuario
	*/
	wxStaticText* m_textCtrl;
	wxStaticBitmap* image;
	wxButton* button1;
	wxButton* button2;
	wxButton* button3;
	wxButton* button4;
	wxButton* button5; 
	wxButton* button6;
};

// Declaraci�n de la variable global 
extern int i;
