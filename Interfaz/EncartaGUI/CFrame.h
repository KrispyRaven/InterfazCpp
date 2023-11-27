#pragma once
/**
 * @file MainFrame.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Definicion de clase de ventana hija que hereda los metodos de wxFrame
*/
#include <wx/wx.h>

wxDECLARE_EVENT(wxEVT_CFRAME_CLOSED, wxCommandEvent);

/**
* @brief Se hereda desde wxFrame para crear la ventana Secundaria
*/
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
	void UpdateText(const wxString& newText);

	/**
	* @brief Metodo que actualiza la imagen que se muestra
	* @param newimage Recibe el nombre/ubicacion  de la imagen
	* @param pixX Recibe el tamaño en pixeles del eje x
	* @param pixY Recibe el tamaño en pixeles del eje x* @param pixX Recibe el tamaño en pixeles del eje y
	* @param posX Recibe la posicion en el eje x de la imagen 
	* @param posY Recibe la posicion en el eje Y de la imagen 
	*/
	void Updateimage(const wxString& newimage, int pixX, int pixY, int posX, int posY);

	/**
	* @brief Metodo que nos reconoce el boton que se ha clickeado y ejecuta un metodo asociado
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnButtonClick(wxCommandEvent& event);


	/**
	* @param m_textCtrl Es un control de texto estatico no copiable por el usuario
	*/
	wxStaticText* m_textCtrl;

	/**
	* @param image Objeto de la imagen que se muestra
	*/
	wxStaticBitmap* image;

	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button1;

	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button2;
	
	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button3;
	
	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button4;
	
	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button5;
	
	/**
	* @param burron1 Objeto del tipo Boton
	*/
	wxButton* button6;

	/**
	* @param panel Objeto del tipo wxPanel que referencia nuestro panel
	*/
	wxPanel* panel;
};

// Declaraci�n de la variable global 
extern int i;
