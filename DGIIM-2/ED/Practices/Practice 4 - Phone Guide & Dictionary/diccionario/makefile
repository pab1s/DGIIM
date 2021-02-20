BIN = bin
OBJ = obj
INC = include
SRC = src

$(BIN)/usodiccionario: $(OBJ)/usodiccionario.o $(INC)/diccionario.h
	echo Creando el ejecutable.
	g++ -I./$(INC) $^ -o $@ 

$(OBJ)/usodiccionario.o: $(SRC)/usodiccionario.cpp
	echo Creando el ejecutable
	g++ -g -c $(SRC)/usodiccionario.cpp -o $@

clean:
	echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*
