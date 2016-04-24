#include<stdio.h>
#include<conio.h>
struct bst
{
	int info;
	struct bst *right,*left;
}*t1,*t2;
struct bst *insert(struct bst *root)
{
	int i;
	clrscr();
	printf("Enter the info\n");
	scanf("%d",&i);
	if(root==NULL)
	{
		root=(struct bst*)malloc(sizeof(struct bst));
		root->info=i;
		root->left=root->right=NULL;
	}
	else
	{
		t1=root;
		t2=NULL;
		while((t1->left!=NULL || t1->right!=NULL) && t2!=t1)
		{
			t2=t1;
			while(i<t1->info && t1->left!=NULL)
				t1=t1->left;
			while(i>t1->info && t1->right!=NULL)
				t1=t1->right;
		}
		t2=(struct bst*)malloc(sizeof(struct bst));
		t2->info=i;
		t2->left=t2->right=NULL;
		if(i<t1->info)
			t1->left=t2;
		else
			t1->right=t2;
	}
	return root;
}
int push(struct bst *stk[],struct bst *p,int top)
{
	stk[++top]=p;
	return top;
}
struct bst *pop(struct bst *stk[],int *top)
{
	return stk[(*top)--];
}
void inorder(struct bst *t)
{
	struct bst *p,*stk[20];
	int top=-1;
	p=t;
	do
	{
		while(p!=NULL)
		{
			top=push(stk,p,top);
			p=p->left;
		}
		if(top!=-1)
		{
			p=pop(stk,&top);
			printf("%d\t",p->info);
			p=p->right;
		}
	}while(top!=-1 || p!=NULL);
}
void main()
{
	int ch,i;
	struct bst *root;
	root=NULL;
	m:
	clrscr();
	printf("PRESS\n1. Insert\n2. Inorder\n3. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			root=insert(root);
			goto m;
		case 2:
			clrscr();
			if(root!=NULL)
				inorder(root);
			else
				printf("No tree exist\n");
			getch();
			goto m;
		case 3:
			exit();
		default:
			goto m;
	}
}