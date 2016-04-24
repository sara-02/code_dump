#include<stdio.h>
#include<conio.h>
struct bst
{
	int info;
	struct bst *right,*left;
}*t1,*t2;
unsigned int insert(struct bst *root)
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
			printf("Same value exist already\n");
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
void inorder(struct bst *t)
{
	if(t->left!=NULL)
		inorder(t->left);
	printf("%d\t",t->info);
	if(t->right!=NULL)
		inorder(t->right);
}
void search(struct bst *root,int i)
{
	int k=1;
	t1=root;
	t2=NULL;
	while((t1->left!=NULL || t1->right!=NULL) && t2!=t1)
	{
		t2=t1;
		while(i<t1->info && t1->left!=NULL)
		{
			t1=t1->left;
			k*=2;
		}
		while(i>t1->info && t1->right!=NULL)
		{
			t1=t1->right;
			k=2*k+1;
		}
	}
	if(i==t1->info)
		printf("Value found at %d",k);
	else
		printf("Not found\n");
	getch();
}
void main()
{
	int ch,i;
	struct bst *root;
	root=NULL;
	m:
	clrscr();
	printf("Press\n1. Insert\n2. Search\n3. Inorder\n4. Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			root=insert(root);
			goto m;
		case 2:
			printf("Enter the value to find\n");
			scanf("%d",&i);
			search(root,i);
			goto m;
		case 3:
			if(root==NULL)
			{
				printf("No info");
				getch();
				goto m;
			}
			inorder(root);
			getch();
			goto m;
		case 4:
			exit();
		default:
			goto m;
	}
}