#include "EFrame.h"
#include <wx/wx.h>
#include <wx/mediactrl.h>
EFrame::EFrame(wxFrame* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
	: CFrame(parent, title, pos, size)
{

	button1->SetLabel("Manejo de memoria");
	button2->SetLabel("Estructuras");
	button3->SetLabel("Algoritmos");
	button4->SetLabel("STL");



	m_textCtrl->SetLabel(R"(Las estructuras de datos en C++ son formas de organizar y almacenar datos en la memoria de
manera eficiente para facilitar su manipulaci�n y acceso. )");


	button1->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick1, this);
	button2->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick1, this);
	button3->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick1, this);
	button4->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick1, this);
    button6->Bind(wxEVT_BUTTON, &EFrame::OnButtonClick1, this);
    Updateimage("Images/EstrucP.png", 671, 372, 150, 125);
    
}


void EFrame::OnButtonClick1(wxCommandEvent& event)
{
    // Textos principales de cada pesta�a

    // Manejo de memoria
    wxString Manejo_text = R"(El manejo de memoria en C++ es fundamental para gestionar c�mo se asigna y libera la memoria durante
 la ejecuci�n de un programa.

-Stack (Pila): Almacena variables locales y datos de funciones. La gesti�n es autom�tica, se
asigna y libera autom�ticamente cuando las variables entran y salen del �mbito.
-Heap (Mont�n): Espacio de memoria din�mica para alojar datos de tama�o desconocido en
tiempo de compilaci�n. La gesti�n requiere asignaci�n y liberaci�n manual.

Asignaci�n y Liberaci�n de Memoria:
new y delete: Operadores utilizados para asignar y liberar memoria en el mont�n.
malloc y free: Funciones de C, asignan y liberan memoria en el mont�n.

Errores Comunes de Memoria:
Fugas de memoria (Memory Leaks): Ocurren cuando la memoria asignada no se libera.
Referencias a memoria no v�lida: Se accede a un �rea de memoria liberada o no asignada.
Double Free: Intentar liberar una misma �rea de memoria dos veces.
)";

    //Estructuras de datos
    wxString Estructuras_text = R"(Arreglos (std::array, Arreglos Tradicionales):
std::array: Contenedor de tama�o fijo, similar a un arreglo tradicional con m�todos para 
acceder, modificar y obtener su tama�o.

Contenedores de Secuencia:
std::vector: Contenedor din�mico de tama�o variable, similar a un array, pero puede crecer y
decrecer en tama�o.
std::deque: Doble-ended queue, permite inserciones y eliminaciones eficientes en ambos extremos.
std::list: Lista doblemente enlazada que permite inserciones y eliminaciones eficientes en
cualquier punto, pero el acceso aleatorio es lento.

Contenedores Asociativos:
std::set: Contenedor que almacena elementos �nicos en orden ascendente.
std::map: Contenedor asociativo que almacena pares clave-valor, donde las claves son �nicas.


Contenedores Adaptativos:
std::stack: Estructura de datos tipo pila (LIFO).
std::queue: Estructura de datos tipo cola (FIFO).
std::priority_queue: Cola de prioridad que permite acceder al elemento con mayor prioridad.

PRESIONA SIGUIENTE PARA VER EJEMPLOS)";

    // Toma de decisiones

    wxString decisiones_text = R"(Un algoritmo es un conjunto de instrucciones bien definidas para resolver un problema particular.
Toma un conjunto de entradas y produce el resultado deseado.

Caracter�sticas de un buen algoritmo:
1. La entrada y la salida deben definirse con precisi�n.
2. Cada paso del algoritmo debe ser claro e inequ�voco.
3. Los algoritmos deber�an ser m�s eficaces entre muchas formas diferentes de resolver un problema.
4. Un algoritmo no deber�a incluir c�digo inform�tico. El algoritmo debe escribirse de tal manera
que pueda usarse en diferentes lenguajes de programaci�n. 

La complejidad de un algoritmo se refiere a la cantidad de recursos necesarios para ejecutar el
algoritmo, como el tiempo y la memoria. La complejidad se puede medir en t�rminos de la cantidad
de operaciones que el algoritmo realiza, como el n�mero de comparaciones, el n�mero de accesos a
memoria o el n�mero de ciclos de iteraci�n.

