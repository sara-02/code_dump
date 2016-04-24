#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//magic square for odd and multiples of four
 int **mat;int n; //mat store the magic square and n store the size
void odd()
{        int i=1;int r,c,p,q;
		//go  up and right else down
	 i=1;
	 r=1;
	 c=n/2+1;
	 while(i<=(n*n))
	 {
		mat[r][c]=i;
		p=r;
		q=c;
		r--;
		c++;
		if(r==0)
			r=n;
		if(c==(n+1))
			c=1;
		if(mat[r][c]!=0)
		{
		  r=p+1;
		  c=q;
		}
		i++;
	}
}
void even1() //for multiples of 4
{       int p,i,j,k;
	p=n/4;
	//border n/4 times thick stores -1 and centre box stores 0
   /*   for(i=p+1;i<=(n-p);i++)
	{
		for(j=1;j<=p;j++)
			{
				mat[i][j]=-1;
				mat[j][i]=-1;
			}
		for(k=n;k>(n-p);k--)
			{	mat[i][k]=-1;
				mat[k][i]=-1;
			}
	}*/
		mat[1][1]=-1;
		mat[n][n]=-1;
		mat[1][n]=-1;
		mat[n][1]=-1;
	for(i=p+1;i<=(n-p);i++)
	{
		for(j=p+1;j<=n-p;j++)
		{
			mat[i][j]=-1;
		}
	}

    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)	
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}

      k=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]==-1)
				{mat[i][j]=k;}
			k++;
		}
		
	}
	k--;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]==0)
				{mat[i][j]=k;}

			k--;
		}
		
	}
}
void even2()//for 4n+2 types
{
	
	   int i=1; int j=1; int r,c,p,q;int a;int k;
        a=n/2;
	k=n/4;
	r=1;
	c=k+1;
	i=1;
	while(i<=(a*a))//for 1st block
	{
		mat[r][c]=i;
		p=r;
		q=c;
		r=r-1;
		c=c+1;
		if(r==0)
			r=a;
		if(c==a+1)
			c=1;
		if(mat[r][c]==0)
			i++;
			
		else
			{
				r=p+1;
				c=q;
				i++;
			}
	}
	r=a+1;
	c=(2+3*n)/4;
	while(i<=(a*a+a*a))//for 4th block
	{
		mat[r][c]=i;
		p=r;
		q=c;
		r=r-1;;
		c=c+1;
		if(r==a)
			r=n;
		if(c==n+1)
			c=a+1;
		if(mat[r][c]==0)
			i++;
		else
		{
			r=p+1;
			c=q;
			i++;
		}	
	}
	r=1;
	c=(2+3*n)/4;
	while(i<=(a*a+a*a+a*a))//for 2nd block
	{
		mat[r][c]=i;
		p=r;
		q=c;
		r=r-1;
		c=c+1;
		if(r==0)
			r=a;
		if(c==n+1)
			c=a+1;
		if(mat[r][c]==0)
			i++;
		else
		{
			r=p+1;
			c=q;
			i++;
		}
	
	}
	r=a+1;
	c=k+1;
	while(i<=(a*a+a*a+a*a+a*a))//for 3rd block
	{
		mat[r][c]=i;
		p=r;
		q=c;
		r=r-1;
		c=c+1;
		if(r==a)
			r=n;
		if(c==a+1)
			c=1;
		if(mat[r][c]==0)
			i++;
		else
		{
			r=p+1;
			c=q;
			i++;
		}
		
	}
        k=n/4;
	j=1; //for the lhs columns
        while(j<=k)
        {
	 	p=1;
		q=n;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
                }
		p=1;
		q=a;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
		}
		p=a+1;
		q=n;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
		}

		j++;
	}
	
	p=1;
	q=n;
	k=n/4-1;
	j=n;
	r=1;
	//for the rhs columns
	while((r<=k))
	{
		p=1;
		q=n;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
                }
		p=1;
		q=a;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
		}
		p=a+1;
		q=n;
		while(p<=q)
		{
			i=mat[p][j];
			mat[p][j]=mat[q][j];
			mat[q][j]=i;
			p++;q--;
		}

		j--;
		r++;		
	}
	//for the centre tiles of 1st and 3rd
	k=n/4;
	i=mat[a/2+1][1];
	mat[a/2+1][1]=mat[a/2+a+1][1];
	mat[a/2+a+1][1]=i;
	i=mat[a/2+1][k+1];
	mat[a/2+1][k+1]=mat[a/2+a+1][k+1];
	mat[a/2+a+1][k+1]=i;
	
}
int check()
{
	int i,j,sum1=0,sum2=0;
	for(i=1;i<=n;i++)
		sum1+=mat[i][i];
	j=n;
	for(i=1;i<=n;i++)
	{
		sum2+=mat[i][j];
		j--;
	}
	if(sum1!=sum2)
		return 0;
	sum1=0;
	for(i=1;i<=n;i++)
	{	sum1=0;
		for(j=1;j<=n;j++)
		{
			sum1+=mat[i][j];
		}
		if(sum1!=sum2)
			return 0;	
	}
	sum1=0;
	for(i=1;i<=n;i++)
	{
		sum1=0;
		for(j=1;j<=n;j++)
		{
			sum1+=mat[j][i];
		}
		if(sum1!=sum2)
			return 0;
	
			
	}
	return 1;
}

int main()
{

	  int i,j; int sum, m;
	sum=0;
	printf("ENTER THE VALUE OF N\n");
      scanf("%d",&n);
      mat=(int**)malloc(sizeof(int)*n*n);
      for(i=1;i<=n;i++)
      *(mat+i)=(int*)malloc(sizeof(int)*n);
       for(i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{	mat[i][j]=0;
			}
		}
	  if(n%2==1)
		 odd();
	  else if(n%4==0)
		even1();
	 else if(n%4==2)
		even2();
	  else
	      { printf("WRONG CHOICE\n");
		exit(1);
		}
	
	m=n*(n*n+1)/2;
		if(!check())
			{     	printf("MAGIC SQUARE NOT POSSIBLE\n");
				exit(1);
			}
	printf("THE MAGIC MATRIX IS\n");
	for(i=1;i<=n;i++)
		{
		   for (j=1;j<=n;j++)
			{
				printf("%d\t",mat[i][j]);
				
			}
		printf("\n");
		}
		printf("\nTHE MAGIC NUMBER IS: %d\n\n\n",m);
return 1;

}
