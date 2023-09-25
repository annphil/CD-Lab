/* Pgm to find count of words. */

/* Prologue*/
%{
#include<stdio.h>

int i = 0;
%}

/* Rules section. Translation part. Takes RE and actions and converts it to C/C++. %% is delimiter for sections */
%%
[a-zA-Z0-9]* {i++;}		/* Rule for counting 
                          number of words*/
"\n" {printf("No. of words: %d\n", i); i=0; }
%%

/*functionto determine when the lexer should stop processing input. It is typically called when the lexer reaches the end of the input or needs to switch to a new input source. */
int yywrap(){
return 1;
}

int main(){
	yylex();
	return 0;
}
