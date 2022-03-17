SRC = src
INC = include
OBJ = obj
BIN = bin
DOC = doc
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


rutas_aereas: rutas_aereas.o punto.o ruta.o almacenrutas.o imagenES.o imagen.o
	$(CXX) -w $(OBJ)/rutas_aereas.o $(OBJ)/punto.o $(OBJ)/ruta.o $(OBJ)/almacenrutas.o $(OBJ)/imagenES.o $(OBJ)/imagen.o -o $(BIN)/rutas_aereas

rutas_aereas.o:
	$(CXX) -c -w -I$(INC) $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o

imagenES.o:
	$(CXX) -c -w -I$(INC) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

imagen.o:
	$(CXX) -c -w -I$(INC) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

almacenrutas.o:
	$(CXX) -c -w -I$(INC) $(SRC)/almacenrutas.cpp -o $(OBJ)/almacenrutas.o

ruta.o:
	$(CXX) -c -w -I$(INC) $(SRC)/ruta.cpp -o $(OBJ)/ruta.o

punto.o:
	$(CXX) -c -w -I$(INC) $(SRC)/punto.cpp -o $(OBJ)/punto.o



# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(BIN)/* $(OBJ)/* $(DOC)/html/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
