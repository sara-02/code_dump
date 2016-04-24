#include<stdio.h>
#include<conio.h>

#define PERM 1
#define TEMP 0
#define infinity 9999

struct node
{
	int pre;
	int dist;
	int status;
};

int findShortestPath(int s,int d,int path[],int weight[][10],int*len,int n)
{
	struct node node[10];
	int i,current,min,u,v,count=0,newdist;
	*len=0;

	for(i=1;i<=n;i++)
	{
		node[i].pre=0;
		node[i].status=TEMP;
		node[i].dist=infinity;
	}

	node[s].pre=0;
	node[s].dist=0;
	node[s].status=PERM;

	current=s;

	while(current!=d)
	{
		for(i=1;i<=n;i++)
		{
			if(weight[current][i]>0&&node[i].status==TEMP)
			{
				newdist=node[current].dist+weight[current][i];
				if(newdist<node[i].dist)
				{
					node[i].dist=newdist;
					node[i].pre=current;
				}
			}
		}

		current=0;
		min=infinity;
		for(i=1;i<=n;i++)
		{
			if(node[i].status==TEMP&&node[i].dist<min)
			{
				min=node[i].dist;
				current=i;
			}
		}

		if(current==0)
		 return 0;

		node[current].status=PERM;
	}

	while(current!=0)
	{
		count++;
		path[count]=current;
		current=node[current].pre;
	}

	for(i=count;i>1;i--)
	{
		u=path[i];
		v=path[i-1];
		*len+=weight[u][v];
	}
	return count;
}


void main()
{
	int i,j,n,weight[10][10],s,d,len,count,path[20];
	char ch1,ch2;
	FILE*f;

	f=fopen("vertex.txt","r+");
	fscanf(f,"%d",&n);

	clrscr();

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			fscanf(f,"%d",&weight[i][j]);
		}
	}

	printf("\nWeight Matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\t%d",weight[i][j]);
		}
		printf("\n");
	}

	printf("Enter ther source node : ");
	scanf("%c",&ch1);
	s=ch1-'a'+1;
	fflush(stdin);
	printf("Enter the destination node : ");
	scanf("%c",&ch2);
	d=ch2-'a'+1;

	count=findShortestPath(s,d,path,weight,&len,n);

	if(len>0)
	{
		printf("\n\nShortest Path between %c (SOURCE) and %c (DESTINATION) is : ",s+'a'-1,d+'a'-1);
		for(i=count;i>=1;i--)
		{
			printf(" %c",path[i]+'a'-1);
		}
		printf("\n\nLength of the shortest path is : %d",len);
	}
	else
	 printf("\n\nNo Path exists between the nodes %c and %c",s+'a'-1,d+'a'-1);
	getch();
}