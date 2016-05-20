#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#define MAX 10

int main()
{
  FILE *fp;
  int row,col,i,j,edges,nodes;
  char ch; int c;
  int mat[MAX][MAX];

  //clrscr();

  fp=fopen("matrix.txt","r");

  row=col=0;

  while(fscanf(fp,"%c",&ch)!=EOF)
  {
     if(ch==' ')
       col++;
     else if(ch=='\n')
     {
       row++;
       c=col;
       col=0;
	
     }
     else if(ch=='1')
       mat[row][col]=1;
     else if(ch=='0')
	mat[row][col]=0;		
   }

fclose(fp);

printf("\nThe given adjacency matrix is : \n");

for(i=0;i<row;i++)
{
  for(j=0;j<=c;j++)
    printf("%d\t",mat[i][j]);
  printf("\n");
}

nodes=row;
printf("\nNumber of nodes = %d",nodes);

edges=0;

for(i=0;i<row;i++)
{
  for(j=0;j<=c;j++)
  {
    if(mat[i][j]==1)
      edges++;
  }
}
printf("\nNumber of edges = %d",edges);
printf("\nCyclometic Complexity of graph%d\n",edges-nodes+2);

return 0;

}

