#pragma once
/**
 * @file MainFrame.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Definicion de clase de ventana hija que hereda los metodos de wxFrame
*/

#include <wx/wx.h>
#include "MainFrame.h"
#include <iostream>
#include <string>

using namespace std;

wxDECLARE_EVENT(wxEVT_QFRAME_CLOSED, wxCommandEvent);

/**
* @brief Clase creadora de la ventana de quiz, hereda de wxFrame
*/
class QFrame : public wxFrame
{
public:

	/**
	* @brief Metodo constructor de la clase QFrame
	* @param parent puntero obligatorio de la ventana padre
	* @param tittle Titulo de la ventana
	* @param pos cordenadas de tipo wxPoint
	* @param size Tamaño de la ventana de tipo wxSize
	*/
	QFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size);

	/**
	* @brief Metodo que se encarga de cerrar solo la ventan hija en la cual el se encuentra
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void CloseClicked(wxCommandEvent& evt);

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
	* @brief Metodo que se encarga de actualizar las preguntas y respuestas del quiz
	* @param Question Recibe la pregunta a actualizar
	* @param OpcionA Recibe la posible respuesta A
	* @param OpcionB Recibe la posible respuesta B
	* @param OpcionC Recibe la posible respuesta C
	* @param OpcionD Recibe la posible respuesta D
	* @param posX Recibe la posicion en el eje x de la pregunta
	* @param posY Recibe la posicion en el eje Y de la pregunta
	*/
	void UpdateQuestion(const wxString& Question, const wxString& OpcionA, const wxString& OpcionB, const wxString& OpcionC, const wxString& OpcionD, int posX, int posY);
	
	/**
	* @brief Metodo que se encarga de indicar en pantalla si la respuesta es correcta o incorrecta
	* @param text Texto quue indica si la respuesta es correcta o incorrecta
	* @param posX Posicion en el eje x del texto
	* @param posY Posicion en el eje y del texto
	*/
	void UpdateExtraText(const wxString& text, int posX, int posY);

	/**
	* @brief Metodo que nos reconoce el boton que se ha clickeado y ejecuta un metodo asociado
	* @param event recibe un objeto wxCommandEvent& como argumento.
	* Este objeto wxCommandEvent contiene informaci�n sobre el evento que se ha producido, como su tipo, el ID del evento y cualquier dato adicional asociado.
	*/
	void OnButtonClick(wxCommandEvent& event);

	/**
	* @brief Metodo que responde cuando el usuario selecciona alguna opcion: A, B, C o D e indica si la respuesta es correcta o incorrecta.
	* Esto empleando el metodo "updateExtraText".
	* @param event Recibe el evento de la checkbox
	*/
	void ABCDClick(wxCommandEvent& event);
	

public:
	/**
	* @param m_textCtrl Es un control de texto estatico no copiable por el usuario
	*/
	wxStaticText* m_textCtrl;

	/**
	* @param extra_text Es un control de texto estatico no copiable por el usuario empleado en el metodo UpdateExtraText
	*/
	wxStaticText* extra_text;

	/**
	* @param image Objeto de la imagen que se muestra
	*/
	wxStaticBitmap* image;

	/**
	* @param button1 Objeto del tipo Boton
	*/
	wxButton* button1;

	/**
	* @param button2 Objeto del tipo Boton
	*/
	wxButton* button2;

	/**
	* @param button3 Objeto del tipo Boton
	*/
	wxButton* button3;

	/**
	* @param button5 Objeto del tipo Boton
	*/
	wxButton* button5;

	/**
	* @param button6 Objeto del tipo Boton
	*/
	wxButton* button6;

	/**
	* @param buttonA Objeto del tipo checkbox
	*/
	wxCheckBox* buttonA;

	/**
	* @param buttonB Objeto del tipo checkbox
	*/
	wxCheckBox* buttonB;

	/**
	* @param buttonC Objeto del tipo checkbox
	*/
	wxCheckBox* buttonC;

	/**
	* @param buttonD Objeto del tipo checkbox
	*/
	wxCheckBox* buttonD;

	/**
	* @param pastButton Objeto del tipo checkbox que almacena el boton presionado anteriormente
	*/
	wxCheckBox* pastButton;

};

/**
* @param e Declaración de la variable global para iterar
*/ 
extern int e;

/**
* @param temita Variable de control para conocer en que tema se esta y que preguntas se deben mostrar, junto on sus posibles respuestas
*/
extern string temita;

