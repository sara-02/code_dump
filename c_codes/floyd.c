// print floyd's triangle.
#include<stdio.h>
int main()
{
	int i,j,t=1,r;
	printf("Enter the number of rows::");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",t);
			t++;
		}
		printf("\n");
	}
return 0;	
}

