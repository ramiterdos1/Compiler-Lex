%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
%}

letter  [a-zA-Z]
digit   [0-9]
id      {letter}({letter}|{digit})*

%%

{digit}+    {yylval.str= strdup(yytext);
 	     return NUMBER;}
[ \t\n]       ;
 
"int"       {yylval.str = strdup(yytext);
	     return TYPE_TOKEN; }
	     
"float"     {yylval.str = strdup(yytext);
	     return TYPE_TOKEN; }

{id}        {yylval.str = strdup(yytext);
	     return NAME;}

.            return yytext[0];	

%%


yywrap(){}

