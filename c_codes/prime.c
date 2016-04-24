//check if a number is prime or not.
#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int i,t=(int)sqrt(n);
	if(n<2)
		return 0;
	else if(n==2)
		return 1;
	else if(n%2==0)
		return 0;
	else
	{
		for(i=3;i<t;i+=2)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}

int main()
{
	int n;
	printf("Enter the number:: ");
	scanf("%d",&n);
	if(prime(n))
		printf("Number is prime\n");
	else
		printf("Number is NOT prime\n");
return 0;		
}
