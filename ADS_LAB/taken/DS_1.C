#include<stdio.h>
#include<conio.h>
void main()
{
	int top=-1,i,stk[40],a,b;
	char exp[50];
	clrscr();
	printf("Enter the postfix expression\n");
	scanf("%s",exp);
	for(i=0;exp[i]!=NULL;i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
			stk[++top]=exp[i]-'0';
		else
		{
			b=stk[top--];
			a=stk[top--];
			if(exp[i]=='+')
				a+=b;
			else if(exp[i]=='-')
				a-=b;
			else if(exp[i]=='*')
				a*=b;
			else if(exp[i]=='/')
				a/=b;
			stk[++top]=a;
		}
	}
	printf("The answer is %d",stk[0]);
	getch();
}