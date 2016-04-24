#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	FILE *p1,*p2;time_t ty;
	int **a,**b;
	int m,n,i,j,k,l,count,occur=0,temp,r,s;

	srand((unsigned)time (&ty));
	printf("Enter the rows/columns for the bigger matrix:\n");
	scanf("%d",&n);
	printf("Enter the rows/columns for the smaller matrix:\n");
	scanf("%d",&m);
	p1=fopen("matrix1.txt","w");
	if(p1==NULL)
	{
		printf("Cannot open the file\n");
		
		exit(0);
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			temp=rand()%10;
			fprintf(p1,"%d ",temp);
		}
		fputc('\n',p1);
	}
	p2=fopen("matrix2.txt","w");
	if(p2==NULL)
	{
		printf("Cannot open the file\n");
		
		exit(0);
	}
	for(i=0;i<m;++i)
	{
		for(j=0;j<m;++j)
		{
			fprintf(p2,"%d ",rand()%10);
		}
		fputc('\n',p2);
	}
	fclose(p1);
	fclose(p2);

	a=(int **)malloc(sizeof(int)*n*n);
	for(i=0;i<n;i++)
		*(a+i)=(int *)malloc(sizeof(int)*n);

	b=(int **)malloc(sizeof(int)*m*m);
	for(i=0;i<m;i++)
		*(b+i)=(int *)malloc(sizeof(int)*m);

	p1=fopen("matrix1.txt","r");
	if(p1==NULL)
	{
		printf("Cannot open the file\n");
		
		exit(0);
	}
	printf("The first matrix is given as:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			fscanf(p1,"%d",&temp);
			a[i][j]=temp;
			printf("%d   ",a[i][j]);

		}
		printf("\n");
	}
	p2=fopen("matrix2.txt","r");
	if(p2==NULL)
	{
		printf("Cannot open the file\n");
		
		exit(0);
	}
	printf("The second matrix is given as:\n");
	for(i=0;i<m;++i)
	{
		for(j=0;j<m;++j)
		{
			fscanf(p2,"%d",&temp);
			b[i][j]=temp;
			printf("%d   ",b[i][j]);
		}
		printf("\n");

	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			r=i;
			s=j;
			count=0;
			for(k=0;k<m;++k)
			{
				for(l=0;l<m;++l)
				{

					if(a[r][s]==b[k][l])
					{
						++count;
						if(l<m)
						{
							++s;
						}
						else
						{
							++r;
							s=j;
						}
						if(count==m*m)
						{
							++occur;
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	printf("\nThe no of occurences are %d\n",occur);
}

