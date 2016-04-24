#include<stdio.h>
#include<stdlib.h>
int stack[100]; int top;
void push(int curr)
{
	top++;
	stack[top]=curr;
}
void pop()
{
	top--;
}
int main()
{
	int i,j,flag,curr,count,n;
	int **arr;
	FILE *ptr;
	top=-1;
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
	while(1)
	{	flag=0;
		push(curr);
		printf("%c",65+curr);
		for(i=0;i<n;i++)
					arr[i][curr]=0;
		for(i=0;i<n;i++)
		{
				if(arr[curr][i]>0)
				{
					flag=1;
					break;
				}
		}
		if(flag==0)
		{
			pop();
			if(top==-1)
				exit(1);
			else
			{
				curr=stack[top];
				count++;
			}
		}
		else
		{
			curr=i;
			count++;
		}
		if(count==n)
			exit(1);
		if(count==n*n)
					exit(1);
	}
	return 0;	
}
