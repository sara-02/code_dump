// Check if a string is palindrome or not.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *p; int i,l,flag=0;
	p=(char*)malloc(sizeof(char)*20);
	printf("Enter the string:: ");
	scanf("%s",p);
	l=strlen(p)-1;
	i=0;
	while(i<=l)
	{
		if(p[i]!=p[l])
		{
			flag=1;
			break;
		}
		i++;l--;
	}
	if(flag)
		printf("The string is NOT Palindrome\n");
	else
		printf("The string is palindrome\n");
return 0;		
}
