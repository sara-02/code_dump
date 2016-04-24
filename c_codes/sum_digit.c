//sum of digits of a number
#include<stdio.h>
int main()
{
	int number,sum=0;
	printf("Enter the number::");
	scanf("%d",&number);
	while(number>0)
	{
		sum=sum+(number%10);
		number=number/10;
	}
	printf("The sum= %d\n",sum);
return 0;
}
