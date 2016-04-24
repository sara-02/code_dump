//print the reverse of a number
#include<stdio.h>
int main()
{
	int number,reverse=0;
	printf("Enter the number::");
	scanf("%d",&number);
	while(number>0)
	{
		reverse=reverse*10+(number%10);
		number=number/10;
	}
	printf("The reverse is:: %d\n",reverse);
return 0;
}
