SRC=src/
INC=include/
OBJ=obj/
BIN=bin/
DOC=doc/

main: main.o pila_max_cola.o pila_max_vd.o
	@echo Compilando...
	@g++ $(OBJ)main.o $(OBJ)pila_max_cola.o $(OBJ)pila_max_vd.o -o $(BIN)main
	@echo Compilado con exito!

main.o:
	@g++ -c $(SRC)main.cpp -o $(OBJ)main.o

pila_max_cola.o:
	g++ -c $(SRC)pila_max_cola.cpp -o $(OBJ)pila_max_cola.o

pila_max_vd.o:
	g++ -c $(SRC)pila_max_vd.cpp -o $(OBJ)pila_max_vd.o
	
clean:
	@rm -rf $(OBJ)* $(BIN)*

document:
	@doxygen
	@echo La documentacion generada se ha guardado en $(DOC)