// Write a lex program to recognize all strings which do not contain the first four characters of your name as a substring.


%{
#include<stdio.h>
#include<stdlib.h>
%}

%%

.*[Aa][Nn][Nn][Aa].* {printf("Not a valid string %s",yytext);}
.+ {printf("Valid string %s\n",yytext);}
\n {return 0;}

%%

int yywrap(){
	// return 1;
	// Whether we return 1 or 0, terminal expects more input
}

int main(){
    yylex();
    return 1;
}
