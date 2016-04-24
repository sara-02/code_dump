#include<stdio.h>
#include<stdlib.h>
char a[9];
void disp()
{	int i;
	for(i=1;i<=9;i++)
	{
		if(i%3==0)
		{
			printf("|%c|",a[i]);
			printf("\n");
			printf(" _||_||_|_");
			printf("\n");
		}
		else
		{
			printf("|%c|",a[i]);
		}
	}
}
int check()
{
	  if((a[1]==a[2])&&(a[2]==a[3]))
		return 1;
	else if((a[4]==a[5])&&(a[5]==a[6]))
		return 1;
	else if((a[7]==a[8])&&(a[8]==a[9]))
		return 1;
	else if((a[1]==a[4])&&(a[4]==a[7]))
		return 1;
	else if((a[2]==a[5])&&(a[5]==a[8]))
		return 1;
	else if((a[3]==a[6])&&(a[6]==a[9]))
		return 1;
	else if((a[1]==a[5])&&(a[5]==a[9]))
		return 1;
	else if((a[3]==a[5])&&(a[5]==a[7]))
		return 1;
	return 0;
	
}
void play()
{
	int i,p;int k;
	for(i=1;i<=9;i++)
	{
		if(i%2==0)
			p=1;
		else
			p=2;
		if(p==1)
			printf("PLAYER ONE'S TURN");
		else
			printf("PLAYER TWO'S TURN");
		
		printf("enter the position\n");
		scanf("%d",&k);
		if(k<=0||k>=10)
		{
			printf("number out of range enter again\n");
			i=i-1;
			continue;
		}
		else if(a[k]=='X'||a[k]=='O')
		{
			printf("position occupied\n");
			i=i-1;
			continue;
		}
		else
		{
			if(p==1)
				a[k]='X';
			else
				a[k]='O';
		}
		if(i>=4)
		{
			if(check())
			{
				if(p==1)
					printf("PLAYER 1 WINS!!\n");
				else
					printf("PLAYER 2 WINS!!\n");
				printf("\n\n");
				disp();
				exit(1);
			}
		}
		
		disp();

	}
	
		printf("MATCH DRAW\n");
		disp();
	
}

int main()
{
	int i;int c=49;
	for(i=1;i<=9;i++)
		{
		a[i]=(char)c;
		c++;
		}
	disp();
	play();	
}


