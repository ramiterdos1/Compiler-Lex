%{
 	#include<stdio.h>
	#include<stdlib.h>
	#include"symbol_table.c"
	#include"string.h"
	void install_id(char *,char *);
	void insert_table(char *);
	char temp[100][100];
	int count = 0;

	char tempc[20]="T";
	int temp_count =0;
	void temp_create();
%}
%union
{
	char *str;	
	int no;
}
%token <str> NAME
%token <str> NUMBER
%token <str> TYPE_TOKEN
%type <str> dcl
%type <str> dcl_smt
%type <str> type
%type <str> id_list
%%
	dcl:dcl dcl_smt
	   |dcl_smt
	   ; 
	dcl_smt:type id_list';' {insert_table($1);count=0;}
	       ;
	type:TYPE_TOKEN  {strcpy($$,$1);}  	
	    ; 		
	id_list:id_list','NAME 	{strcpy(temp[count],$3);count++;}	    
	       |NAME            {strcpy(temp[count],$1);count++;} 
	       ;
%%
main()
{	
	yyparse();
	display_table();
	return 0;
}
void insert_table(char *s)
{
	int i;
	for(i=0;i<count;i++)
	{
		install_id(temp[i],s);			
	}
}
void install_id(char *s1,char *type)
{
	int i,sum=0;

	for(i=0;s1[i]!='\0';i++)
	{
		sum += s1[i];
	}	
	sum = sum%SIZE;
	insert(sum,s1,type);
}		
yyerror(char *err)
{
	printf("ERROR :%s\n",err);
	exit(1);
}
