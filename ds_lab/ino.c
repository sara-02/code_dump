#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100];int i; int pos,c; int stack[100];int top=-1; int c1=1;
	for(i=0;i<100;i++)
		a[i]=0;
	for(i=1;i<=9;i++)
	{
		printf("enter the number\n");
		scanf("%d",&a[i]);
	}
	for(i=1;i<=9;i++)
	{
		printf("%d\n",a[i]);
	}
	pos=9;
	c1=1; //preorder
	while(c1<=pos||top!=-1)
	{
		if(a[c1]==0)
		{
			c1=stack[top];
			if(top==-1)
				break;
			top--;
		}
		else
		{
			top++;
			stack[top]=c1;
			top++;
			stack[top]=c1*2+1;
			c1=c1*2;
			if(a[c1]!=0)
				printf("|%d|",a[c1]);
		}
	}
	/*c1=1;//in order
	while((c1<=pos)||(top!=-1))
		{
			if(a[c1]==0)
			{
					c1=stack[top];
					if(top==-1)
						break;
					top--;
			}
			else
			{       
				printf("|%d|",a[c1]);
				top++;
				stack[top]=c1*2+1;
				c1=c1*2;
			}
		}*/	
}
