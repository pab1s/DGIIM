/*lex program to identify words in a language*/
%{
/* Definition section */
#include<stdio.h>
int i = 1;
%}
  
/* Rules Section*/
%%
(a[a-c]*(b|c)+)     {printf("THE WORD %d IS IN THE LANGUAGE\n", i); ++i;}
"\n"                {}
.+                  {printf("THE WORD %d IS NOT IN THE LANGUAGE\n", i); ++i;}
%%
  
int yywrap(void) {
    return 1;
}