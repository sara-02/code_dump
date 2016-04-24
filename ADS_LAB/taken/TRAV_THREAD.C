#include<stdio.h>
#include<conio.h>
struct bst
{
	int info,rthread;
	struct bst *right,*left;
}*t1,*t2,*t3;
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
		root->rthread=0;
		root->left=root->right=NULL;
	}
	else
	{
		t1=root;
		t3=NULL;
		while((t1->left!=NULL || t1->right!=NULL) && t3!=t1)
		{
			t3=t1;
			while(i<t1->info && t1->left!=NULL)
				t1=t1->left;
			while(i>t1->info && t1->rthread==0 && t1->right!=NULL)
				t1=t1->right;
		}
/*		printf("%d",t1->info);
		getch(); */
		t2=(struct bst*)malloc(sizeof(struct bst));
		t2->info=i;
		t2->left=t2->right=NULL;
		if(i<t1->info)
		{
			t1->left=t2;
			t2->right=t1;
			t2->rthread=1;
		}
		else
		{
			if(t1->right!=NULL)
			{
				t2->right=t1->right;
				t1->right=t2;
				t1->rthread=0;
				t2->rthread=1;
			}
			else
			{
				t1->right=t2;
				t2->rthread=0;
			}
		}
	}
	return root;
}
void inorder(struct bst *p)
{
	struct bst *q;
	do
	{
		q=NULL;
		while(p!=NULL)
		{
			q=p;
			p=p->left;
		}
		if(q!=NULL)
		{
			printf("%d\t",q->info);
			p=q->right;
			while(q->rthread && p!=NULL)
			{
				printf("%d\t",p->info);
				q=p;
				p=p->right;
			}
		}
	}while(q!=NULL);
}
void main()
{
	int ch,i;
	struct bst *root=NULL;
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