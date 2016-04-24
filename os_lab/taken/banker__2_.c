#include<stdio.h>
void main()
{
	int m,k,need[10][3],max[10][3],all[10][3],j,no,avail[11][3],finish[10],i=0,l=0,new[1][3];
	char name[10][3],exe[10][3],chk='n';
	FILE *fp;
	fp=fopen("process","r+");
	fscanf(fp,"%d%d%d",&avail[i][0],&avail[i][1],&avail[i][2]);
	while(fscanf(fp,"%s%d%d%d%d%d%d",name[i],&all[i][0],&all[i][1],&all[i][2],&max[i][0],&max[i][1],&max[i][2])!=EOF)
	{
		need[i][0]=max[i][0]-all[i][0];
		need[i][1]=max[i][1]-all[i][1];
		need[i][2]=max[i][2]-all[i][2];
		i++;
	}
	m:
	for(j=0;j<i;j++)
		finish[j]=0;
	j=k=0;
	while(k<i)
	{
		if(chk=='y' || chk=='Y')
		{
			if(new[0][0]<=avail[k][0] && new[0][1]<=avail[k][1] && new[0][2]<=avail[k][2])
			{
				for(m=0;m<3;m++)
				{
					all[no][m]=all[no][m]+new[0][m];
					avail[k][m]=avail[k][m]-new[0][m];
					need[no][m]=need[no][m]-new[0][m];
				}
				chk='n';
			}
		}
		if(need[j][0]<=avail[k][0] && need[j][1]<=avail[k][1] && need[j][1]<=avail[k][2] && finish[j]==0)
		{
			finish[j]=1;
			strcpy(exe[k],name[j]);
			avail[k+1][0]=avail[k][0]+all[j][0];
			avail[k+1][1]=avail[k][1]+all[j][1];
			avail[k+1][2]=avail[k][2]+all[j][2];
			k++;
			j=-1;
		}
		j++;
		if(j>i)
		{
			l=1;
			break;
		}
	}
	if(l==1)
		printf("\n\n\nUnsafe System\n");
	else
	{
		printf("\n\nSystem is safe\nSequence is \n\t");
		for(j=0;j<i;j++)
			printf("%s\t",exe[j]);
		printf("\n Net Available Resources %d %d %d\n\n",avail[k][0],avail[k][1],avail[k][2]);
	}
	printf("Additional request for any process y/n\n");
	scanf("%c",&chk);
	if(chk=='n' || chk=='N')
		exit(0);
	else
	{
		printf("Enter the process no i.e., 0,1,2,3,...\n");
		scanf("%d",&no);
		printf("Enter the additional resources requested\n");
		scanf("%d%d%d",&new[0][0],&new[0][1],&new[0][2]);
		if(new[0][0]<=need[no][0] && new[0][1]<=need[no][1] && new[0][2]<=need[no][2])
		{
			goto m;
		}
		else
			printf("Request can't be granted\n");
	}
}
