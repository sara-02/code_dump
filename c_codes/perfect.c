//check if number is perfect or not. A number is perfect if sum of its divisor(excluding number)=number
#include <stdio.h>
int main()
{
	int number,sum=0, i=1;
	printf("Enter the number:: ");
	scanf("%d",&number);
	for(i=2;i<number;i++)
		if(number%i==0)
			sum+=i;
	if(number==(sum+1))
		printf("\nThe number is perfect\n");
	else
		printf("\nThe number is NOT perfect\n");
return 0;
}
