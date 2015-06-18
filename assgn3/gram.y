
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    char* newtemp();
    void back_patch();
    void print_code();
    char str_arr[100][100];
    char tempvar[5];
    char cond_arr[10];
    int line_no=99,start_line,start_line2,end_line,end_line2,elsequad;
    int st_count,i;
    char buff[100];	

%}

%union{
    char *str;
    int no;
}

%token <str> ID 
%token <no>  NUMBER
%token <str> IF ELSE
%token <str> WHILE FOR
%token <str> EQ NEQ GT LT GE LE
%type  <str> start_prog
%type  <str> IF_ST
%type  <str> IF_ELSE_ST
%type  <str> WHILE_ST
%type  <str> FOR_ST INCR
%type  <str> BLOCK
%type  <str> CONDN
%type  <str> assgn_bl assgn_st
%type  <str> EXPR
%left '+' '-'
%left '*' '/'

%%

start_prog : BLOCK    
      | assgn_st start_prog
      | assgn_st ; 

assgn_st : ID '=' EXPR ';' '#'  { st_count++;
                                    sprintf(str_arr[st_count],"%d-->%s=%s\n",st_count,$1,$3);
                                    back_patch();
                                    print_code();
                                    st_count=0;
                                  };
   
assgn_bl : ID '=' EXPR ';'    { st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=%s\n",st_count,$1,$3);
                               };

EXPR : EXPR '+' EXPR           { $$=strdup(newtemp());
                                 st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=%s+%s\n",st_count,$$,$1,$3);}

     | EXPR '-' EXPR           { $$=strdup(newtemp());
                                 st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=%s-%s\n",st_count,$$,$1,$3);}

     | EXPR '*' EXPR           { $$=strdup(newtemp());
                                 st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=%s*%s\n",st_count,$$,$1,$3);}

     | EXPR '/' EXPR           { $$=strdup(newtemp());
                                 st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=%s/%s\n",st_count,$$,$1,$3);}

     | '-' EXPR                { $$=strdup(newtemp());
                                 st_count++;
                                 sprintf(str_arr[st_count],"%d-->%s=-%s\n",st_count,$$,$2);}

     | '(' EXPR ')'            {$$=strdup($2);}

     | ID                      {$$=strdup($1);};


IF_ST : IF '(' CONDN ')' '{' BLOCK '}' ';'   { line_no++;
                                               printf("%d--> if %s then goto %d\n",line_no,$3,line_no+2);
                                               line_no++;
                                               printf("%d--> goto %d\n",line_no,line_no+st_count+1);
                                               back_patch();
                                               print_code();
                                               st_count=0;
                                             };


IF_ST2 : IF '(' CONDN ')' '{' BLOCK '}'      { line_no++;
                                               printf("%d--> if %s then goto %d\n",line_no,$3,line_no+2);
                                               line_no++;
                                               printf("%d--> goto %d\n",line_no,line_no+st_count+2);
                                               elsequad=line_no+st_count+1;
                                               back_patch();
                                               print_code();
                                               st_count=0;
                                             };

IF_ELSE_ST : IF_ST2 ELSE '{' BLOCK '}'       { printf("%d--> goto %d\n",elsequad,elsequad+st_count+1);
                                               line_no=elsequad;
                                               back_patch();
                                               print_code();
                                               st_count=0;
                                             };

WHILE_ST : WHILE '(' CONDN ')' '{' BLOCK '}'  { line_no++;
                                                start_line=line_no;
                                                printf("%d--> if %s then goto %d\n",line_no,$3,line_no+2);
                                                line_no++;
                                                printf("%d--> goto %d\n",line_no,line_no+st_count+2);
                                                end_line=line_no+st_count+1;
                                                back_patch();
                                                print_code();
                                                printf("%d--> goto %d\n",end_line,start_line);
                                                line_no=end_line;
                                                st_count=0;
                                              };

FOR_ST : FOR '(' ID '=' ID ';' CONDN ';' INCR ')' '{' BLOCK '}'   { line_no++;
                                                                    printf("%d--> %s=%s\n",line_no,$3,$5);
                                                                    line_no++;
                                                                    printf("%d--> X1=%s\n",line_no,$5);
                                                                    line_no++;
                                                                    start_line2=line_no;
                                                                    printf("%d--> if%s then goto %d\n",line_no,$7,line_no+2);
                                                                    line_no++;
                                                                    printf("%d--> goto %d\n",line_no,line_no+st_count+2);
                                                                    	 
								    end_line2=line_no+st_count+1;
                                                                    back_patch();
                                                                    print_code();
                                                                    printf("%d--> goto %d\n",end_line2,start_line2);
                                                                    line_no=end_line2;
                                                                    st_count=0;
                                                                   };

INCR : ID '+' '=' ID      { st_count++;
                            sprintf(buff,"%d-->%s=%s+%s\n",0,$1,$1,$4);};

CONDN : ID EQ ID          { sprintf(cond_arr,"(%s==%s)",$1,$3);
                            $$=strdup(cond_arr);}

      | ID NEQ ID         { sprintf(cond_arr,"(%s!=%s)",$1,$3);
                            $$=strdup(cond_arr);}  

      | ID GT ID          { sprintf(cond_arr,"(%s>%s)",$1,$3);
                            $$=strdup(cond_arr);}

      | ID LT ID          { sprintf(cond_arr,"(%s<%s)",$1,$3);
                            $$=strdup(cond_arr);}

      | ID GE ID          { sprintf(cond_arr,"(%s>=%s)",$1,$3);
                            $$=strdup(cond_arr);}

      | ID LE ID          { sprintf(cond_arr,"(%s<=%s)",$1,$3);
                            $$=strdup(cond_arr);};

BLOCK : assgn_bl BLOCK
      | assgn_bl                  
      | IF_ST BLOCK
      | IF_ST             
      | IF_ELSE_ST BLOCK
      | IF_ELSE_ST        
      | WHILE_ST BLOCK 
      | WHILE_ST          
      | FOR_ST BLOCK
      | FOR_ST            ;

%%

char* newtemp(){
   i++;
   sprintf(tempvar,"T%d",i);
   return(tempvar);
}


void print_code(void)
{
    int i;
    for(i=1;i<=st_count;i++)
    {
       printf("%s\n",str_arr[i]);
    }
}

void back_patch()
{
        char tmp[100];
        int off,i;
        for(i=1;i<=st_count;i++)
        {
            sscanf(str_arr[i],"%d%s",&off,tmp);
            sprintf(str_arr[i],"%d%s",off+line_no,tmp);
        }
        line_no+=st_count;
}

main(void)
{
  st_count=0;
  i=0;
  yyparse();
  return(0);
}

yyerror(char *err)
{
  printf("ERROR:%s",err);
  exit(1);
}


