#include<stdio.h>
#include<stdlib.h>
struct st
{
	int pow;
	int coeff;
	struct st *ptr;
}; struct st *startA=NULL,*startB=NULL,*startC=NULL,*temp,*ptr1,*ptr2,*ptr3;

void fillA()
{
	int i;int p,c;
	printf("enter  in descendning order\n");
	printf("enter 1 to discontnue or otherwise\n");
	scanf("%d",&i);
	while(i!=1)
	{
		printf("enter the power\n");
		scanf("%d",&p);
		printf("enter the coeff\n");
		scanf("%d",&c);
		temp=(struct st*)malloc(sizeof(struct st));
		temp->pow=p;
		temp->coeff=c;
		temp->ptr=NULL;
		
		if(startA==NULL)
		{
			startA=temp;
			ptr1=temp;
		}
		else
		{
			ptr1->ptr=temp;
			ptr1=temp;
		}
	    printf("enter 1 to discontnue or otherwise\n");
	    scanf("%d",&i);
		

	}
	ptr1->ptr=NULL;

	
}
void dispA()
{
	temp=startA;
	while(temp!=NULL)
	{
		printf("|%d|-->|%d|\t",temp->coeff,temp->pow);
		temp=temp->ptr;
	
	}
	printf("\n");
}
void fillB()
{
	int i;int p,c;
	printf("enter  in descendning order\n");
	printf("enter 1 to discontnue or otherwise\n");
	scanf("%d",&i);
	while(i!=1)
	{
		printf("enter the power\n");
		scanf("%d",&p);
		printf("enter the coeff\n");
		scanf("%d",&c);
		temp=(struct st*)malloc(sizeof(struct st));
		temp->pow=p;
		temp->coeff=c;
		temp->ptr=NULL;
		
		if(startB==NULL)
		{
			startB=temp;
			ptr2=temp;
		}
		else
		{
			ptr2->ptr=temp;
			ptr2=temp;
		}
	    printf("enter 1 to discontnue or otherwise\n");
	    scanf("%d",&i);
		

	}
	ptr2->ptr=NULL;

	
}
void dispB()
{
	temp=startB;
	while(temp!=NULL)
	{
		printf("|%d|-->|%d|\t",temp->coeff,temp->pow);
		temp=temp->ptr;
	
	}
	printf("\n");
}
void add()
{
	ptr1=startA;
	ptr2=startB;
	free(temp);
	while((ptr1!=NULL)&&(ptr2!=NULL))
	{
			
		if(ptr1->pow>ptr2->pow)	
		{
			temp=(struct st*)malloc(sizeof(struct st));
			if(temp==NULL)
			{
				printf("mem not allocated\n");
				exit(1);
			}
			temp->pow=ptr1->pow;
			temp->coeff=ptr1->coeff;
			temp->ptr=NULL;
			ptr1=ptr1->ptr;
		}
		else if(ptr2->pow>ptr1->pow)
		{       temp=(struct st*)malloc(sizeof(struct st));
			if(temp==NULL)
			{
				printf("mem not allocated\n");
				exit(1);
			}
			temp->pow=ptr2->pow;
			temp->coeff=ptr2->coeff;
			temp->ptr=NULL;
			ptr2=ptr2->ptr;
		}
		else if(ptr1->pow==ptr2->pow)
		{        temp=(struct st*)malloc(sizeof(struct st));
				if(temp==NULL)
			{
				printf("mem not allocated\n");
				exit(1);
			}
			temp->pow=ptr2->pow;
			temp->coeff=ptr1->coeff+ptr2->coeff;
			temp->ptr=NULL;
			ptr1=ptr1->ptr;
			ptr2=ptr2->ptr;
		}
		if(startC=NULL)
		{
			startC=temp;
			ptr3=temp;
			printf("|%d|-->|%d|\t",ptr3->coeff,ptr3->pow);
		}
		else
		{
			ptr3->ptr=temp;
			ptr3=temp;
		}
		
	}
	if((ptr1==NULL)&&(ptr2!=NULL))
	{
		
		ptr3->ptr=ptr2;

	}
	else if((ptr2==NULL)&&(ptr1!=NULL))
	{
		ptr3->ptr=ptr1;	
	
	}
	else
	{
		ptr3->ptr=NULL;
	}
}
void dispC()
{
	temp=startC;
	while(temp!=NULL)
	{
		printf("|%d|-->|%d|\t",temp->coeff,temp->pow);
		temp=temp->ptr;
	
	}
	printf("\n");
}
int main()
{
	printf("for the first list\n");
	fillA();
	dispA();
	printf("for the second list\n");
	fillB();
	dispB();
	add();
	printf("the result is\n");
	dispC();
}
