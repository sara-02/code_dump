#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *pt; 
	int *p,*bt,*bt1,*qu,*oz,*ozp; int i,j,z,fr,k,t,check,re,ts; float avg=0.0;

	printf("ENTER THE TIME SLICE\n");
	scanf("%d",&ts);
	pt=fopen("rr.txt","r");
	if(pt==NULL)
	{
		printf("error\n");
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
	fclose(pt);
	p=(int*)malloc(sizeof(int)*t);
	bt=(int*)malloc(sizeof(int)*t);
	bt1=(int*)malloc(sizeof(int)*t*8);
	qu=(int*)malloc(sizeof(int)*t*8);
	oz=(int*)malloc(sizeof(int)*t*8);
	ozp=(int*)malloc(sizeof(int)*t*8);
	
	pt=fopen("rr.txt","r");
        
	k=0;fr=0;re=0;
	while(!feof(pt))
	{
		fscanf(pt,"%d%d",&i,&j);
		if(i==1234)
			break;
		p[k]=i;
		bt[k]=j;
		bt1[k]=j;
		qu[k]=i;
	printf("%d\t%d\t%d\t%d\n",p[k],qu[k],bt[k],bt1[k]);
		k++;
		
	}
	re=k-1;
	printf("%d\n",re);
	fclose(pt);
	check=0;
	z=0;fr=0;
	while(check<t)
	{
		oz[z]=qu[fr];
		k=bt1[fr]-ts;
		if(k<=0)
		{      
			ozp[z]=bt1[fr]; 
			fr++;
			check++;
		}
		else
		{
			bt1[fr]=k;
			ozp[z]=ts;
			re++;
			qu[re]=qu[fr];
			bt1[re]=bt1[fr];
			fr++;
		}
	printf("P%d-->%d\n",oz[z],ozp[z]);
	z++;
	}
	ts=0;
	for(i=0;i<t;i++)
	{
		fr=0;
		re=0;
		for(j=0;j<z;j++)
		{
			if(p[i]==oz[j])
			{
				for(k=fr;k<j;k++)
					re+=ozp[k];
				fr=j+1;
			}
		}
		avg+=re;
		ts+=bt[i];
		printf("%d\t%d\t%d\t%d\n",p[i],bt[i],re,bt[i]+re);
	}
	avg=avg/t;
	printf("the avg waiting time is =%f ms\n",avg);
	avg*=t;
	avg+=ts;
	avg=avg/t;
	printf("the avg TAT is = %f ms \n" ,avg);	
	
}
