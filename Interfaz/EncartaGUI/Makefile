# Nombre del ejecutable
TARGET = mi_aplicacion.exe

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Ruta a wxWidgets
WX_DIR = C:/Libraries/wxWidgets-3.2.3

# Incluir directorios y bibliotecas de wxWidgets
WX_CXXFLAGS := -I$(WX_DIR)/include
WX_LIBS := -L$(WX_DIR)/lib/gcc_lib -lwxmsw32

# Archivos fuente
SOURCES = App.cpp MainFram.cpp OOP.cpp CFrame.cpp EFrame.cpp

# Archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:.cpp=.o)

# Regla para el target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(WX_CXXFLAGS) -o $(TARGET) $(OBJECTS) $(WX_LIBS)

# Regla para los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(WX_CXXFLAGS) -c -o $@ $<

# Regla para limpiar archivos generados
clean:
	del *.o $(TARGET)