Para verificar la complejidad de un algoritmo, se puede realizar un an�lisis te�rico de la cantidad de
operaciones necesarias para realizar la tarea y compararla con la complejidad esperada. Si el an�lisis
te�rico muestra que la complejidad del algoritmo es mayor que la esperada, es necesario revisar el
dise�o del algoritmo para encontrar formas de reducir la complejidad. En cuanto a la eficiencia, se
puede medir mediante la ejecuci�n del algoritmo con diferentes tama�os de entrada y medir el tiempo de
ejecuci�n y la utilizaci�n de recursos, como la memoria. Si el algoritmo utiliza m�s recursos de lo
esperado o tarda m�s tiempo en ejecutarse, es necesario revisar el dise�o del algoritmo para encontrar
formas de optimizarlo y mejorar su eficiencia

)";

    // Loops

    wxString Loops_text = R"(La STL (Standard Template Library) de C++ es una colecci�n de plantillas y algoritmos predefinidos que
proporciona una variedad de estructuras de datos y funciones para operar en esos datos.
Est� compuesta por varios componentes principales:

-Contenedores:
Secuenciales: std::vector, std::list, std::deque, std::array.
Asociativos: std::set, std::map, std::multiset, std::multimap.
Adaptativos: std::stack, std::queue, std::priority_queue.

-Iteradores:
Iteradores: Permiten recorrer secuencias de elementos en los contenedores STL.

-Algoritmos:
Algoritmos: Funciones predefinidas para realizar operaciones en contenedores, como b�squeda,
ordenaci�n, manipulaci�n, modificaci�n, partici�n, comparaci�n, entre otros.

-Funciones y Objetos de Funci�n:
Funciones Lambda: Permiten definir funciones an�nimas in situ.
Objetos de Funci�n (Functors): Clases que act�an como funciones cuando implementan el operador
operator().

-Iteradores Especiales:
Iteradores de Flujo: Para leer y escribir secuencialmente a trav�s de flujos de datos.
Iteradores de Retroceso: Permiten iterar en direcciones inversas.

-Smart Pointers:
std::shared_ptr: Puntero inteligente compartido.
std::unique_ptr: Puntero inteligente �nico.
std::weak_ptr: Puntero inteligente d�bil.)";

    wxString algortE = R"(La eficiencia de un algoritmo se refiere a la capacidad del algoritmo para utilizar de manera efectiva
los recursos disponibles. Un algoritmo eficiente es aquel que realiza una tarea en la menor
cantidad de tiempo y utilizando la menor cantidad de memoria posible. La eficiencia se mide
con la ayuda de notaciones asint�ticas. Es posible que un algoritmo no tenga el mismo rendimiento
para diferentes tipos de entradas. Con el aumento del tama�o de entrada, el rendimiento cambiar�.
Las notaciones asint�ticas son notaciones matem�ticas utilizadas para describir el tiempo de
ejecuci�n de un algoritmo cuando la entrada tiende hacia un valor particular o un valor l�mite.

Se definen tres notaciones asint�ticas como:

1. La notaci�n Big-O representa el l�mite superior del tiempo de ejecuci�n de un algoritmo.
Por tanto, proporciona la complejidad del peor de los casos de un algoritmo.

2. La notaci�n omega representa el l�mite inferior del tiempo de ejecuci�n de un algoritmo.
Por lo tanto, proporciona el mejor caso de complejidad de un algoritmo.

3. La notaci�n theta encierra la funci�n desde arriba y desde abajo. Dado que representa el
l�mite superior e inferior del tiempo de ejecuci�n de un algoritmo, se utiliza para analizar
la complejidad promedio de un algoritmo.)";

    // Ejemplo en Toma de decisiones

    wxString decisiones_example = R"( En la figura se muestra ejemplos de estructuras
)";

    // Ejemplo en Loops

    wxString Loops_example = R"( En la figura se muestra un codigo STL
)";

    // Ejemplo de Estructuras

    wxString Estructuras_example = R"( En la figura se muestra ejemplos de estructuras
)";

    wxString textoExtra = R"( Contenedores
)";
    wxString algoritmos = R"( Algoritmos de b�squeda:
- find: Busca un elemento en un rango.
- binary_search: Realiza una b�squeda binaria en un rango ordenado.
- count: Cuenta el n�mero de ocurrencias de un elemento en un rango.
- find_if: Busca el primer elemento que cumple con cierto criterio.

Algoritmos de ordenamiento:
- sort: Ordena un rango en orden ascendente.
- partial_sort: Ordena los primeros elementos en un rango.
- nth_element: Coloca el elemento n-�simo en su posici�n correcta en un rango

Algoritmos de manipulaci�n de rangos:
- copy: Copia elementos de un rango a otro.
- move: Mueve elementos de un rango a otro.
- fill: Asigna un valor dado a todos los elementos en un rango.

