# Propuesta del proyecto
## Descripción general de la aplicación educativa
Se propone crear una interfaz gráfica que permita al usuario aprender sobre estructuras de datos y algoritmos de ordenamiento. En primer lugar, se planea crear un menú principal el cual debe contener como mínimo tres botones: Estructuras de datos, algoritmos de ordenamiento y salir. AL ingresar al primer botón (Estructuras de datos), se debe abrir una pantalla nueva, la cual debe contener los siguientes botones: arreglos, listas enlazadas, cola, pila, árbol binario de búsqueda, diccionario, cola de prioridad, grafo y regresar al menu principal. AL estripar cada uno de estos botones, se debe desplegar una ventana informativa asociada al tema correspodiente. Dicha ventana debe contener como mínimo: información relevante sobre la estructura de datos y un ejemplo (imagen) que demuestre su aplicabilidad. Por otra parte, al ingresar en el segundo botón (algoritmos de ordenamiento), se debe desplegar una pantalla nueva, la cual debe contener los siguientes botones: burbuja, inserción, selección, fusión,
rápido, análisis de su complejidad y eficiencia, y regresar al menu principal. Al estripar cada uno de estos botones, se debe desplegar una ventana informativa asociada al tema correspodiente, la cual debe contener al menos una imagen que clarifique la explicación de cada tema. Por último, se tiene el boton salir, el cual termina la ejecución del programa. Cabe destacar que, de manera opcional, en el menú principal se podría añadir un cuarto botón denominado: recursos online, el cual contenga distintos enlaces con información relevante referente a los dos temas centrales (estructuras de datos y algoritmos de ordenamiento).

## Librerías
### Win32 API
La API de Windows (WinAPI) es un conjunto de funciones que permiten a los desarrolladores crear aplicaciones para el sistema operativo Windows. La API de Windows se compone de varios módulos y bibliotecas que abarcan una amplia gama de funciones de bajo y alto nivel. Aunque tiene muchas ventajas, tales como:

* Tener acceso completo a funcionalidades de Windows: WinAPI ofrece acceso completo a las funcionalidades de bajo nivel del sistema operativo Windows, lo que permite un control detallado sobre el funcionamiento de la aplicación y la interacción con el sistema operativo.

* Alto rendimiento: Al ser una API de bajo nivel, WinAPI está optimizada para ofrecer un rendimiento rápido y eficiente. Esto es especialmente útil en aplicaciones que requieren un uso intensivo de recursos o que necesitan un alto grado de control sobre el hardware y los recursos del sistema.

* Soporte de largo plazo: Dado que la WinAPI es parte integral del sistema operativo Windows, Microsoft generalmente proporciona un soporte de largo plazo para las aplicaciones desarrolladas utilizando esta API. Esto garantiza la estabilidad y la compatibilidad de las aplicaciones incluso en versiones posteriores de Windows.

Cabe destacar que es una herramienta ampliamente utilizada en el desarrollo de aplicaciones para Windows, pero también presenta algunas desventajas, que incluyen:

* Complejidad: La WinAPI puede resultar complicada de utilizar, especialmente para aquellos que no están familiarizados con los conceptos de programación de bajo nivel y la arquitectura de Windows.

* Falta de portabilidad: La WinAPI está específicamente diseñada para aplicaciones que se ejecutan en el sistema operativo Windows, lo que limita su portabilidad a otros sistemas operativos. Esto puede ser una desventaja si se necesita llevar las aplicaciones a distintas plataformas.  

* Riesgo de errores de bajo nivel: Al trabajar directamente con la API de Windows, existe un mayor riesgo de cometer errores de bajo nivel que podrían afectar el rendimiento, la estabilidad y la seguridad de la aplicación. 

### QT
Qt es un conjunto de herramientas de desarrollo de software de código abierto ampliamente utilizado para crear aplicaciones de software con interfaces gráficas de usuario (GUI). Tiene ventajas tales como:

* Portabilidad multiplataforma: Qt permite el desarrollo de aplicaciones que pueden ejecutarse en diversas plataformas, como Windows, macOS, Linux, Android e iOS, con un código fuente común. Esto simplifica en gran medida el proceso de desarrollo y facilita la creación de aplicaciones que pueden llegar a una amplia audiencia de usuarios en diferentes sistemas operativos.

* Comunidad activa y soporte profesional: Qt cuenta con una comunidad activa de desarrolladores y usuarios que pueden proporcionar soporte y orientación. Además, The Qt Company, la entidad responsable de Qt, ofrece soporte profesional y servicios de consultoría para empresas que necesitan asistencia adicional en el desarrollo de sus aplicaciones.

* Flexibilidad y extensibilidad: Qt es altamente flexible y extensible, lo que permite a los desarrolladores ampliar su funcionalidad según sea necesario. Esto facilita la adaptación de la biblioteca a una variedad de casos de uso y requisitos específicos del proyecto. Ademas con su herramienta de diseño grafico hace más sencilla la labor de diseño de aplicaciones.

A pesar de ser una de las bibliotecas de interfaz gráfica de usuario (GUI) más populares y poderosas, la biblioteca QT también presenta algunas limitaciones y desventajas. Algunas de estas desventajas son:

* Espacio en la memoria y tamaño del paquete: La biblioteca QT puede aumentar el tamaño de los archivos ejecutables y las bibliotecas dinámicas debido a sus amplias funcionalidades y su naturaleza orientada a objetos. Esto puede ser un inconveniente en situaciones en las que el tamaño de la aplicación es una consideración crítica, como en el desarrollo de aplicaciones para dispositivos con recursos limitados.

* Dependencias no incluidas: Al utilizar QT, las aplicaciones pueden tener dependencias adicionales que deben distribuirse junto con la aplicación. Esto puede generar problemas de compatibilidad o instalación en sistemas donde estas dependencias no están disponibles o son difíciles de administrar.

