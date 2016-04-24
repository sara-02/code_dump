#include<stdio.h>


int main()
{
	char process[10][3];
	int burst[10],burst1[10],i=0,l=0,time_slice,n,flag[10],exec_time[10],wait[10],running=1,k;
	float total_wait=0.0,sum=0.0;
	FILE*f;

	f=fopen("process.txt","r+");
	printf("\n\n\n");
	printf("\t\t\tROUND ROBIN ALGORITHM\n");
	printf("_______________________________________________\n");

	for(i=0;i<10;i++)
	{
		flag[i]=0;
		wait[i]=0;
		exec_time[i]=0;
	}

	i=0;

	while(!feof(f))
	{
		fscanf(f,"%s%d",process[i],&burst[i]);
		burst1[i]=burst[i];
		i++;
	}

	printf("\nEnter time slice quantum: ");
	scanf("%d",&time_slice);
	n=--i;
	
	i=0;

		while(running)
		{
			if(burst[i]>0)
			{
				total_wait+=exec_time[l]-wait[i];
				

				if(burst[i]>=time_slice)
				{
					burst[i]=burst[i]-time_slice;	
					l++;
					exec_time[l]=exec_time[l-1]+time_slice;
				}

				else
				{
					l++;
					exec_time[l]=exec_time[l-1]+burst[i];
					burst[i]-=time_slice;
				}
	
				printf("%s    ",process[i]);

			if(burst[i]<=0)
			 flag[i]=1;

			else
			 wait[i]=exec_time[l];

			}

			if(i==2)
			 i=-1;			

			i++;

			k=0;
			while(flag[k]==1)
			 k++;
			if(k==n)
			 running=0;
		}
	
	printf("\n");
	for(i=0;i<=l;i++)
	 printf("-----"); 
	printf("\n");
	for(i=0;i<=l;i++)
	 printf("%d    ",exec_time[i]);

	printf("\n\nProcess Name\tBurst Time");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t%d",process[i],burst1[i]);
	}

	for(i=0;i<n;i++)
	{
		sum+=burst1[i];
	}

	sum+=total_wait;

	printf("\nAverage Waiting Time: %.4f ms",total_wait/n);
	printf("\nAverage Turn Around Time: %.4f ms",sum/n);
	printf("\n");

}
