#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,j,k,f,fault,count;
	int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int pg[3][2]={{-1,-1},{-1,-1},{-1,-1}},pf=3;
	j=0; i=0; fault=0;
	count=sizeof(arr)/sizeof(int);
	while(i<count)
	{
		f=0;
		for(k=0;k<pf;k++)
		{
			if(pg[k][0]==arr[i])
			{
				f=1;break;
			}
		}
		if(f==1)
		{
			pg[k][1]=i;
			i++;
		}
		else
		{
			if(j==pf)
			{	f=0;
				for(k=0;k<pf;k++)
				{
					if(pg[k][1]<pg[f][1])
						f=k;
				}
					pg[f][0]=arr[i];
					pg[f][1]=i;
			}
			else
			{
					pg[j][0]=arr[i];
					pg[j][1]=i;
					j++;
			}
		i++;
		fault++;
		for(k=0;k<pf;k++)
			printf("|%d|.|%d|------->",pg[k][0],pg[k][1]);
	printf("\n");	
		}	
	}
	printf("count%d",count);
	printf("faults==%d\n",fault);
	printf("%d",abs(2-3));
	return 0;
}
