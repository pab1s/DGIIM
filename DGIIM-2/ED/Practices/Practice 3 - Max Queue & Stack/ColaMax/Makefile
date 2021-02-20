BIN = bin
OBJ = obj
INC = include
SRC = src

$(BIN)/main: $(OBJ)/main.o $(INC)/cola_max.h
	echo Creando el ejecutable.
	g++ -I./$(INC) $^ -o $@ 

$(OBJ)/main.o: $(SRC)/main.cpp
	echo Creando el ejecutable
	g++ -g -c $(SRC)/main.cpp -o $@

clean:
	echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*
