#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int data;
    struct node *l;
    struct node *r;
}*root;

void find(int dataitem,struct node **parent,struct node **position)
{
    struct node *ptr,*prevptr;
    if(root==NULL)
    {
	*position=NULL;
	*parent=NULL;
	return;
    }
    if(dataitem==root->data)
    {
	*position=root;
	*parent=NULL;
	return;
    }
    if(dataitem<root->data)
	ptr=root->l;
    else
	    ptr=root->r;
    prevptr=root;
    while(ptr!=NULL)
    {
	 if(dataitem==ptr->data)
	 {
		 *position=ptr;
		     *parent=prevptr;
		     return;
	 }
	     prevptr=ptr;
	 if(dataitem<ptr->data)
			      ptr=ptr->l;
	 else
			      ptr=ptr->r;
     }
     *position=NULL;
     *parent=prevptr;
}
/*
void insert(int dataitem)
{
    struct node *temp,*parent,*position;
    find(dataitem,&parent,&position);
    if(position!=NULL)
    {
	printf("\t\tItem Already Present");
	return;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=dataitem;
    temp->l=NULL;
    temp->r=NULL;
    if(parent==NULL)
	root=temp;
    else if(dataitem<parent->data)
	    parent->l=temp;
	else
	    parent->r=temp;
}*/

void nokid(struct node *parent,struct node *position )
{
    if(parent==NULL)
	root=NULL;
    else if(position==parent->l)
	    parent->l=NULL;
	else
	    parent->r=NULL;
}

void onekid(struct node *parent,struct node *position)
{
    struct node *child;
    if(position->l!=NULL)
	child=position->l;
    else
	child=position->r;
    if(parent==NULL )
	    root=child;
    else if( position==parent->l)
	    parent->l=child;
	else
	    parent->r=child;
}

void twokids(struct node *parent,struct node *position)
{
    struct node *ptr,*prevptr,*suc,*parentsuc;
    prevptr=position;
    ptr=position->r;
    while(ptr->l!=NULL)
    {
	    prevptr=ptr;
	    ptr=ptr->l;
    }
    suc=ptr;
    parentsuc=prevptr;
    if(suc->l==NULL && suc->r==NULL)
	    nokid(parentsuc,suc);
    else
	    onekid(parentsuc,suc);
    if(parent==NULL)
	    root=suc;
    else if(position==parent->l)
	    parent->l=suc;
	else
	    parent->r=suc;
    suc->l=position->l;
    suc->r=position->r;
}

void del(int dataitem)
{
    struct node *parent,*position;
    if(root==NULL)
    {
	printf("\t\tTree empty");
	    return;
    }
    find(dataitem,&parent,&position);
    if(position==NULL)
    {
	printf("\t\tItem not present in tree");
	return;
    }
    if(position->l==NULL && position->r==NULL)
	nokid(parent,position);
    if((position->l!=NULL && position->r==NULL) || (position->l==NULL && position->r!=NULL) )
	onekid(parent,position);
    if(position->l!=NULL && position->r!=NULL)
	twokids(parent,position);
	printf("\t\tItem Deleted   :%d",position->data);
    free(position);
}

/*void preorder(struct node *ptr)
{
    if(root==NULL)
    {
	      printf("\n\t\t\tTree Empty");
	      return;
    }
    if(ptr!=NULL)
    {
	      printf("%d  ",ptr->data);
	      preorder(ptr->l);
	      preorder(ptr->r);
    }
}

void inorder(struct node *ptr)
{
    if(root==NULL)
    {
	     printf("\n\t\t\tTree Empty");
	     return;
    }
    if(ptr!=NULL)
    {
	     inorder(ptr->l);
	 printf("%d  ",ptr->data);
	 inorder(ptr->r);
    }
}

void postorder(struct node *ptr)
{
    if(root==NULL)
    {
	printf("\n\t\t\tTree Empty");
	return;
    }
    if(ptr!=NULL)
    {
	postorder(ptr->l);
	postorder(ptr->r);
	printf("%d  ",ptr->data);
    }
}
/*
void print_tree(struct node *ri,int m)
{
	int i;
	if(!ri)
	{
		return;
	}
	print_tree(ri->r,m+1);
	for(i=0;i<m;++i)
	{
		printf(" ");
	}
	printf("%d\n",ri->data);
	print_tree(ri->l,m+1);
} 
*                    */
/*int main()
{
    int choice,nodevalue,choice1;
    root=NULL;
    while(1)
    {
	printf("\n");
	printf("\tBinary Search Tree\n");
	printf("\t1.Insert\n");
	printf("\t2.Delete\n");
	printf("\t3.Traversals\n");
	printf("\t4.Quit\n");
	printf("\tEnter your choice :");
	fflush(stdin);
	scanf("%d",&choice);
	    switch(choice)
	    {
	     case 1:
	      printf("\tEnter the number to be inserted : ");
		  scanf("%d",&nodevalue);
	      insert(nodevalue);
	      break;
	     case 2:
		  printf("\tEnter the number to be deleted : ");
		  scanf("%d",&nodevalue);
		  del(nodevalue);
		  break;
	 case 3:
	      printf("\tTraversals\n");
	      printf("\t1.Preoreder Traversal\n");
	      printf("\t2.Inorder Traversal\n");
	      printf("\t3.Postorder Traversal\n");
	      printf("\t4.All Traversls\n");
	      printf("\tEnter your Choice :");
	      scanf("%d",&choice1);
	      switch(choice1)
	      {
		case 1:
		       printf("\nPreOrder Traversal:\n");
		       preorder(root);
		       break;
		case 2:
		       printf("\nInorder Traversal:\n");
		       inorder(root);
		       break;
		case 3:
		       printf("\nPostOrder Traversal:\n");
			   postorder(root);
		       break;
	      /*	case 4:
			printf("TREE!!!!:-)");
				print_tree(root,0);
				break;   */
		default:
			printf("\nPreOrder Traversal:\n");
			preorder(root);
			printf("\nInorder Traversal:\n");
			    inorder(root);
			printf("\nPostOrder Traversal:\n");
			    postorder(root);
	      }
	      break;
	 case 4:
	      printf("\tExiting...");
	      getch();
		  exit(0);
	 default:
	      printf("\tWrong choice\n");
	}
    }
    return 0;
}*/
