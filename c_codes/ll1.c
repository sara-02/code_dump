#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
  	struct node *ptr;
};
void printList(struct node* start)
{
	while(start!=NULL)
	{
		printf("| %d |-->",start->data);
		start=start->ptr;
	}
	printf("| \\ |\n");
}
int main()
{
	struct node* head=NULL;
	struct node* second=NULL;
	struct node* third=NULL;
  
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;
	head->ptr=second;
	second->data=4;
	second->ptr=third;
	third->data=0;
	third->ptr=NULL;
	
	printList(head);
return 0;
}
