#include<stdio.h>
#include<conio.h>
struct bst
{
	int info;
	struct bst *right,*left;
}*t1,*t2,*t4;
int a;
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
		if(i==t1->info)
		{
			printf("Same value already exist\n");
			getch();
		}
		else
		{
			t2=(struct bst*)malloc(sizeof(struct bst));
			t2->info=i;
			t2->left=t2->right=NULL;
			if(i>t1->info)
				t1->right=t2;
			else if(i<t1->info)
				t1->left=t2;
		}
	}
	return root;
}
struct bst *search(struct bst *root,int i,int j)
{
	int k=1;
	struct bst *t3;
	t1=root;
	t2=NULL;
	t3=NULL;
	while((t1->left!=NULL || t1->right!=NULL) && t2!=t1)
	{
		t2=t1;
		while(i<t1->info && t1->left!=NULL)
		{
			t3=t1;
			t1=t1->left;
			k*=2;
		}
		while(i>t1->info && t1->right!=NULL)
		{
			t3=t1;
			t1=t1->right;
			k=2*k+1;
		}
	}
	if(i==t1->info)
	{
		printf("Value found at %d\n",k);
		if(j==0)
			getch();
		return t3;
	}
	else
	{
		printf("Not found\n");
		return NULL;
	}
}
void inorder(struct bst *t,int i)
{
	if(i==0 && t->left!=NULL)
		inorder(t->left,i);
	if(t->left!=NULL && i==1 && a==1)
	{
		t4=t2;
		t2=t;
		inorder(t->left,i);
	}
	if(t==t1)
	{
		if(t->right!=NULL)
		{
			a++;
			inorder(t->right,i);
		}
	}
	printf("%d\t",t->info);
	if(t->right!=NULL && a==0)
		inorder(t->right,i);
	if(a==1 && t->left==NULL)
	{
		t4=t2;
		t2=t;
	}
}
struct bst *del(struct bst *root,int i)
{
	struct bst *t3;
	t3=search(root,i,1);
	m1:
	if(t3!=NULL)
	{
		if(t1->left!=NULL && t1->right!=NULL)
		{
			a=0;
			t2=t1;
			inorder(t1,1);
			t1->info^=t2->info^=t1->info^=t2->info;
			t1=t2;
			t3=t4;
			goto m1;
		}
		else if(t1->left==NULL && t1->right==NULL)
		{
			if(t3->left==t1)
				t3->left=NULL;
			else if(t3->right==t1)
				t3->right=NULL;
			free(t1);
		}
		else if(t1->left!=NULL && t1->right==NULL && t3->left==t1)
		{
			t3->left=t1->left;
			free(t1);
		}
		else if(t1->right!=NULL && t1->left==NULL && t3->left==t1)
		{
			t3->left=t1->right;
			free(t1);
		}
		else if(t1->left!=NULL && t1->right==NULL && t3->right==t1)
		{
			t3->right=t1->left;
			free(t1);
		}
		else if(t1->right!=NULL && t1->left==NULL && t3->right==t1)
		{
			t3->right=t1->right;
			free(t1);
		}
	}
	else if(t3==NULL && t1!=NULL)
	{
		if(t1->left!=NULL && t1->right==NULL)
			root=t1->left;
		else if(t1->right!=NULL && t1->left==NULL)
			root=t1->right;
		else if(t1->left==NULL && t1->right==NULL)
			root=NULL;
		else
		{
			a=0;
			t2=t1;
			inorder(t1,1);
			t1->info^=t2->info^=t1->info^=t2->info;
			t1=t2;
			t3=t4;
			goto m1;
		}
		free(t1);
	}
	return root;
}
void main()
{
	int ch,i;
	struct bst *root;
	root=NULL;
	m:
	clrscr();
	printf("PRESS\n1. Insert\n2. Search\n3. Inorder\n4. Delete\n5. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			root=insert(root);
			goto m;
		case 2:
			clrscr();
			printf("Enter the value to search\n");
			scanf("%d",&i);
			search(root,i,0);
			goto m;
		case 3:
			clrscr();
			t2=NULL;
			t1=NULL;
			a=0;
			if(root==NULL)
				printf("No tree exist\n");
			else
				inorder(root,0);
			getch();
			goto m;
		case 4:
			clrscr();
			printf("Enter the info to delete\n");
			scanf("%d",&i);
			root=del(root,i);
			goto m;
		case 5:
			exit();
		default:
			goto m;
	}
}