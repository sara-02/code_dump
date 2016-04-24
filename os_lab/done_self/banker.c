# include<stdio.h>
#include<stdlib.h>


int main()
{
	int all[10][10],max[10][10],need[10][10];
	int avl[10]; int fin[10]; int req[10];int pro;
	int m,n,d,i,j; int num; int flag; int k=0; int ord[10];
	printf("enter the number of resources\n");
	scanf("%d",&m);
	printf("enter the number of processes\n");
	scanf("%d",&n);
	//avl=(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
	{
		printf("\n enter the availability of resource Ri::\t");
		scanf("%d",&avl[i]);
	}
	
		
	/*max=(int**)malloc(sizeof(int)*n*m);
	for(i=0;i<n;i++)
	{
		*(max+i)=(int*)malloc(sizeof(int)*m);
		
	}
	
	all=(int**)malloc(sizeof(int)*n*m);
	for(i=0;i<n;i++)
	{
		*(all+i)=(int*)malloc(sizeof(int)*m);
		
	}e
	
	need=(int **)malloc(sizeof(int)*n*m);
	for(i=0;i<n;i++)
	{
		*(need+i)=(int*)malloc(sizeof(int)*m);
		
	}*/
	FILE *ptr=fopen("banker.txt","r");
	i=0;
	if(ptr==NULL)
	{
		printf("Error opening\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(ptr,"%d",&d);
			all[i][j]=d;
		}
		for(j=0;j<m;j++)
		{
			fscanf(ptr,"%d",&d);
			max[i][j]=d;
			need[i][j]=d-all[i][j];
		}
		fin[i]=-1;
	}
	printf("\nEnter the requesting process");
	scanf("%d",&pro);
	pro--;
	if(pro<0 || pro>n)
	{
		printf("process not listed");
		exit(1);
	}
	j=pro;
	printf("\nenter the request");
	for(i=0;i<m;i++)
	{
			scanf("%d",&req[i]);
			if(req[i]>avl[i])
			{
				printf("req greater than avl");
		      exit(1);
			}
			else if(req[i]>need[pro][i])
			{
				printf("req greater than need");
				exit(1);
			}
			avl[i]-=req[i];
			need[pro][i]-=req[i];
			all[pro][i]+=req[i];
	}	
	printf("process\t\t allocation \t\t max\t\t\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("|%d| ",all[i][j]);
			printf("\t");
		for(j=0;j<m;j++)
			printf("--%d-- ",max[i][j]);	printf("\t");
		for(j=0;j<m;j++)
			printf("==%d==",need[i][j]);		
		printf("\n");	
	}
	num=0;
	i=0;
	while(num<n*n)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(fin[j]!=-1)
			flag++;
		}
		if(flag==n)
		{
			break;
		}
		flag=0;
		if(fin[i]==-1)
		{
			for(j=0;j<m;j++)
			{
				if(need[i][j]>avl[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				for(j=0;j<m;j++)
					avl[j]+=all[i][j];
				fin[i]=1;
				ord[k]=i;
				k++;
			}
		}
		i++;
		if(i==n)
			i=0;
		num++;	
	}
	if(flag==n)
	{printf("no de");
		for(i=0;i<n;i++)
			printf("%d-->",ord[i]);
	}
	else
	printf("dead");
	return 0;
}
