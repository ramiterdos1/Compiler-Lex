
%{
   #include<string.h>
   #include"y.tab.h"
%}

letter		[A-Za-z]
digit		[0-9]
identifier	{letter}({letter}|{digit})*



%%


[ \t]		{;}

\-n		{return(0);}

"if"            {return(IF);}
"else"          {return(ELSE);}
"for"           {return(FOR);} 
"while"         {return(WHILE);}
"=="            {return(EQ);}
"!="            {return(NEQ);}
">"             {return(GT);}
"<"             {return(LT);}
">="            {return(GE);}
"<="            {return(LE);}
 
{identifier}	{yylval.str=strdup(yytext);
		 return(ID);}

 .		{return(yytext[0]);}
%%

int yywrap()
{
  return 1;
}
