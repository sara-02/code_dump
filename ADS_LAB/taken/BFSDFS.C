#include<stdio.h>
#include<conio.h>

void main()
{
	int g[10][10],v[10],q[10],p[10],stk[10];
	char s,z;
        int flag=0,row=0,col=0,c,i,j,k=0,f=-1,r=-1,s1,top=-1;
	FILE *fp;
	clrscr();
	fp=fopen("graph.txt","r+");
	printf("\t\t* GRAPH TRAVERSAL *\n");
        printf("\t\t  ---------------");
	while(!feof(fp))
	{
		c=fgetc(fp);
		if(c!='\n')
			g[row][col++]=c-'0';
		else
		{
			row++;
			col=0;
		}
	}
	row++;
	col--;
        printf("\n* Adjacency Matrix *\n");
        printf("  ----------------\n");
	for(i=0;i<10;i++)
		q[i]=v[i]=0;
	for(i=0;i<row;i++,printf("\n"))
		for(j=0;j<col;j++)
			printf("%d\t",g[i][j]);
	printf("Enter the starting vertex : ");
	scanf("%c",&s);
	s1=s-'a';
	i=s1;
	q[++r]=i;
	f++;
	v[i]=1;

        printf("Enter the vertex to be searched : ");
        scanf("%s",&z);
        //printf("Check : %d",z);
	do
	{
		i=p[k++]=q[f++];
		for(j=0;j<col;j++)
			if(g[i][j]==1 && v[j]==0)
			{
				q[++r]=j;
				v[j]=1;
			}
		v[i]=2;
	}while(f<=r);

	printf("\nBreadth First Search gives : \n");
        for(i=0;i<k;i++)
        {
        	if((p[i]+'a')!=z)
        	printf("%c --> ",p[i]+'a');
                	else
                        {
			printf("%c",p[i]+'a');
                        flag=1;
                        printf("\nNode found at position %d in traversal\n",i+1);
                        break;
                        }
        }
        if(flag==0)
        printf("\nNode not found\n");

        for(i=0;i<10;i++)
	v[i]=0;
	i=s1;
	stk[++top]=i;
	v[i]=1;
	k=0;

	do
	{
		i=p[k++]=stk[top--];
		for(j=0;j<col;j++)
			if(g[i][j]==1 && v[j]==0)
			{
				stk[++top]=j;
				v[j]=1;
			}
		v[i]=2;
	}while(top!=-1);

	printf("\nDepth First Search gives : \n");
        for(i=0;i<k;i++)
        {
        	if((p[i]+'a')!=z)
        	printf("%c --> ",p[i]+'a');
                	else
                        {
			printf("%c",p[i]+'a');
                        flag=1;
                        printf("\nNode found at position %d in traversal\n",i+1);
                        break;
                        }
        }
        if(flag==0)
        printf("\nNode not found\n");
getch();
}