#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 50

//typedef char* String;
 struct s{
		char val[50];
		struct s* next;
} ;
typedef struct s Symb;
Symb table[MAXSIZE];


void initialize_hashtable()
{
int i;	
	for(i=0;i<MAXSIZE;i++)
		{
			table[i].val[0]='\0';
			table[i].next=NULL;
		}
}

int insert(char* x,int index)
{
int i,count=0;
Symb * temp,*temp1; 	
temp=&table[index];
if(temp->val[0]=='\0')
	{		
		strcat(temp->val,x);
		return 0;
	}
	else{
	
	while(temp->next!=NULL)
		{
			if(temp->next!=NULL)
			 { temp=temp->next;
			       count++;
			 }
		}
		
	}//end of else
temp1=(Symb *)malloc(sizeof(Symb));
strcat(temp1->val,x);
temp1->next=NULL;
temp->next=temp1;
return count;
}
	
