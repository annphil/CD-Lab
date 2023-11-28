%{
#include <stdio.h>
%}

%%
abc     ; // Match "abc" but do nothing
.       { putchar(yytext[0]); } // Pass all other characters through
%%

int yywrap(void){}

int main() {
    yylex();
    return 0;
}
