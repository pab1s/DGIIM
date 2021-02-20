BIN = bin
OBJ = obj
SRC = src
INC = include

$(BIN)/main: $(OBJ)/main.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	echo Creando el ejecutable.
	g++ $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	echo Creando el main.o.
	g++ -g -c -I./$(INC) $< -o $@
	
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	echo Creando el imagen.o.
	g++ -g -c -I./$(INC) $< -o $@

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	echo Creando el imagenES.o.
	g++ -g -c -I./$(INC) $< -o $@	

clean:
	echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*
	
rebuild: clean $(BIN)/main

documentacion:
	echo Creando la documentacion.
	doxygen Doxyfile
