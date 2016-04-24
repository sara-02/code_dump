#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int start; int output[10]; int matrix [10][10]; char input[10];
int curstate;
int flag=0;
int main()
{
	FILE *f; char ch; int i=0,j=0,col=0,row=0;
	int len;
	f=fopen("try.txt","r");
	if(f==NULL)
	{
		printf("File not present");
		exit(0);
	}
	ch=getc(f);
	while(ch!=EOF)
	{
		//printf("%c",ch);
		//ch=getc(f);
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
			else if(ch==',')
			{
				ch=getc(f);
				output[i]=ch-48;
			}
			else if(ch!=' '&&ch!=',')
			{
				matrix[i][j]=ch-48;
				j++;
			}
			
			
		}
		ch=getc(f);
	}
	//printf("start%d",start);
	row=i-1;	
	/*for(i=0;i<=row;i++)
	{
		for(j=0;j<=col;j++)
			printf("%d ", matrix[i][j]);
		printf("\n");	
	}*/
	while(1)
	{
		printf("Enter the string");
		scanf("%s",input);
		len=strlen(input);
		flag=0;
		curstate=start;
		for(i=0;i<len;i++)
		{
			if(input[i]-97>col)
			{
				printf("Rejected");
				break;
			}
			if(i==0)
			{
				printf("%d",output[curstate]);
			}
			curstate=matrix[curstate][input[i]-97];
			printf("%d",output[curstate]);			
		}
	}
return 0;
}
