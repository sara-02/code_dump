#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,k,n,x,u,v,small,smallest,pos,total,weight[10][10],visited[10],parent[10];
	FILE*f;

	f=fopen("vertex.txt","r+");
	clrscr();
	fscanf(f,"%d",&n);

	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	  fscanf(f,"%d",&weight[i][j]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\t%d",weight[i][j]);
		}
		printf("\n");
	}

	for(i=1;i<=n;i++)
	{
		parent[i]=-1;
		visited[i]=0;
	}

	x=1;
	parent[x]=1;
	visited[x]=1;

	for(i=2;i<=n;i++)
	{
		k=1;
		smallest=9999;
		while(parent[k]!=-1)
		{
			small=999;
			for(j=1;j<=n;j++)
			{
				if(weight[k][j]>0&&visited[j]==0&&weight[k][j]<small)
				{
					small=weight[k][j];
					pos=j;
					u=parent[k];
				}
			}

			if(small<=smallest)
			{
				smallest=small;
				v=pos;
			}

			k++;
		}

		total+=smallest;
		parent[x++]=v;
		visited[v]=1;
		printf("\n(%c,%c)",u+'a'-1,v+'a'-1);
	}

	printf("Weight of the Minimum Spanning Tree : %d",total);
	getch();

}