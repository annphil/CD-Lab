// Write a lex program to recognize all strings which do not contain the first four characters of your name as a substring.

%{
#include<stdio.h>
#include<stdlib.h>
%}

%%

\n {return 1;}
.*[Aa][Nn][Nn][Aa].* {printf("Not a valid string %s\n",yytext);}
.+ {printf("Valid string %s\n",yytext);}

%%

int yywrap(){}

int main(){
    yylex();
    return 1;
}
