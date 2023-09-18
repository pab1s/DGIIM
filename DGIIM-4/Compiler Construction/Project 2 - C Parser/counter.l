/* Project 2: Text analyzer to count the number of words, lines and characters. */
/* Author: Pablo Olivares */

%{
	/* Definition section */
	#include<stdio.h>
	int nLines = 0, nWords = 0, nChars = 0;
%}

/*Rule Section*/
%%
\n 				{nLines++; nChars+=yyleng;}
[A-Za-z]+ 	{ nWords++; nChars+=yyleng;}
.				nChars+=yyleng;
%%

int yywrap(){}

int main(int argc, char *argv[])
{
	// yyin as pointer of File type
	extern FILE *yyin;

	// yyin points to the input file and opens it in read mode
	for (int i = 1; i<argc; i++) {
		yyin = fopen(argv[i], "r");
		yylex();

		// We print nLines + 1 because last line can't have "\n"
		printf("\nFILE %d:", i);
		printf("\nNo. of lines: %d", ++nLines);
		printf("\nNo. of words: %d", nWords);
		printf("\nNo. of characters: %d\n", nChars);
		nLines = 0; nChars = 0; nWords = 0;
	}

	return 0;
}
