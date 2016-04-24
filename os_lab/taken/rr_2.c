#include<stdio.h>
void main()
{
	int burst[10],ts,n=0,i=0,j=0,k=0,l=0,time=0,exe[30],sav[30],waiting[10];
	float wait=0,time1=0;
	char name[10][3];
	FILE *fp;
	fp=fopen("process","r+");
	while(fscanf(fp,"%s%d",name[n],&burst[n])!=EOF)
		n++;
	printf("Enter time slice\n");
	scanf("%d",&ts);
	printf("\n\n\n\n\n\n\nProcess\tBurst Time\n");
	for(i=0;i<n;i++)
		printf("%s\t%d\n",name[i],burst[i]);
	for(i=0;i<30;i++)
		exe[i]=0;
	for(i=0;i<n;i++)
		waiting[i]=0;
	i=0;
	printf("\n\n\n\n\n\n\n");
	while(k<n)
	{
		if(burst[i]>ts)
		{
			sav[l++]=time;
			time+=ts;
			burst[i]-=ts;
			for(j=0;j<n;j++)
				if(j!=i && exe[j]==0)
					waiting[i]+=ts;
			printf("%s\t",name[i]);
		}
		else if(burst[i]==ts)
		{
			sav[l++]=time;
			time+=ts;
			burst[i]-=ts;
			for(j=0;j<n;j++)
				if(j!=i && exe[j]==0)
					waiting[i]+=ts;
			exe[i]=1;
			k++;
			printf("%s\t",name[i]);
		}
		else if(burst[i]<ts && burst[i]>0)
		{
			sav[l++]=time;
			time+=burst[i];
			for(j=0;j<n;j++)
				if(j!=i && exe[j]==0)
					waiting[i]+=burst[i];
			burst[i]-=burst[i];
			exe[i]=1;
			k++;
			printf("%s\t",name[i]);
		}
		i++;
		if(i>=n)
			i=0;
	}
	printf("\n");
	for(i=0;i<=l;i++)
		printf("-------");
	printf("\n");
	for(i=0;i<l;i++)
		printf("%d\t",sav[i]);
	printf("%d",time);
	for(i=0;i<n;i++)
		wait+=waiting[i];
	time1=time;
	printf("\n\n\n\n\nAverage Waiting Time %f\n",wait/n);
	printf("\nAverage Turnaround Time %f\n\n\n\n\n\n\n",(wait+time1)/n);
}
