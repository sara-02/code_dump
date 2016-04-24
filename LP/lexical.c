#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	FILE *f;
	int curstate=0,flag=0; char ch;
	f=fopen("lexi.txt","r");
	if(f==NULL)
	{
		printf("FILE NOT PRESENT");
		exit(0);
	}
	ch=fgetc(f);
	while(ch!=EOF)
	{
		if(ch!=' '&& ch!='\n')
			printf("%c",ch);
		if(flag==-1)
			{
				printf("  Identifier type error  ");
				flag=-3;
				//printf("\n");
				//flag=0;
				//curstate=0;
			
			}
		if(flag==-2)
			{
				printf("  Numerical type error  ");
				flag=-3;
				//printf("\n");
			//flag=0;
			//curstate=0;
			
			}
		if(flag!=-3)
		{
	
		 	if(ch==' ' || ch=='\n')
			{
				if(curstate==2||curstate==3)
					printf("  Number");
				else
				printf("  Identifier");
				printf("\n");
				flag=0;
				curstate=0;
			}	
			else
			{
				if (curstate==0)
				{
					if(ch=='_'||(ch>='a'&&ch<='z'))
						curstate=1;
					else if(ch>='0'&&ch<='9')
						curstate=2;
					else
						flag=-1;
				
				}
				else if(curstate==1)
				{
					if(ch>='0'&&ch<='9')
						curstate=4;
					else if(ch>='a' && ch<='z')
						curstate=1;
					else
						flag=-1;
				}
				else if(curstate==2)
				{
					if(ch>='0'&&ch<='9')
						curstate=2;
					else if(ch=='.')
						curstate=3;
					else
						flag=-2;
				}
				else if(curstate==3)
				{
					if(ch>='0'&&ch<='9')
						curstate=3;
					else
						flag=-2;	
				}

				else if(curstate==4)
				{
					if(ch>='a'&& ch<='z')
						curstate=1;
					else if(ch>='0' && ch<='9')
						curstate=4;
					else 
						flag=-1;			
				}

			}	
	}	
		ch=fgetc(f);		
	}
printf("\n");
return 0;
}
