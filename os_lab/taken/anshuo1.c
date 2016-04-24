#include<stdio.h>
void main()
{
	int f,exe[10],l,flag[10],time[10],j,k=0,i=0,burst=0,fc[10],arr[10],chk;
	float wait=0;
	FILE *fp;
	char name[10][5];
	fp=fopen("process","r");
	while(fscanf(fp,"%s%d%d",name[i],&fc[i],&arr[i])!=EOF)
		i++;
	chk=arr[0];
	for(j=0;j<i;j++)
		flag[j]=0;
	m:
	j=0;
	f=10000;
	while(j<i)
	{
		if(arr[j]<f && flag[j]==0)
		{
			chk=j;
			f=arr[j];
		}
		j++;
	}
	if(k==0)
	{
		if(arr[chk]==0)
		{
			l=0;
			wait=wait+arr[chk];
		}
		else
		{
			wait=wait;
			l=arr[chk];
		}
	}
	else
		wait=wait+burst-l-arr[chk];
	flag[chk]=1;
	burst=burst+fc[chk];
	exe[k]=chk;
	time[k]=burst;
	k++;
	if(k<i)
		goto m;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for(j=0;j<i*8;j++)
		printf("_");
	printf("\n|");
	for(j=0;j<k;j++)
	{
		i=exe[j];
		printf("%s_____|",name[i]);
	}
	i=exe[0];
	printf("\n%d\t",arr[i]);
	for(j=0;j<k;j++)
		printf("%d\t",time[j]);
	printf("\n\n\n\nAverage waiting time = %f\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",wait/k);
	fclose(fp);
}
