#include<stdio.h>
#include<stdlib.h>
int a[100],pos,i;
int main()
{
	int c; int h,j,k,t=1; int top=-1,stack[100]; int c1=1;int pos1;
	for(i=0;i<100;i++)
		a[i]=0;
	printf("enter the root\n");
	fflush(stdin);
	scanf("%d",&c);
	a[1]=c;
	i=1;
	while(1)
	{
		printf("enter 1 to exit or otherwise\n");
		scanf("%d",&c);
		if(c==1)
		break;
		else
		{ 	if(a[i]==0)
				i++; 
			
			else
			{
				printf("enter the left sub child\n");
				scanf("%d",&c);
				a[i*2]=c;
				printf("enter the right sub child\n");
				scanf("%d",&c);
				a[i*2+1]=c;
				pos=i*2+1;
				i++;
			}
		}
	}
		h=pos/2;
		/*c=1;
		while(c<=pos)
		{
			j=0;
			while(j<h)
			{
				printf(" ");
				j++;
			}
			for(k=0;k<t;k++)
			{	
				if(c>pos)
					break;
				printf(" %d ",a[c]);
				j=0;
				while(j<h)
				{
					printf(" ");
					j++;
				}
				c++;
				
			}
			h--;
			t=t*2;
			printf("\n");
			
		}*/
		
		printf("%d\t%d\n",pos,c);
		c1=1;
	/*c1=1;
	while((c1<=pos)||(top!=-1))
		{
			if(a[c1]==0)
			{
					if(top==-1)
						break;
			 	 c1=stack[top];
				printf("|%d||",a[c1]);
				if(top==-1)
					break;
				top=top-1;
				c1=c1*2+1;	
			}
			else
			{       top=top+1;
				stack[top]=c1;
				
				c1=c1*2;
			}
		}*/
		c1=1;
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
		}
			
	return 1;
}
