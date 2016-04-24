#include<stdio.h>
#include<stdlib.h>
char **mat;
int *pos;int r,c;long int count; int n;
	
void disp()//to disp the first two solutions
{
	int i,j;
	printf("\n\nONE OF THE SOLUTION IS\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			{
				printf("|%c|",mat[i][j]);
			}
		printf("\n");		
		for(j=1;j<=n;j++)
			{
				printf("==");
			}
		printf("\n");
	}

}

int check_fnc(int r,int c)
{
 	 int i=1;int j=1;
	for(i=1;i<=r-1;i++)
		{	// to check the colums above
			if(mat[i][c]=='q')
			return 0;
		}

	 i=r-1;j=c+1;
	 while((i>=1)&&(j<=n))
	{       //to check upper right digonal
		if(mat[i][j]=='q')
			return 0;
		i--;
		j++;

		}
	i=r-1;j=c-1;
	while((i>=1) &&(j>=1))
	{      
		//to check upper left diagonal
		if(mat[i][j]=='q')
			return 0;
		i--;j--;
	}

	return 1;

}


int check_count()
{
  int c=0; int i,j;  // to check if complete square has been formed or not
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]=='q')
				c++;
		}
	}
	if(c==n)
		      	return 1;
	       
	else
		return 0;

}




void counting()
{
	if(r==1&&c==(n+1))
	{	// all combinations exhausted
		printf("THE NUMBER OF SOLUTIONS ARE:   %ld\n",count);
		exit(1);
	}
	if(r==n+1)
	{	//a possible solution reached
		r=n;
		c=pos[r];
		mat[r][c]=' ';
		c=c+1;
		counting();

	}
	if((c<=n)&&(check_fnc(r,c)) )
	{
		mat[r][c]='q'; //to check the postion in current row
		if(check_count())
			{
				count++;
				if(count==1||count==2)
					disp();
			}
		pos[r]=c;
		r=r+1;
		c=1;
		counting();

	}
	else
	{
	    if(c<n)
	    {
		c++;
		counting();
	    }
	    else
	    {  // to move from curent row to the previous one and rearranging the previous one 
		c=pos[r];
		mat[r][c]=' ';
		r=r-1;
		c=pos[r];
		mat[r][c]=' ';
		c=c+1;
		counting();
	    }
	}

}

int main()
{
	int i,j;
	printf("enter the value of n\n");
	scanf("%d",&n);
	mat=(char**)malloc(sizeof(char)*n*n);
	for(i=1;i<=n;i++)
	*(mat+i)=(char*)malloc(sizeof(char)*n);

	pos=(int*)malloc(sizeof(int)*n);
	
	for(i=1;i<=n;i++) //intialize
	{
		for(j=1;j<=n;j++)
			{
				mat[i][j]=' ';
			}
		pos[i]=0;
	}

	r=1;c=1;
	counting();//function to count the number of solutions
return 1;
}
