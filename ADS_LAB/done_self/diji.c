# include<stdio.h>
#include<stdlib.h>
	int n,**arr,*d,*p;
	//n hold number of nodes, arr hold the adji matrix, d hold the distance values and p holds the parent node.
int allcov()
{
	//to heck if all nodes have been visited or not.
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	if(arr[i][j]!=-1)
				{return -1;}
		}		
	}
	return 1;
}

int main()
{
	int i,j,count,curr; int min; FILE *ptr;
	ptr=fopen("diji.txt","r");
	fscanf(ptr,"%d",&n); 
	arr=(int**)malloc(sizeof(int)*n*n);
	d=(int*)malloc(sizeof(int)*n);
	p=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{	*(arr+i)=(int*)malloc(sizeof(int)*n);
		d[i]=99; //all distance infinity
		p[i]=-1; //no parents defined
	}

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
	printf("\nenter the source node::\t");
	scanf("%d",&curr); //enter the number between 1 to N;
	curr--;
	if(curr<0||curr>=n)
	{
		printf("\ncurrent node value does not exist");
		
		exit(1);
	}
	d[curr]=0; //source's distance =0;
	count=0;
	while(1)
	{
			printf("\ncount%d---current%d\n",count,curr);
			
		for(i=0;i<n;i++)
		{    
			if(arr[curr][i]==0)
				arr[curr][i]=-1;
			if(arr[curr][i]>0)
			{
				if((d[curr]+arr[curr][i])<d[i])
				{
					d[i]=d[curr]+arr[curr][i]; //chnage the distance if minimum
					p[i]=curr; //update parent
				}
			}
			arr[i][curr]=-1;	//the column of curr is=-1 so as to state visited.
		}
		
		for(i=0;i<n;i++)
		{
			if(arr[i][i]==0)
			{
					min=i;
		
			for(j=0;j<n;j++)
			{
				if((d[j]<d[min])&&(arr[j][j]==0))
				{		
					min=j;
				}	
						
				}
			break;
		}		
		}		
		curr=min;
		count++;  //if atter n^2 no result then graph has some incomplete info
		if(count==n*n)
			break;
		if(allcov()==1) //if all nodes visited
			break;
	}
if(count==n*n)
{printf("shorest path not possible");
exit(1);
}	
printf("the distances are\nNODE\t\t\tDISTANCE\t\tPARENT\n\n");
for(i=0;i<n;i++)
{
		printf("%d\t\t\t%d\t\t\t%d\n",i,d[i],p[i]);
}
return 1;	
}
