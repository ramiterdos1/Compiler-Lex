#include<stdio.h>
#include<stdlib.h>

#define SIZE 101

typedef struct node{
	char val[20];
	struct node *next;
	char type[20];
} NODE;

typedef struct 
{
	NODE *arr[SIZE];
} HTABLE;

HTABLE ht;

void initialise_table()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		ht.arr[i]=NULL;
	}

}

int insert(int index,char *s,char *t)
{
	NODE *temp;
	NODE *start;

	temp = (NODE*) malloc(sizeof(NODE));
	temp->next = NULL;
	
	strcpy(temp->val,s);
	strcpy(temp->type,t);
	
	if(ht.arr[index] == NULL)
	{
		ht.arr[index] = temp;			
		return 1;

	}

	start = ht.arr[index];

	if(strcmp(start->val,s)==0)
	{       	
		printf("MULTIPLE DECLARATION OF VARIABLE %s\n",s);
		return 0;
	}	
	while(start->next!=NULL)
	{
		if(strcmp(s,start->val)==0)
		{
			printf("MULTIPLE DECLARATION OF VARIABLE %s\n",s);
			return 0;		
		}
		start =start->next;
	}

	if(strcmp(s,start->val)!=0)
	{
		start->next = temp;

		return 1;
	}	
	else
		return 0;
}

void display_table()
{
	int i,count;

	for(i=0;i<SIZE;i++)
	{
		if(ht.arr[i] == NULL)
			continue;
		else
		{
			count = 0;
			NODE *temp;

			temp = ht.arr[i];
			while(temp!=NULL)		
			{
				printf("%s of type %s ",temp->val,temp->type);
				printf("AT LOCATION %d %d\n",i,count);
			
				count++;
				temp = temp->next;
			}			
		        
						
			printf("\n");
		}
	}
}


