#include<stdio.h>
void main()
{
	int l,i=0,n=0,flag=0,k=0,j,burst[10],min,arr[10],minb=0,exe[10],seq[10];
	char name[10][3];
	float wait=0,time=0;
	FILE *fp;
	fp=fopen("process","r+");
	while(fscanf(fp,"%s%d%d",name[n],&burst[n],&arr[n])!=EOF)
	{
		n++;
	}
	printf("\n\n\n\nProcess\tBurst\tArrival\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\n",name[i],burst[i],arr[i]);
		exe[i]=0;
	}
	min=arr[0];
	j=0;
	while(k<n)
	{
		l=0;
		for(i=0;i<n;i++)
		{
			if(exe[i]==0 && arr[i]<=min && flag==0)
			{
				min=arr[i]; 
				j=i;
			}
			else if(exe[i]==0  && time>=arr[i] && flag==1)
			{
				if(l==0)
				{
					minb=burst[i];
					j=i;
					l++;
				}
				else if(burst[i]<=minb)
				{
					j=i;
				}
			}
		}
		seq[k]=j;
		wait+=time-arr[j];
		time+=burst[j];
		exe[j]=1;
		k++;
		flag=1;
	}
	printf("\n\n\n\n\n\n\n GC Chart \n\n\n");
	for(i=0;i<5*n;i++)
		printf("-");
	printf("\n|");
	for(i=0;i<n;i++)
	{
		j=seq[i];
		printf("%s  |",name[j]);
	}
	printf("\n");
	for(i=0;i<5*n;i++)
		printf("-");
	l=0;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d    ",l);
		j=seq[i];
		l+=burst[j];
	}	
	printf("%d\n",l);
	printf("\n\n\nAverage waiting time is %f",wait/n);
	for(i=0;i<n;i++)
		wait+=burst[i];
	printf("\n\nAverage Turnaround time is %f\n\n\n\n",wait/n);
}
