#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k,f,l,fault,count;int g;
	int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int pg[3][2]={{-1,-1},{-1,-1},{-1,-1}},pf=3;
	j=0; i=0; fault=0;
	count=sizeof(arr)/sizeof(int);
	while(i<count)
	{
		f=0;g=0;
		for(l=0;l<pf;l++)
		{
			if(pg[l][0]==arr[i])
			{		f=1;
				for(k=i+1;k<count;k++)
				{
					if(arr[k]==arr[i])
				{
						pg[l][1]=k;
						g=1;
						break;
				}
				}
				break;
			}
		}
		if(f==1)
		{
			if(g==0)
			pg[l][1]=99;
			i++;
		}
		else
		{
				l=0;
			if(j==pf)
		{
			f=0;
			for(k=0;k<pf;k++)
			{
				if(pg[k][1]>pg[f][1])
					f=k;
			}
			pg[f][0]=arr[i];
		}
		else
		{
		
			pg[j][0]=arr[i];
			f=j;
			j++;
			
		}
		for(k=i+1;k<count;k++)
		{
			if(arr[k]==arr[i])
			{
				pg[f][1]=k;
				l=1;
				break;
			}
		}
			if(l==0)
			pg[f][1]=99;
			
		i++;
		fault++;
		for(k=0;k<pf;k++)
			printf("|%d|.|%d|------->",pg[k][0],pg[k][1]);
	printf("\n");	
		}	
	}
	printf("count%d",count);
	printf("faults==%d",fault);
	return 0;
}
