#include<stdio.h>
int gcd(int m,int n)
{
  	
	 if(n>m)
		{
			printf("%d\t%d\n",m,n);
		return(gcd(n,m));
		}
	else if (n==m)
       		{
			printf("%d\t%d\n",m,n);
		return(m);
		}
	else
	 	{
			if(n==0)
				return m;
			printf("%d\t%d\n",m,n);
		return(gcd(n,m%n));
		}
}
int main()
{  	int a; int b;
  	printf("enter the first number\n");
	scanf("%d",&a);
	printf("enter the second number\n");
	scanf("%d",&b);
	printf("%d\n",gcd(a,b));
	return 1; 
}
