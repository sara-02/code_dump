#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p,*bt; int i,j,k,t=0; int tl;float avg=0.0;
	FILE *pt;
	pt=fopen("fcfs.txt","r");
	if(pt==NULL)
	{
		printf("Error\n");
		exit(1);
	}
	t=0;
	while(!feof(pt))
	{
		fscanf(pt,"%d%d",&i,&j);
		if(i==1234)
			break;
		
			t++;
	}
	printf("%d\n\n",t);
	fclose(pt);
	p=(int*)malloc(sizeof(int)*t);
	bt=(int*)malloc(sizeof(int)*t);
	k=0;
	pt=fopen("fcfs.txt","r");
	while(!feof(pt))
	{
		fscanf(pt,"%d%d",&i,&j);
		p[k]=i;
		bt[k]=j;
		k++;
	}
	for(i=0;i<t;i++)
		printf("%d\t%d\n",p[i],bt[i]);
	for(i=0;i<t;i++)
		printf("-------");
	printf("\n|");
	for(i=0;i<t;i++)
		printf("   P%d |",p[i]);
	printf("\n");
		for(i=0;i<t;i++)
		printf("-------");
	printf("\n");
	for(i=0;i<t;i++)
	{
		printf("%d     ",(int)tl);
		tl+=bt[i];
		avg+=tl;
	}
	printf("%d      ",tl);
	printf("\n");
	avg=avg/t;
	printf("The avg TAT is=%f ms\n",avg);
	avg=avg*t;
	avg=avg-tl;
	avg=avg/t;
	printf("The waiting time is=%f ms\n",avg);
	return 0;  
}
