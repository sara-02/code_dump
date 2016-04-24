// 	Implementation Of Binary Search Tree using Linked List and Recursion

//	Header Files
#include<stdio.h>

//	Structure for a Node
struct BT
{
	int data;
	struct BT *right,*left;
};

//	Inserting The Nodes of The Tree
void insert(struct BT **ptr,int d)
{
	if((*ptr)==NULL)
	{
		(*ptr)=(struct BT *)malloc(sizeof(struct BT));
		(*ptr)->data=d;
		(*ptr)->left=(*ptr)->right=NULL;
	}

	else
	{
		if((*ptr)->data>d)
		insert(&((*ptr)->left),d);

		else
		insert(&((*ptr)->right),d);
	}
return ;
}

//	Searching a Node
int search(struct BT *ptr,int no)
{
	if(ptr==NULL)
	return(0);

	if(ptr->data==no)
	return(1);

	if(ptr->data>no)
	return(search(ptr->left,no));

	else
	return(search(ptr->right,no));
}

//	Inorder Traversal
void inorder(struct BT *ptr)
{
	if(ptr==NULL)
	return;

	else
	{
		inorder(ptr->left);
		printf("\t%d",ptr->data);
		inorder(ptr->right);
	}
}

//	Preorder Traversal
void preorder(struct BT	*ptr)
{
	if(ptr==NULL)
	return;

	else
	{
		printf("\t%d",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

//	Postorder Traversal
void postorder(struct BT *ptr)
{
	if(ptr==NULL)
	return;

	else
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("\t%d",ptr->data);
	}
}

void main()
{

    struct BT *root;        //Pointer to a Structure
    int ch,d,no,f;
    root=NULL;
    m:
    clrscr();
		printf("\n\t\t\t* Binary Search Tree *\n\n");
		printf("\t\t\t1.Insert\n\
			2.Search\n\
			3.Inorder\n\
			4.Preorder\n\
			5.Postorder\n\
			6.Sorted Order\n\
			7.Exit\n\
			Enter the choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("Enter the data:");
			scanf("%d",&d);
			insert(&root,d);
			printf("Node Successfully Inserted..");
			break;
		case 2:
			printf("Enter the node:");
			scanf("%d",&no);
			f=search(root,no);

			if(f==0)
			printf("Node is not present");
			else
			printf("Node is present");
			break;
		case 3:
			printf("\nInorder Traversal gives :\n");
			inorder(root);
			break;
		case 4:
			printf("\nPreorder Traversal gives :\n");
			preorder(root);
			break;
		case 5:
			printf("\nPostorder Traversal gives :\n");
			postorder(root);
			break;
		case 6:
			printf("\nSorted Order is :\n");
			inorder(root);
			break;
		case 7:
			exit(0);
		default:
			printf("Wrong Option Entered..Enter Again");
			break;

		}
      getch();
      goto m;

}