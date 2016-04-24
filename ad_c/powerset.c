#include <stdio.h>
#include <math.h>
#include<stdlib.h>
 int *a;int n;
void printPowerSet()
{
    
     int tot= pow(2,n);
	printf("{#}");
    int counter, j; int count =0; 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter <tot; counter++)
    {
      for(j = 0; j<n; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
           printf("%d",a[j]);
       }
       printf("\n");
	count++;
    }
 printf("|%d|\n",count);
}
 
/*Driver program to test printPowerSet*/
int main()
{ int i;
	printf("enter the number of elements::");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		a[i]=i+1;
	printPowerSet();
   

    return 0;
}
