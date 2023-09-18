#include <stdio.h>

extern int yylex();
extern FILE *yyin;

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");

    if (!yyin) {
        printf("I can't open the file!\n");
        return 1;
    }

    while(!feof(yyin)) {
        yylex();
    }

    fclose(yyin);
    return 0;
}