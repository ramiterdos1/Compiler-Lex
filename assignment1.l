%{
	#include<stdio.h>
	#include<string.h>
	#define MAXSIZE 50
	#include "symbol_table.c"
	void load_id(char *);
	int hash(char *s);
%}

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*

%%
{ws}		{if(yytext[0]=='\n')printf("\n");}
"if"		{printf("IF ");}
"else"		{printf("ELSE ");}
"int"		{printf("INT ");}
"float"		{printf("FLOAT ");}
"char"		{printf("CHAR ");}
"for"		{printf("FOR ");}
"while"		{printf("WHILE ");}
"break"		{printf("BREAK ");}
{id}        {printf("ID-%s ",yytext);load_id(yytext);}
{digit}     {printf("DIGIT-%s ",yytext);}
"+"		{printf("PLUS ");}
"-"		{printf("MINUS ");}
"/"		{printf("DIV ");}

"%"		{printf("MOD ");}
"--"	{printf("DEC ");}
"++"	{printf(" INC ");}
"="		{printf("ASSIGN ");}
"=="	{printf("EQ ");}
"!="	{printf("NEQ ");}
">"		{printf("GT ");}
"<"		{printf("LT ");}
">="	{printf("GE ");}
"<="	{printf("LE ");}
"&&"	{printf("AND ");}
"||"	{printf("OR ");}
"~"		{printf("NOT ");}
"&"		{printf("AMPS ");}
"*"		{printf("POINTER ");}
";"		{printf("SEMICOL ");}
","		{printf("COMMA ");}
"("		{printf("OpnBrkt ");}
")"		{printf("ClsBrkt ");}
%%


int main()
{
initialize_hashtable();	
yylex();
return 0;
}
int hash(char  *s )
{
    int i=0,cal=0,len=strlen(s);
    while(i<len || s[i]!=0)
    {
        cal+=(s[i]-0)/(s[i]-'A'+1);
        i++;
    }cal*=(i+211);
    return cal;
    //return cal;
}

void load_id(char *s)
{
int pos=hash(s),index=0;
pos=pos%MAXSIZE;
index=insert(s,pos);
if(index!=-1)
	;//printf("\n[Identifier=%s is placed @ Position=%d and here we have only %d collision.]\n",s,pos,index);
	
}

int yywrap() {return 1;}

