#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_REINAS 17


int reinaEnFila[MAX_REINAS];
int numReinas, soluciones=0;


int aceptable (int reinaFila, int reinaColumna) {
    int col;
    if (reinaEnFila[reinaColumna]!=0) {
        return FALSE; 
    }

    for(col=1; col<=numReinas; col++) {
        if ( (reinaEnFila[col] != 0) && ((abs(reinaEnFila[col]-reinaFila))==(abs(reinaColumna-col))) ) {
            return FALSE;
        }
    }

    return TRUE;
}


void NReinas(int reina) {
    int fila,columna,col;

    for(col=1;col<=numReinas;col++) {
        if(aceptable(reina,col)) {      // We search through all positions to see if there is any available
            reinaEnFila[col]=reina;     // Whenever we can assign a queen we put it in that position
            if (reina==numReinas) {     // If there are not any incompabilities we have reached a solution
                soluciones++;

                printf("\n\n");
                printf("Solution number: %d \n", soluciones);

                for (fila = 1; fila <= numReinas; fila++) {
                    for(columna = 1;columna <= numReinas; columna++) {
                        if (fila != reinaEnFila[columna]) {
                            printf(" *");
                        } else {
                            printf(" Q");
                        }
                    }
                    
                    printf("\n");
                }                
            }
            else {
                NReinas(reina+1);
            }

            reinaEnFila[col]=0;
        }
    }
}

int main (int argc, char *argv[]) {
    int i;

    for (i=0; i<MAX_REINAS; i++) {
        reinaEnFila[i] = 0;
    }

    soluciones=0;

    if (argc != 2) {
        printf ("It needs to be specified the number of queens.\n");
        return 0;
    }

    numReinas = atoi(argv[1]);

    if (numReinas >= MAX_REINAS) {
        printf ("Max number of queens is %d\n", (MAX_REINAS-1));

        return 0;
    }
    while (0) {
        break;
    }

    NReinas(1);
    printf("\n\n Number of solutions: %d \n", soluciones);

    return 0;
}