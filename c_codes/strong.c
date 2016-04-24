/*
	check if a number is strong or not. 
	A number is strong is sum of factorials of digits=number itself.
	EG: 145=1!+4!+5!=1+24+120=145
*/	
#include<stdio.h>
int fact(int p)
{
	int fc=1;
	while(p>1)
	{
		fc=fc*p;
		p--;
	}
return fc;	
}

int main()
{
	int number, n, sum=0;
	printf("Enter the number:: ");
	scanf("%d",&number);
	n=number;
	while(n>0)
	{
		sum=sum+fact(n%10);
		n=n/10;
	}
	if(sum==number)
		printf("Number is Strong\n");
	else
		printf("Number is NOT Strong\n");
return 0;
}
