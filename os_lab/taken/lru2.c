#include<stdio.h>
void main()
{
	int fr[10][50],a[50],l=0,pf=0,n=0,f,i=0,j=0,k=0,flag=0,frame[10],c[10],r,s;
	FILE *fp;
	fp=fopen("process","r+");
	while(fscanf(fp,"%d",&a[n])!=EOF)
	{
		printf("%d\t",a[n]);
		n++;
	}
	printf("\nEnter the frame size\n");
	scanf("%d",&f);
	for(i=0;i<10;i++)
		frame[i]=-1;
	while(k<n)
	{
		if(frame[j]==-1)
		{
			flag=0;
			for(r=0;r<j;r++)
				if(frame[r]==a[k])
				{
					flag=1;
					k++;
				}
			if(flag==0)
			{
				pf++;
				frame[j++]=a[k++];
			}
		}
		else
		{
			flag=0;
			for(r=0;r<f;r++)
				if(frame[r]==a[k])
				{
					k++;
					flag=1;
					break;
				}
			if(flag==0)
			{
				for(r=0;r<f;r++)
					c[r]=0;
				for(r=0;r<f;r++)
				{
					for(s=k;s<n;s++)
					{
						if(frame[r]!=a[s])
							c[r]++;
						else
							break;
					}
				}
				s=-99;
				for(r=0;r<f;r++)
					if(c[r]>s)
					{
						s=c[r];
						j=r;
					}
				pf++;
				frame[j]=a[k++];
			}
		}
		if(j==f)
			j=0;
		for(i=0;i<f;i++)
			fr[i][l]=frame[i];
		l++;
		/*for(i=0;i<f;i++)
			printf("%d\t",frame[i]);
		printf("\n");*/
	}
	printf("\n\n\n");
	for(i=0;i<f;i++,printf("\n\n"))
		for(k=0;k<l;k++)
		{
			if(fr[i][k]==-1)
				printf("-\t");
			else
				printf("%d\t",fr[i][k]);
		}
	printf("\n\n\nPage Fault is %d\n\n\n",pf);
}
