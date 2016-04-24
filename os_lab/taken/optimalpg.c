#include<stdio.h>
int main()
{
	int fr[10][50],a[50],l=0,pf=0,n=0,f,i=0,j=0,k=0,flag=0,frame[10],c[10],r,s;
	FILE *fp;
	fp=fopen("inp.txt","r+");
	while(fscanf(fp,"%d",&a[n])!=EOF)
	{
		n++;
	}
    printf("No of pages read = %d",n);
	printf("\nEnter the frame size : ");
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
	}
    printf("\nPage\t FRAMES ==>>\n");
	for(i=0;i<l;i++,printf("\n"))
    {
        
        printf("%3d\t  ",a[i]);
		for(k=0;k<f;k++)
		{
			if(fr[k][i]==-1)
				printf("-  ");
			else
				printf("%d  ",fr[k][i]);
		}
    }
	printf("\nPage Fault is %d\n",pf);
}
