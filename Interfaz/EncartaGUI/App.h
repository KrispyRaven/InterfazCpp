#pragma once
#include <wx/wx.h>
/**
 * @file App.hpp
 * @author Noel Blandon y Carlos Cordero
 * @date 22/11/2023
 * @brief Funcion  de partida de un programa en C++ donde se inicia la ejecuci�n y desde donde se pueden controlar los flujos de ejecuci�n y los argumentos que se pasan al programa al iniciarse.
*/

/**
* @brief Se hereda desde wxApp el iniciador del programa 
*/
class App : public wxApp
{
public:

    /**
     * @brief Metodo de inicio del programa 
    */
	bool OnInit();

};