* Licencias: Si bien QT es de código abierto y tiene una versión de la comunidad, algunas características y herramientas avanzadas pueden requerir una licencia comercial, lo que puede resultar costoso para proyectos empresariales o de mayor escala.

* Desempeño: En comparación con bibliotecas de interfaz de usuario más livianas, QT puede consumir más recursos del sistema y tener un rendimiento ligeramente inferior en sistemas con capacidades limitadas o en aplicaciones que requieren un rendimiento extremadamente alto.

### wxWidgets
wxWidgets es un framework de código abierto en C++ que te permite escribir aplicaciones de interfaz gráfica (GUI) que funcionan en varias plataformas y se ven y se sienten nativas, tanto en C++ como en otros lenguajes de programación. A continuación se enlistan algunas de las ventajas que se encontraron luego de investigar la librería wxWidgets:

* Portabilidad multiplataforma: Basta con escribir el código de la GUI una sola vez, ya que es posible ejecutarlo en diferentes sistemas operativos, como Windows, Unix y macOS. Además, el aspecto de la interfaz se adapta al aspecto nativo del sistema operativo. 

* Comunidad activa y soporte profesional: Hay bastante documentación, foros y recursos en YouTube. Actualmente, la pagina oficial cuenta con mas de 100 ejemplos de programas.

* Codigo simple: En comparación a otros programas para crear GUI (como Win32 API), el código que se requiere para crear una GUI basica, requiere de menos lineas de código en wxWidgets. Asimismo, el código puede llegar a ser sencillo de entender, lo cual es fundamental para disminuir el impacto de la curva de aprendizaje.

* Costo: Es un software de código abierto completamente gratuito, sin ningun tipo de restricción. Esto es una gran ventaja sobre Qt, ya que este sí tiene algunas licencias de pago.

Por otro lado, wxWidgets cuenta con ciertas desventajas, las cuales se muestran a continuacion:

* Visual designer: A diferencia de QT, wxwidgets no cuenta con una herramienta visual que ayude a diseñar la GUI.

* Aplicaciones simples: Con wxWidgets se pueden crear interfaces para aplicaciones simples. Cuando la aplicación tiene un grado de complejidad alto, es recomendable usar Qt, debido a los features que este puede llegar a brindar dependiendo de la licencia que se pague. 


### Elección final
En base a la información proporcionada anteriormente, las mejores librerías son QT y wxWidgets. Ahora bien, a pesar de que Qt cuenta con una herramienta visual para crear la GUI, se elige wxWidgets, debido a que es completamente gratuito. Asimismo, dado que wxWidgets no cuenta con una herramienta visual para crear la GUI, se tiene certeza de que todo el codigo creado en wxWidgets es el encargado de generar toda la GUI. Esto garantizará una mejor comprensión del funcionamiento de la GUI creada, lo cual será fundamental para debuggear apropiadamente. De igual forma, la aplicación para la cual se va a crear la GUI no es compleja, por lo que se tiene certeza que wxWidgets proporcionara las herramientas necesarias para crear una interfaz apropiada. Por último, se encontraron mejores recursos en internet para aprender con wxWidgets en comparación a los encontrados para Qt.

## Plan de trabajo
A nivel general, el plan de trabajo se puede dividir en las fases que se muestran en el siguiente diagrama de bloques: 

![Diagrama de bloques parte 1](diagramadebloques.jpeg)



A nivel más específico, se pueden llevar a cabo los siguientes pasos para ir cumpliendo las diferentes fases que se muestran en el diagrama de bloques anterior:

1. Investigar las diferentes clases y funciones que posee la librería wxWidgets.

2. Buscar códigos base como ejemplo para tener un mejor entendimiento.

3. Crear una GUI sencilla y entender bien su funcionamiento.

4. Investigar cómo crear una segunda interfaz a partir de una primera GUI, usando botones.

5. Crear una interfaz primaria y secundaria, de modo que estando en la primaria se pueda abrir la interfaz secundaria y viceversa.

6. Recolectar toda la información e imágenes que se van a incluir en el proyecto, referente a estructuras de datos y algoritmos de ordenamiento.

7. Crear todas las pantallas necesarias y conectarlas entre sí para crear el proyecto propuesto.

## Caracteristicas principales de la aplicacion

1. Menu central para ir a las diferentes secciones

2. Diferente pantalla con informacion de cada una de las secciones

3. Codigo real de ejemplos de las diferentes secciones

4. Ilustraciones para ejemplificar de manera visual ciertos procedimientos/definiciones

5. Mini cuestionario al final de cada seccion

## Bibliografía

- wxWidgets Cross-Platform GUI Library. (s/f). Wxwidgets.org. Recuperado el 22 de octubre de 2023, de https://www.wxwidgets.org/

- Sciber [@wearesciber]. (2021, noviembre 6). BEST GUI TOOLKITS for C++ | Sciber. Youtube. https://www.youtube.com/watch?v=UpREGWu7Oig

- OttoBotCode [@OttoBotCode]. (2022, febrero 9). C++ GUI programming for beginners | episode 0 - introduction. Youtube. https://www.youtube.com/watch?v=BjQhp0eHmJw

- Codigazo [@Codigazo]. (2021, marzo 1). Cómo hacer una interfaz gráfica en C++. Youtube. https://youtu.be/8p9CQPmwxvo

- Codigazo [@Codigazo]. (2021, marzo 31). ¿Que es Winapi y para que sirve?. Youtube. https://youtu.be/zOmsCzkxQlg

- Qt GUI wiki (s/f). https://wiki.qt.io/Main Recuperado el 22 de octubre de 2023, de https://wiki.qt.io/Main