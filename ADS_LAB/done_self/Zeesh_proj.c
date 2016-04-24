#include <stdio.h>
#include <stdlib.h>

void insert(int,int arr[]);
void delete(int,int arr[]);
void heapify_up(int,int arr[]);
void heapify_down(int,int arr[]);
void display(int arr[]);

int main()
{
	int heap[100],i=0,j=0,n,del_key=0,ins_num=0;

	for(i=0;i<100;i++)
		heap[i]=0;

	while(1)
	{

		printf("\n::ENTER 1 TO INSERT :: ENTER 2 TO DELETE :: ENTER 3  TO DISPLAY :: ENTER 0 TO EXIT::");
		scanf("%d",&n);

		switch(n)
			{

			case 1:printf("\nEnter the element to be inserted::");
					scanf("%d",&ins_num);
					insert(ins_num,heap);
					break;
			case 2:	
					if(heap[1]==0)
						{
							printf("\n::********************!!NOTHING TO DELETE!!******************::\n");
						}
					else
					{
					printf("\nEnter the key to be deleted::");
					scanf("%d",&del_key);
					delete(del_key,heap);
					}
					break;
			case 3:display(heap);
					break;
			case 0:exit(0);

		}
	}
}


void delete (int del,int arr[100])
{
	int i=1,f=0;
	
	
	while(arr[i]!=0)
	{
		if(arr[i]==del&&f==0)
		{
			f=i;
		}

		i++;

	}


	if(f==0)

	{
		printf("\n::*****************no such key*********************** ::\n");
	}
	else
	{
		arr[f]=arr[i-1];
		arr[i-1]=0;
		heapify_down(f,arr);
	}

}


void insert(int num,int arr[100])
{
	int i=1;

	while(arr[i]!=0)
	{
		i++;
	}
	
	arr[i]=num;
	heapify_up(i,arr);
}
void heapify_up(int root,int arr[100])
{
	int c=0;	
	while(root!=1)
	{
		if(arr[root/2]<arr[root])
		{
			c=arr[root/2];
			arr[root/2]=arr[root];
			arr[root]=c;
			root=root/2;
		}
	else
		break;
	}

}
void heapify_down(int root,int arr[100])
{
	int c=0;
	while(arr[root]!=0)
		{
			if((arr[root]<arr[2*root]&&arr[2*root]!=0)||(arr[root]<arr[2*root+1]&&arr[2*root+1]!=0))
			{
				if(arr[2*root]<arr[2*root+1])
				{
					c=arr[root];
					arr[root]=arr[2*root+1];
					arr[2*root+1]=c;
					root=2*root+1;
				}

				else
				{
					c=arr[root];
					arr[root]=arr[2*root];
					arr[2*root]=c;
					root=2*root;
				}
			}

			else
				break;
		}
}

void display(int arr[100])
{
	int root=1;
	if(arr[1]!=0)
	{
		printf("\n%d ",arr[root]);

		while(arr[root]!=0)
			{
				if(arr[2*root]!=0)
					printf("%d",arr[2*root]);

				if(arr[2*root+1]!=0)
					printf("%d",arr[2*root+1]);
				root++;
			}
	}

	else
		printf("\n::********************NOTHING TO DISPLAY***********************::\n");
}
