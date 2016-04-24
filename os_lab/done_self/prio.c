#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p,*bt,*pro; int i,j,k,l,t=0; int tl;float avg=0.0;
	FILE *pt;
	pt=fopen("prio.txt","r");
	if(pt==NULL)
	{
		printf("Error\n");
		exit(1);
	}
	t=0;
	while(!feof(pt))
	{
		fscanf(pt,"%d%d%d",&i,&j,&l);
		if(i==1234)
			break;
		
			t++;
	}
	printf("%d\n\n",t);
	fclose(pt);
	p=(int*)malloc(sizeof(int)*t);
	bt=(int*)malloc(sizeof(int)*t);
	pro=(int*)malloc(sizeof(int)*t);
	k=0;
	pt=fopen("prio.txt","r");
	while(!feof(pt))
	{
		fscanf(pt,"%d%d%d",&i,&j,&l);
		if(i==1234)
			break;
		p[k]=i;
		bt[k]=j;
		pro[k]=l;
		k++;
	}
	for(i=0;i<t;i++)
		printf("%d\t%d\t%d\n",p[i],bt[i],pro[i]);
	printf("---\n\n\n");
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
			{
				if(pro[j]<pro[i])
				{
					k=bt[j];
					bt[j]=bt[i];
					bt[i]=k;
					k=p[j];
					p[j]=p[i];
					p[i]=k;
					k=pro[j];
					pro[j]=pro[i];
					pro[i]=k;
				}	
			}
	}
	for(i=0;i<t;i++)
		printf("%d\t%d\t%d\n",p[i],bt[i],pro[i]);
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
		printf("%d     ",tl);
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
