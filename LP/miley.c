#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	FILE *f;
	int start,curstate; char ch; int flag=0; int i=0;int col; int len;
	int matrix[30][30]; int output[30][30]; int k,j; char input[30];

	f=fopen("mile.txt","r");
	if(f==NULL)
	{
		printf("FILE NOT PRESENT");
		exit(0);
	} 
	ch=fgetc(f);
	while(ch!=EOF)
	{
		//printf("%c",ch);
		if(flag==0)
		{
			start=ch-48;
			flag=1;
		}
		else if(flag==1)
			flag=2;
		else if(flag==2)
		{
			if(ch=='\n')
			{
				i++;
				col=j-1;
				j=0;
			}
			else if(ch=='/')
			{
				ch=getc(f);
				//printf("%c--%di--%dj--",ch,i,j);
				output[i][j]=ch-48;
				j++;
			}
			else if(ch!=' ' && ch!='/')
			{
				matrix[i][j]=ch-48;
			}	
		}
		ch=fgetc(f);	
	}
	fclose(f);	
// printf("\n--start=%d\n",start);
// printf("\n--rows=%d\n",i);
// printf("\n--rows=%d\n",col);
// 	for (flag=0;flag<=i;flag++)
// 	{
// 		for(j=0;j<=col;j++)
// 			printf("%d/%d--i=%d,j=%d--",matrix[flag][j],output[flag][j],flag,j);
// 	 	printf("\n");
// 	}
// 	// for(flag=0;flag<=i;flag++)
// 	// {
// 	// 	printf("%d--",output[flag]);
// 	// }
// 	// printf("-----\n");
while(1)
	{
		//flag=0;
		curstate=start;
		printf("\nEnter the string::");
		scanf("%s",input);
		len=strlen(input);
		for(k=0;k<len;k++)
		{
			
			if((input[k]-97>col))
			{
				printf("REJECTED\n");
				//flag=-1;
				break;
			}
			// if(k==0)
			// {
			// 	printf("%d",output[curstate]);
			// }	
			
			//printf("%d---ss---%d",curstate,output[curstate]);
			printf("(%d--->%d)",input[k]-97,output[curstate][input[k]-97]);
			curstate=matrix[curstate][input[k]-97];
			//printf("%d",output[curstate][]);
			

		}
		// if(flag==0)
		// {
		// 	printf("%d",output[curstate]);
		// }	
			
	}	

return 0;
}
