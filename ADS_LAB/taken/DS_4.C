#include<string.h>
#include<conio.h>
#include<stdio.h>

char opnds[50][80],oprs[50];
int  topr=-1,topd=-1;

// Push Operation for Operand Stack
void pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}

// Pop operation for Operand Stack
char *popd()
{
    return(opnds[topd--]);
}

// Push operation for Operator Stack
void pushr(char opr)
{
    oprs[++topr]=opr;
}

// Pop operation for Operator Stack
char popr()
{
    return(oprs[topr--]);
}

// To check if a stack empty by checking its value of top
int empty(int t)
{
    if(t==0)
	return(1);

    return(0);
}

void main()
{
	char prefix[50],ch,str[50],operand1[50],operand2[50],oper_ator[2];
	int i=0,operand_count=0;
	clrscr();
	printf("\t\t\t * Prefix to Infix *\n\n");
	printf("Enter the Prefix Expression : ");
	gets(prefix);

	while((ch=prefix[i++])!='\0')
	{
		if(isalnum(ch))
		{
		str[0]=ch;
		str[1]='\0';
		pushd(str);
		operand_count++;

			if(operand_count >= 2)
			{
			strcpy(operand2,popd());
			strcpy(operand1,popd());
			strcpy(str,"(");
			strcat(str,operand1);
			ch=popr();
			oper_ator[0]=ch;
			oper_ator[1]='\0';
			strcat(str,oper_ator);
			strcat(str,operand2);
			strcat(str,")");
			pushd(str);
			operand_count-=1;
			}
		}

		else
		{
		pushr(ch);
		/* operator followed by single operand*/
			if(operand_count==1)
			operand_count=0;
		}
	}
									      getche
    if(topd==0)
    {
	strcpy(operand2,popd());
	strcpy(operand1,popd());
	strcpy(str,"(");
	strcat(str,operand1);
	ch=popr();
	oper_ator[0]=ch;
	oper_ator[1]='\0';
	strcat(str,oper_ator);
	strcat(str,operand2);
	strcat(str,")");
	pushd(str);
    }
	printf("The Infix Expression is : ");
	puts(opnds[topd]);

getch();
}