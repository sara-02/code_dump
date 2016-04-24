#include<stdio.h>
#include<stdlib.h>
int queue[100]; int front,rear;
void push(int val)
{
	if(front==-1&&rear==-1)
	{
		front=0;rear=0;
		queue[rear]=val;
	}
	else
	{
		rear=rear+1;
		queue[rear]=val;
	}
}
void pop()
{
		front=front+1;
}
int main()
{
	int i,j,curr,count,n;
	int **arr;
	FILE *ptr;
	ptr=fopen("diji.txt","r");
	fscanf(ptr,"%d",&n);
	arr=(int**)malloc(sizeof(int)*n*n);
	for(i=0;i<n;i++)
		*(arr+i)=(int*)malloc(sizeof(int)*n);
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			{
				fscanf(ptr,"%d",&arr[i][j]);
			}
	}
	fclose(ptr);
	front=-1; rear=-1;
	//disp
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d   ",arr[i][j]);
		printf("\n");	
	}
	count=0;	
	printf("\nenter the source::\t");
	scanf("%d",&curr);
	curr--;
	push(curr);
	while(1)
	{	printf("%c",65+curr);
		for(i=0;i<n;i++)
			arr[i][curr]=0;
		for(i=0;i<n;i++)
		{
			if(arr[curr][i]>0)
			{
				push(i);
				for(j=0;j<n;j++)
					arr[j][i]=0;
			}
		}
		pop();
		if(front>rear)
			exit(1);
		curr=queue[front];
		count++;
		if(count==n*n)
				exit(1);
		
	}
	return 0;	
}
