%{
#include <stdio.h>
#include<string.h>
char result[100];
%}

%%
abc     { strcat(result, "ABC"); }
\n		{ strcat(result, "\n"); }
. 		{ strcat(result, yytext); }
[\0]
%%
/*.       { strcat(result, yytext); } /*OR printf("%s",yytext);*/  /* '.' takes anything letter other than '\n', '.*' takes a string till '\n' */
/*[\0]	{ printf("Sup"); return 0; }*/
int yywrap(void){}

int main() {
    yylex();
    printf("%s", result);
    return 0;
}
