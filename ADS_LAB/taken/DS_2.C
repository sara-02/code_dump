#include<stdio.h>
#include<conio.h>
unsigned int posteval(char *infix,char *postfix)
{
	int i,k=0,top=-1;
	char stk[40];
	for(i=0;infix[i]!=NULL;i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
			postfix[k++]=infix[i];
		else if(infix[i]=='(')
			stk[++top]=infix[i];
		else if(infix[i]==')')
		{
			while(stk[top]!='(')
				postfix[k++]=stk[top--];
			top--;
		}
		else if(infix[i]=='+' || infix[i]=='-')
		{
			while(stk[top]=='+' || stk[top]=='-' || stk[top]=='*' || stk[top]=='/')
				postfix[k++]=stk[top--];
			stk[++top]=infix[i];
		}
		else if(infix[i]=='*' || infix[i]=='/')
		{
			while(stk[top]=='*' || stk[top]=='/')
				postfix[k++]=stk[top--];
			stk[++top]=infix[i];
		}
	}
	while(top>-1)
		postfix[k++]=stk[top--];
	postfix[k]=NULL;
	return postfix;
}
void main()
{
	char *infix,*postfix;
	clrscr();
	infix=(char *)malloc(50);
	postfix=(char *)malloc(50);
	printf("Enter the infix exp\n");
	scanf("%s",infix);
	postfix=posteval(infix,postfix);
	printf("The postfix exp. is %s",postfix);
	getch();
}