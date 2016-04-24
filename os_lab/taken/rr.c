#include<stdio.h>

int z[10],avg=0,b[10],n=1,m[50],q,e=0,i,j;
char process[20];
float f,r;

int main()
{
	FILE *fp;
	fp=fopen("rr.txt","r+");
	while(fscanf(fp,"%s%d",&process[n],&b[n])!=EOF)
	{
		z[n]=b[n];
		n++;
		
	} 
	
	printf("\n\tROUND ROBIN SCHEDULING ALGORITHM");
 	printf("\n\t**********************************\n");
 	
	//printf("\nEnter how many jobs:");
 	//scanf("%d",&n);
 	//printf("\nEnter burst time for corresponding job...\n");
 	//for(i=1;i<=n;i++)
 	//{
  	//	printf("\nProcess %d: ",i);
  	//	scanf("%d",&b[i]); z[i]=b[i];
 	//}	

 	printf("\nEnter the time slice value : ");
 	scanf("%d",&q); 
	
	rr();
	average();	

return 0;
}

int rr()
{
	int max=0;
 	max=b[1];
	
	for(j=1;j<=n;j++)
	  	 if(max<=b[j])
			max=b[j];

 	if((max%q)==0)
   	r=(max/q);
 		else
  		r=(max/q)+1;
   
	for(i=1;i<=r;i++)
   	{
      		printf("\nAfter Round %d",i);
      		for(j=1;j<=n;j++)
		{
	  		if(b[j]>0)
	    		{
	     		b[j]=b[j]-q;

	     			if(b[j]<=0)
				{
					b[j]=0;
	     				printf("\nProcess %d is completed",j);
				}
	     else
	     printf("\nProcess %d remaining time is %d",j,b[j]);
	    		}
	 	}
	}
return 0;
}

// Average Waiting time
int average()
{
	//printf("\nCheck %d",n);
	for(i=1;i<n;i++)
   	{
    	e=0;
    		for(j=1;j<=r;j++)
     		{
			if(z[i]!=0)
			{
	  			if(z[i]>=q)
	  			{
	  				m[i+e]=q;
					z[i]-=q;
	  			}

	  			else
	  			{
	  				m[i+e]=z[i];
					z[i]=0;
	  			}
			}
	
			else
	  		m[i+e]=0;
       
		e=e+(n-1);
     		}
   	}

	for(i=2;i<n;i++)
    		for(j=1;j<=i-1;j++)
      		avg=avg+m[j];

	for(i=n;i<=r*(n-1);i++)
  	{
    		if(m[i]!=0)
    		{
      			for(j=i-(n-2);j<=i-1;j++)
      			avg=m[j]+avg;
    		}
  	}
 	f=avg;
	f=f/(n-1);
 
printf("\nTotal Waiting Time : %d",avg);
printf("\n\nAverage Waiting Time :%f\n",f);
	
	for(i=1;i<=r*n;i++)
	{ 
		if(m[i]!=0)
	   		if(i%n==0)
			{
	   		printf("|P%d| ",(i%n)+(n));      
			}

		else
	   	printf("|P%d| ",(i%n));
	   
	for(j=1;j<=m[i];j++)
		printf("%c",22);
	}

	printf("\n");
return 0;
}


