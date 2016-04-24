#include<stdio.h>
void main()
{
	int pf=0,n=0,a[50],f,flag=0,frame[10],fr[10][20],l=0,i=0,j=0,k=0;
	FILE *fp;
	fp=fopen("page","r+");
	printf("\n\nPages are\n\n");
	while(fscanf(fp,"%d",&a[n])!=EOF)
	{
		printf("%d ",a[n]);
		n++;
	}
	printf("\n\nEnter the frame size\n");
	scanf("%d",&f);
	for(i=0;i<f;i++)
		frame[i]=-99;
	while(k<n)
	{
		flag=0;
		for(i=0;i<f;i++)
		{
			if(a[k]==frame[i])
			{
				k++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			frame[j++]=a[k++];
			pf++;
			if(j==f)
				j=0;
		}
		for(i=0;i<f;i++)
			fr[i][l]=frame[i];
		l++;
	}
	printf("\n\n Pages are\n\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n\n\n");
	for(i=0;i<f;i++,printf("\n\n"))
		for(k=0;k<l;k++)
			{
				if(fr[i][k]!=-99)
					printf("%d ",fr[i][k]);
				else
					printf("- ");
			}
	printf("\n\nPage Fault is %d\n\n",pf);
}
