#include<stdio.h>
#include<string.h>

int main()
{
	
	char process[10][3],seq[20][3];
	int all[10][3],max[10][3],need[10][3],i=0,j,k,l,m=0,r1,r2,r3,p,pos,avail[10][3],finish[10],flag=0;
	
	FILE*f;

	f=fopen("process.txt","r+");

	fscanf(f,"%d%d%d",&avail[0][0],&avail[0][1],&avail[0][2]);

	while(!feof(f))
	{
		fscanf(f,"%s%d%d%d%d%d%d",process[i],&all[i][0],&all[i][1],&all[i][2],&max[i][0],&max[i][1],&max[i][2]);		
		need[i][0]=max[i][0]-all[i][0];
		need[i][1]=max[i][1]-all[i][1];
		need[i][2]=max[i][2]-all[i][2];
			
		i++;
	}
	
	i--;
		printf("\n");
        	for(k=0;k<3;k++)
        	{
              		 printf("%d ",avail[0][k]);
      	  	}
		printf("\n");

	l:
		for(j=0;j<i;j++)
    		 finish[j]=0;

	j=0;
	m=0;

	while(!flag)
	{
		if((finish[j]==0)&&(need[j][0]<=avail[m][0]&&need[j][1]<=avail[m][1]&&need[j][2]<=avail[m][2]))
		{
		
			
			for(k=0;k<3;k++)
			 avail[m+1][k]=avail[m][k]+all[j][k];
		
			strcpy(seq[m],process[j]);
			m++;
			finish[j]=1;
			j=-1;
		}
		j++;
	
		p=0;
		while(finish[p]==1&&p<i)
		{
			p++;		
		}	
	
		if(p==i)
		{
			flag=1;
		}
		if(j>i)
		{
			flag=2;
		}

	}
	
	 printf("\t\tALLOCATION\tMAX\tNEED\tAVAILABLE\n");
         
        for(j=0;j<i;j++)
        {
                printf("%s",process[j]);
                printf("\t\t");

                for(k=0;k<3;k++)
                {
                        printf("%d ",all[j][k]);
                }

                printf("\t\t");
    
                for(k=0;k<3;k++)
                { 
                        printf("%d ",max[j][k]);
                }
                printf("\t\t");

                for(k=0;k<3;k++)
                {
                        printf("%d ",need[j][k]);
                }
		printf("\t\t");
		for(k=0;k<3;k++)
		 printf("%d ",avail[j][k]);
		printf("\n");
	}
	
	if(flag==1)
	{
		printf("\nSAFE SEQUENCE: ");
		for(i=0;i<m;i++)
	 	 printf("%s ",seq[i]);
	}

	else if(flag==2)
	 printf("\nDEADLOCK STATE");
	
	printf("\n");

	printf("ENTER PROCESS NO. : ");
	scanf("%d",&pos);

	printf("ENTER ADDITIONAL RESOURCES: ");
	scanf("%d%d%d",&r1,&r2,&r3);

	m=0;

	if(r1<=need[pos][0]&&r2<=need[pos][1]&&r3<=need[pos][2])
	{
		if(r1<=avail[m][0]&&r2<=avail[m][1]&&r3<=avail[m][2])
		{
			 avail[m][0]=avail[m][0]-r1;
			 avail[m][1]=avail[m][1]-r2;
			 avail[m][2]=avail[m][2]-r3;
			 all[pos][0]-=r1;
			 all[pos][1]-=r2;
			 all[pos][2]-=r3;
			 need[pos][0]-=r1;
			 need[pos][1]-=r2;
			 need[pos][2]-=r3;
			 goto l;
		}
	}


}
