/*WAP to find the sum of all the nodes in a Binary search Tree.
 * Submitted by 12CSS-57 for Advanced DS LAB.
 * */
 
#include<stdio.h>
#include<stdlib.h>
//define the node structure.
struct node
{
	int val; //to store the number
	struct node *left;
	struct node *right;
}; struct node *head,*temp,*temp1;  // to store start and current pointer to node
int flag; int sum;

//inserting into the BST
int insert(int n)
{
	if(head==NULL) //inserting for the first time
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->val=n;
		head->left=NULL;
		head->right=NULL;
		temp=head;
		return 1; // returns 1 on successful insertion.
	}
	else if(temp==NULL)
	{ //when a new non duplicate node is to be inserted
		temp=(struct node*)malloc(sizeof(struct node));
		temp->val=n;
		temp->left=NULL;
		temp->right=NULL;
		if(flag==1) //insert as left child of parent node if flag is set
		{
			temp1->left=temp;
			return 1;
		}
		else
		{   //insert as right child of parent node
			temp1->right=temp;
			return 1;
		}
		//return 1 on successful insertion.
	}
	else if(n<temp->val)
	{
		//move to the left subtree.
		temp1=temp;
		temp=temp->left;
		flag=1; //flag=1 indicates that insertion will be the left of current node
		if(insert(n))
			return 1;
		else 
				return -1;	
		
	}
	else if(n>temp->val)
	{ 
		//move to the right subtree.
		temp1=temp;
		temp=temp->right;
		flag=0; //means that insertion will be the right of current node
		if(insert(n))
			return 1;
		else 
				return -1;	
	}
	else if(n==temp->val)
	{ 
		//if number already exits.
			return -1;
	}
	
} //insert 
//FIRST sum function.
void suminorder(struct node* temp)
{
	//use recursive inorder traversal to find the sum
		if(temp!=NULL)
		{
		suminorder(temp->left);
		printf("|%d|-->",temp->val);
		sum+=temp->val;
		suminorder(temp->right);
	}
}
//SECOND sum function.
void sumpreorder(struct node* temp)
{
	//use recursive preorder traversal to find the sum
	if(temp!=NULL)
		{
		printf("|%d|-->",temp->val);
		sum+=temp->val;
		sumpreorder(temp->left);
		sumpreorder(temp->right);
	}
}

//THIRD sum fucntion.
void sumpostorder(struct node* temp)
{
	//use recursive postorder traversal to find the sum
	if(temp!=NULL)
		{
		sumpostorder(temp->left);
		sumpostorder(temp->right);
		printf("|%d|-->",temp->val);
		sum+=temp->val;
	}
}

int main()
{
	int n,ch;
	head=NULL;
	//initalise head to NULL pointer.
	printf("\n---CHOICE MENU---\n1 Insert\n2 Print nodes and sum in INORDER\n3 Print nodes and sum in PREORDER\n4 Print nodes and sum in POSTORDER\n5 Exit------\n");
	while(1)
	{  //continues until user wishes to exit
		printf("\nEnter your choice\t::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: //insertion
					printf("\nenter the number to insert::\t");
					scanf("%d",&n);
					temp=head;
					temp1=head;
					break;
			case 2: //inorder
					if(head==NULL)
					{
						printf("\nTREE EMPTY.SUM=0");
					}
					else
					{
						temp=head;
						sum=0;
						printf("INORDER::\t");
						suminorder(temp);
						printf("\nSUM-->%d\n",sum);
						
					}
					break;
					
			case 3: //preorder
					if(head==NULL)
					{
						printf("\nTREE EMPTY.SUM=0");
					}
					else
					{
						temp=head;
						sum=0;
						printf("PREORDER::\t");
						sumpreorder(temp);
						printf("\nSUM-->%d\n",sum);
						
					}
					break;
					
			case 4:	//postorder	
					if(head==NULL)
					{
						printf("\nTREE EMPTY.SUM=0");
					}
					else
					{
						temp=head;
						sum=0;
						printf("POSTEORDER::\t");
						sumpostorder(temp);
						printf("\nSUM-->%d\n",sum);
						
					}
					break;
			case 5: exit(1);		
			default: printf("\nWrong choice");
					
				}//switch
		}//while
	}//main
