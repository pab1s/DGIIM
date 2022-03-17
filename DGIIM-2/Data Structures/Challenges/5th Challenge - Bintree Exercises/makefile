BIN = bin/
OBJ = obj/
INC = include/
SRC = src/

all : 32 33 35 38 41
	
32 : $(SRC)32.cpp $(INC)bintree.h $(INC)bintree.hxx $(INC)node.hxx
	g++  -o $(BIN)32 -I$(INC) $(SRC)32.cpp	

33 : $(SRC)33.cpp $(INC)bintree.h $(INC)bintree.hxx $(INC)node.hxx
	g++  -o $(BIN)33 -I$(INC) $(SRC)33.cpp
	
35 : $(SRC)35.cpp $(INC)bintree.h $(INC)bintree.hxx $(INC)node.hxx
	g++  -o $(BIN)35 -I$(INC) $(SRC)35.cpp

38 : $(SRC)38.cpp $(INC)bintree.h $(INC)bintree.hxx $(INC)node.hxx
	g++  -o $(BIN)38 -I$(INC) $(SRC)38.cpp

41 : $(SRC)41.cpp $(INC)bintree.h $(INC)bintree.hxx $(INC)node.hxx
	g++  -o $(BIN)41 -I$(INC) $(SRC)41.cpp
	
clean:
	echo Limpiando.
	-rm $(BIN)*
	
documentacion: 
	doxygen doc/Doxyfile
