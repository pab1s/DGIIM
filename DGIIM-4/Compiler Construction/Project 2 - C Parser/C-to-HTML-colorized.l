/* Project 2: Text analyzer to color C files in HTML */
/* Author: Pablo Olivares */

%{
	/*Definition section */
    #include <string.h>
    #include <stdio.h>

    char* html_header = "<!DOCTYPE html>\n<html>\n<head>\n<style>\n.mark {background-color: #FFFF00;}\n.blue {color: blue;}\n</style>\n</head>\n<body>\n ";
    char* html_closer = "</body>\n</html>";

    char* process(char* text);
    char* str_replace(char *str, const char *find, const char *replacement);
%}

/* Alias for some of my regular expresions */

comment                                     (\/\/.*[\n])|(\/\*.*\*\/)
blank                                       [ \t\n]
variable                                    ([A-Za-z0-9\(\)]|_|-)*

include                                     #include{blank}*<.*>
define                                      #define{blank}{variable}{blank}*{variable}?(\n)
for                                         {blank}*for{blank}*\([^\)]*\){blank}*[\{].*[^color]
while                                       {blank}*while{blank}*\([^\)]*\){blank}*[\{].*[^color]

if                                          {blank}*if{blank}*\([^\)]*\){blank}*[\{].*[^color]
else                                        {blank}*else{blank}*[\{].*[^color]
do                                          {blank}*do{blank}*[\{].*[^color]
switch                                      {blank}*switch{blank}*(\([^\)]*\)){blank}*[\{].*[^color]

green                                       {include}|{define}|break;
blue                                        {for}|{if}|{else}|{do}|switch
color                                       {green}|{blue} 

/* Rules section */
%%

{comment}       {fprintf(yyout, "%s", process(yytext)); }
{while}         {fprintf(yyout, "<span style=\"color:green;\">"); fprintf(yyout, "%s", process(yytext));}
{green}         {fprintf(yyout, "<span style=\"color:green;\">"); fprintf(yyout, "%s", process(yytext)); fprintf(yyout, "%s", "</span>");}
{blue}          {fprintf(yyout, "<span style=\"color:blue;\">"); fprintf(yyout, "%s", process(yytext));}

[ ]             {fprintf(yyout, "&nbsp;");}
[\t]+           {fprintf(yyout, "&emsp;");}
[\n]+           {fprintf(yyout, "<br>\n");}
[<]             {fprintf(yyout, "&lt");}
[>]             {fprintf(yyout, "&gt");}
[}]             {fprintf(yyout, "} </span>");}
.               {fprintf(yyout, "%s", yytext); }

%%

int yywrap(){}

int main(int argc, char *argv[])
{
	// yyin and yyout as pointer of File type
	extern FILE *yyin, *yyout;

	// yyin points to the input C file and opens it in read mode
    if (argc < 2) {
        printf("ERROR, you have to pass the input C file as an argument.");
        return 1;
    }
	yyin = fopen(argv[1], "r");

	// yyout points to the file output.txt and opens it in write mode
	yyout = fopen("output.html", "w");

    fprintf(yyout, html_header);
	yylex();
    fprintf(yyout, html_closer);
	return 0;
}

// Function to process C characters into HTML characters
char* process(char* text)
{
    int i = 0;
    char * section = malloc(strlen(text) + 1); 
    strcpy(section, text);

    section = str_replace(section, ">", "&gt");
    section = str_replace(section, "<", "&lt");
    section = str_replace(section, " ", "&nbsp;");
    section = str_replace(section, "\t", "&emsp;");
    section = str_replace(section, "\n", "<br>\n");
    return section;
}

// Function to replace all ocurrences of a given c-substring by another c-string
char* str_replace(char *str, const char *find, const char *replacement)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = str;
    size_t size = strlen(str);
    size_t find_len = strlen(find);
    size_t repl_len = strlen(replacement);

    while (1) {
        const char *p = strstr(tmp, find);

        // walked past last occurrence of find; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before find
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy replacement string
        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + find_len;

        // updating the new length of the str for the return
        size = size + repl_len - find_len;
    }

    // Now we allocate the memory for the str string
    free(str);
    str = (char*)malloc(size+1);
    for (int i = 0; i <= size; i++) {
        str[i] = buffer[i];
    }
    return str;
}