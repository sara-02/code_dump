#include <string.h>
#include <ctype.h>

char opnds[50][80],oprs[50];
int  topr=-1,topd=-1;

void pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}

char *popd()
{
    return(opnds[topd--]);
}

void pushr(char oper_ator)
{
    oprs[++topr]=oper_ator;
}

char popr()
{
    return(oprs[topr--]);
}

int empty(int t)
{
	if(t==0)
	return(1);

return(0);
}

void main()
{
    char prefix[50],ch,str[50],operand1[50],operand2[50],oper_ator[2];
    int i=0,k=0,opndcnt=0;
    clrscr();
    printf("\t\t\t * Prefix to Postfix *");
    printf("\n\nEnter the Prefix Expression : ");
    gets(prefix);

    while((ch=prefix[i++])!='\0')
    {
	if(isalnum(ch))
	{
	    str[0]=ch;
	    str[1]='\0';
	    pushd(str);
	    operand_count++;
	    if(operand_count>=2)
	    {
		strcpy(operand2,popd());
		strcpy(operand1,popd());
		strcpy(str,operand1);
		strcat(str,operand2);
		ch=popr();
		oper_ator[0]=ch;
		oper_ator[1]='\0';
		strcat(str,oper_ator);
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

    if(!empty(topd))
    {
	strcpy(operand2,popd());
	strcpy(operand1,popd());
	strcpy(str,operand1);
	strcat(str,operand2);
	ch=popr();
	oper_ator[0]=ch;
	oper_ator[1]='\0';
	strcat(str,oper_ator);
	pushd(str);
    }
    printf("The Postfix Expression is : ");
    puts(opnds[topd]);
getch();
}