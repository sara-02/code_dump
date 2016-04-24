// sum of 2 numbers without using + operator.
#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter the first nubmer:: ");
	scanf("%d",&a);
	printf("Enter the second number:: ");
	scanf("%d",&b);
	a=a-~b-1;
	printf("Sum of the nubmers is:: %d\n",a);
return 0;	
}
