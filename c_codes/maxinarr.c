#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
	int *a, max,i,n;
	a=(int*)malloc(sizeof(int)*20);
	printf("Enter the number of elements:: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:: ");
		scanf("%d",&a[i]);
		if(i==0)
			max=a[0];
		else
		{
			if(a[i]>max)
				max=a[i];
		}
	}
	printf("The maximum element is::  %d\n",max);
return 0;
}
