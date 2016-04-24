#include<stdio.h>
void swap(int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void display(int a,int b)
{
	printf("------------\n");
	printf(" | a | b |\n");
	printf("------------\n");
	printf(" | %d | %d |\n",a,b);
	printf("------------\n");
}
int main()
{
	int a,b;
	printf("Enter the first element:: ");
	scanf("%d",&a);
	printf("Enter the second element:: ");
	scanf("%d",&b);
	printf("The numbers before swap are:\n");
	display(a,b);
	swap(&a,&b);
	printf("The numbers after swap are:\n");
	display(a,b);
return 0;
}
