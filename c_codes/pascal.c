//print pascal's triangle.
#include<stdio.h>
long fact(int p)
{
	long fc=1;
	while(p>1)
	{
		fc=fc*p;
		p--;
	}
return fc;
}
int main()
{
	int r,i,j; long temp;
	printf("Enter the nubmer of rows:: ");
	scanf("%d",&r);
	printf("\n");
	for(i=0;i<r;i++)
	{
		temp=fact(i);
		for(j=0;j<r-i+1;j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf("%ld ",temp/(fact(j)*fact(i-j)));
		printf("\n");
	}
return 0;
}
