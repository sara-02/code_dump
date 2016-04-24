# include<stdio.h>
#include<stdlib.h>

int main()
{
	//int a[4][4]={{0,1,1,0},{0,0,1,1},{0,0,0,0},{0,0,1,0}};
	int **a,n,i,j,c,flag;
	FILE *ptr;
	ptr=fopen("topo.txt","r");
	if(ptr==NULL)
	{
		printf("Error\n");
		exit(1);
	}
	fscanf(ptr,"%d",&n);
	a=(int**)malloc(sizeof(int)*n*n);
	for(i=0;i<n;i++)
	*(a+i)=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
				fscanf(ptr,"%d",&a[i][j]);
		}
	}
	 c=0,i=0,j=0,flag=0;
	while(c!=n)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(a[j][i]!=0)
			{
				flag=1;break;
			}
			
		}
		if(flag==0)
		{
			for(j=0;j<n;j++)
			{
				a[j][i]=-1;
				if(a[i][j]==1)
					a[i][j]=0;
					
			}
			c++;
			printf("%d-->",i+1);
		}
		i++;
		if(i==n)
			i=0;
	}
	printf("\n");
	return 0;
}