Algoritmos de eliminaci�n y modificaci�n:
- remove: Elimina elementos espec�ficos de un rango.
- replace: Reemplaza elementos espec�ficos en un rango.
- reverse: Invierte el orden de los elementos en un rango.

Algoritmos num�ricos:
- accumulate: Realiza una operaci�n de acumulaci�n en un rango.
- inner_product: Calcula el producto escalar de dos rangos.
- partial_sum: Calcula la suma acumulativa de un rango.
- iota: Llena un rango con valores incrementales.

)";

    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    this->button6->Show(false);


    if (button)
    {
        wxString buttonText = button->GetLabel();
        // Aqu� puedes personalizar el texto seg�n el boton presionado
        if (buttonText == "Manejo de memoria") {
            m_textCtrl->Show();
            image->Show();
            UpdateText(Manejo_text);

            Updateimage("Images/memoria.png", 515, 115, 140, 350);
        }

        else if (buttonText == "Estructuras") {
            m_textCtrl->Show();
            image->Show();
            UpdateText(Estructuras_text);

            i = 0;

            Updateimage("Images/Fondo.png", 50, 36, 140, 450);
            button6->SetLabel("Siguiente");
            button6->Show(true);


        }
        else if (buttonText == "Algoritmos") {
            m_textCtrl->Show();
            image->Hide();
            i = 1;
            Updateimage("Images/Fondo.png", 50, 36, 140, 450);
            UpdateText(decisiones_text);
            button6->SetLabel("Continuar");
            button6->Show(true);




        }
        else if (buttonText == "STL") {
            m_textCtrl->Show();
            image->Hide();
            i = 2;
            UpdateText(Loops_text);
            button6->SetLabel("Ver ejemplo");
            button6->Show(true);


        }
        else if (buttonText == "Siguiente") {

            this->button6->Show(true);

            m_textCtrl->Hide();
            image->Show();
            if (i == 6) {
                i = 0;
            }

            wxString lista[] = { "Images/Estructuras1.png", "Images/Estructuras2.png", "Images/Estructuras3.png","Images/Estructuras4.png","Images/Estructuras5.png" };

            int pixelX[] = { 538,314,363,442,373};
            int pixelY[] = { 423,432,446,375,385};
            if (i == 5) {
                Updateimage("Images/Fondo.png", 50, 36, 140, 450);
                m_textCtrl->Show();

            }
            else{
            Updateimage(lista[i], pixelX[i], pixelY[i], 155, 50);
            }

            i += 1;
        }
        else if (buttonText == "Continuar") {

            this->button6->Show(true);

            m_textCtrl->Hide();
            image->Show();
            if (i == 3) {
                i = 0;
            }

            if (i == 0) {

                Updateimage("Images/Fondo.png", 50, 36, 140, 450);
                m_textCtrl->Show();
                UpdateText(decisiones_text);

                
            }
            else if (i == 1) {
                m_textCtrl->Show();
                UpdateText(algortE);

                          
            }
            else if (i == 2) {
                image->Show();
                Updateimage("Images/sort.png", 384, 459, 140, 50);

            }

            i += 1;
        }
        else if (buttonText == "Ver ejemplo" || buttonText == "Mostrar info again" || buttonText == "Ver otro ejemplo") {

            if (i == 0) {
                button6->SetLabel("Mostrar info again");
                button6->Show();
                image->Hide();
                UpdateText(algoritmos);

            }
            if (i == 1){
                button6->SetLabel("Ver ejemplo");
                button6->Show();
                image->Hide();
                UpdateText(Loops_text);

            }
            if (i == 2) {
                button6->SetLabel("Ver otro ejemplo");
                button6->Show();
                UpdateText(textoExtra);
                Updateimage("Images/secuenciales.png", 396, 241, 140, 50);
                image->Show();
                

            }
            if (i == 3) {
                button6->SetLabel("Ver otro ejemplo");
                button6->Show();
                Updateimage("Images/asociativos.png", 493, 244, 140, 50);

            }

            if (i == 4) {
                button6->SetLabel("Ver otro ejemplo");
                button6->Show();
                wxString it = "Iteradores";
                UpdateText(it);
                Updateimage("Images/Iteradores.png", 574, 226, 140, 50);

            }

            if (i == 5) {
                button6->SetLabel("Ver otro ejemplo");
                button6->Show();
                wxString it = "Smart Pointers";
                UpdateText(it);
                Updateimage("Images/spointer.png", 440, 366, 140, 50);

                i = -1;

            }


            

            i += 1;

        }
    }
}

