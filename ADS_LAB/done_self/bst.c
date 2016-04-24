#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
}; struct node *head,*temp,*temp1;
int flag;
int insert(int n)
{
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->val=n;
		head->left=NULL;
		head->right=NULL;
		temp=head;
		return 1;
	}
	else if(temp==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->val=n;
		temp->left=NULL;
		temp->right=NULL;
		if(flag==1)
		{
			temp1->left=temp;
		}
		else
		{
			temp1->right=temp;
		}
		return 1;
	}
	else if(n<temp->val)
	{
		temp1=temp;
		temp=temp->left;
		flag=1;
		if(insert(n))
			return 1;
		else return -1;	
		
	}
	else if(n>temp->val)
	{
		temp1=temp;
		temp=temp->right;
		flag=0;
		if(insert(n))
			return 1;
		else return -1;	
	}
	else if(n==temp->val)
	{
			return -1;
	}
	
}
struct node* parent(struct node *temp,int n)
{
	 if(temp->val<n)
	{
		temp1=temp;
		temp=temp->right;
		parent(temp,n);
	}
	else if(temp->val>n)
	{
		temp1=temp;
		temp=temp->left;
		parent(temp,n);
	}
	else if(temp->val==n)
	{
		return temp1;
	}
	else
		return NULL;
}
int search(struct node *temp,int n)
{
	if(temp==NULL)
		return 0;
	else if(temp->val<n)
	{
		search(temp->right,n);
	}
	else if(temp->val>n)
	{
		search(temp->left,n);
	}
	else if(temp->val==n)
	{
		return 1;
	}
}
void inorder(struct node* temp)
{
		if(temp!=NULL)
		{
		inorder(temp->left);
		printf("|%d|-->",temp->val);
		flag+=temp->val;
		inorder(temp->right);
	}
}
void preorder(struct node* temp)
{
	if(temp!=NULL)
		{
		printf("|%d|-->",temp->val);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node* temp)
{
	if(temp!=NULL)
		{
		postorder(temp->left);
		postorder(temp->right);
		printf("|%d|-->",temp->val);
	}
}
int main()
{	int n,ch;
	head=NULL;
	do
	{
	printf("enter the number to insert::\t");
	scanf("%d",&n);
	temp=head;
	temp1=head;
	if(insert(n)==-1)
	{
		printf("number exists");
	}
	printf("enter 1 to insert again or otherwise::\t");
	scanf("%d",&ch);
	}while(ch==1);
	printf("\n");
	temp=head;
	flag=0;
	printf("INORDER::\t");
	inorder(temp);
	printf("\n");
	temp=head;
	printf("PREORDER::\t");
	preorder(temp);
	printf("\n");
		temp=head;
	printf("POSTORDER::\t");
	postorder(temp);
		printf("\n");
	/*do
	{
		printf("enter the number to delete ::\t");
		scanf("%d",&n);
		temp=head;
		temp1=head;
		if(search(temp,n)==0)
		{
			printf("Number not found\n");
		}		
		else
		{
			temp1=parent(temp,n);
			printf("parent is==%d \n",temp1->val);
			if(temp1->left->val==n)
			{
				temp=temp1->left;
				if(temp->left==NULL && temp->right==NULL)
					temp1->left=NULL;
				else
						printf("cannot delete not a leaf\n");
						
			}
			else if(temp1->left->val==n)
			{
				temp=temp1->right;
				if(temp->left==NULL && temp->right==NULL)
					temp1->right=NULL;
				else
						printf("cannot delete not a leaf\n");
			}
			else
				printf("cannot delete not a leaf\n");
			
		}
	printf("enter 1 to search again or otherwise::\t");
	scanf("%d",&ch);
	}while(ch==1);
	printf("\n");
	temp=head;
	printf("INORDER::\t");
	inorder(temp); */
	
	printf("\nSUM-->%d\n",flag);
	return 0;
}	
