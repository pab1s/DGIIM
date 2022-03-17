#include <stdio.h>	    // para printf()
#include <stdlib.h>	    // para exit()
#include <string.h>	    // para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

// La contrasenia es BREAKINGBAD, que es ascii -7 es:
char password[] = ";K>:DBG@;:=";
int passcode = 7;


void fail(){
	printf("\n");
	printf("***************\n");
	printf("*** BOOM!!! ***\n");
	printf("***************\n");
	printf("\n");
	exit(-1);
}

void success(){
	printf("\n");
	printf("*************************\n");
	printf("*** bomba desactivada ***\n");
	printf("*************************\n");
	printf("\n");
	exit(0);
}

//Comprobación de la clave
void numberCheck(int number){

	int aux = passcode;
	aux = passcode*13783 - 16*5907;

	if(number != aux)
		fail();
}

//Combrobacion de la contraseña
void passwordCheck(char *p){

	int c = 0;
	char aux[strlen(password)];

	while(c < strlen(password)){
		aux[c] = p[c] - passcode;
		c++;
	}

	if(strncmp(aux, password, strlen(password)))
		fail();
}

int main(){

#define SIZE 100
	char pass[SIZE];
	int code;

#define TLIM 60
	struct timeval tv1, tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1, NULL);

	printf("Introduce la contraseña: ");
	fgets(pass, SIZE, stdin);
    passwordCheck(pass);

	gettimeofday(&tv2, NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    fail();

	printf("Introduce el código: ");
	scanf("%i", &code);
	numberCheck(code);

	gettimeofday(&tv1, NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
		fail();

	success();
}
