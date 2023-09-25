/* Program to count number of chars words sentences spaces and lines. */
/*
To run the program: 
lex program.l
gcc lex.yy.c
./a.out < input.txt
*/

%{
#include<stdio.h>
int chars=0, words=0, lines=0, sentences=0, spaces=0;
%}

%%
[?.!] {sentences++; chars+=yyleng;}
[\n] {lines++; chars+=yyleng;}
[ \t] {spaces++; chars+=yyleng;}
[0-9a-zA-Z]+ {words++; chars+=yyleng;}
[/0] /*{ }*/
%%
/*[^\t\n ]+ { wc++;  cc+=yyleng;}*/
int yywrap(void){}

int main(){
	/*printf("Enter the input:\n");*/
	
	yylex();
	printf("chars: %d\nwords: %d\nlines: %d\nspaces: %d\nsentences: %d\n", chars, words, lines, spaces, sentences);
	return 0;
	
}
