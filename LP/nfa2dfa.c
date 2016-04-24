#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char matrix[10][10][10]; char table[10][10]; char start; char finish[10]; 
int rm,cm,tm=0;

void unionly(int j)
{
	int l; int pt,k,t=0;
	int u[10];int fu[10];
	for(l=0;l<=rm-1;l++)
	{
		if(table[tm-1][l]>='0'&&table[tm-1][l]<='9')
		{
			pt=table[tm-1][l]-48;
			for(k=0;k<=rm-1;k++)
			{
				if(matrix[pt][j][k]>='0'&&matrix[pt][j][k]<='9')
				{
					u[t]=matrix[pt][j][k];
					t++;
				}	
			}	
		}
	}
	if(t==0)
		matrix[rm][j][0]='$';
	 else if(t==1)
		matrix[rm][j][0]=u[0];
	else
	{
		for(l=0;l<t;l++)
			for(pt=0;pt<t-1;pt++)
			{
				if(u[pt]>u[pt+1])
				{
					k=u[pt];
					u[pt]=u[pt+1];
					u[pt+1]=k;
				}
			}
		pt=0;	
		for(l=0;l<t;l++)
		{
			if(u[l+1]==u[l])
				continue;
			fu[pt]=u[l];
			pt++;

		}
		for(l=0;l<pt;l++)
			matrix[rm][j][l]=fu[l];	
	}		
}

int checknp(int i, int j)
{
	int l,k,flag=0;
	for(l=0;l<tm;l++)
	{ flag=0;
		for(k=0;k<=rm;k++)
		{
			if(matrix[i][j][k]>='0'&&matrix[i][j][k]<='9')
				if(table[l][k]==matrix[i][j][k])
					flag=flag+1;
					
		}
		if(flag==countk(i,j))
			break;
	}	
		
	if(flag==0)
		return 1;
return 0;		
}

void tableentry(int i,int j)
{
	int l=0,k=0,p=0; char t;
	for(k=0;k<=rm;k++)
		if(matrix[i][j][k]>='0'&&matrix[i][j][k]<='9')
		{
			table[tm][l]=matrix[i][j][k];
			l++;	
		}
 tm=tm+1;
}
int countk(int i ,int j)
{
	int k=0,count=0;
	for(k=0;k<=rm;k++)
	{
		
			if(matrix[i][j][k]>='0'&&matrix[i][j][k]<='9')
				count++;
	}
		return count;
	
}
int main()
{
	FILE *f;
	int i=0,j=0,k=0; int l; int orgcount=0;
	int col, flag=0; int fcol=0; char ch;
	f=fopen("nfa.txt","r");
	if(f==NULL)
	{
		printf("FILE NOT PRESENT\n");
		exit(0);
	}
	ch=fgetc(f);
	while(ch!=EOF)
	{
		if (flag==0)
		{
			start=ch;
			flag=2;
		}
	
		else if(flag==2)
		{
			ch=fgetc(f);
			finish[i]=ch;
			i++;
			ch=fgetc(f);
			while(ch!='\n')
			{
				if(ch!=',' && ch!=(char)13)
				{
					finish[i]=ch;
					i++;
				}
				ch=fgetc(f);
			}
			flag=3;
        	fcol=i-1;
        	i=0;
		}
		else if(flag==3)
		{
			if(ch=='\n')
        	{
        		i++;
        		col=j;
        		j=0;
        		k=0;
        		
        	}
        	else if(ch==',')
        	{
        		ch=getc(f);
        		matrix[i][j][k]=ch;
        		k++;
        	}
        	else if(ch==' ')
        	{
        		j++;
        		k=0;
        	}
        	else if(ch!=',' && ch!=' ')
        	{
        		if(ch=='$')
        		{
        			matrix[i][j][0]=ch;
        		}
        		else
        		{
        			matrix[i][j][0]=ch;
        			k++;
        		}
        	}	
		}
		ch=fgetc(f);		
	}
	rm=i;
	orgcount=i;
	cm=col;
	flag=0;

 for(i=0;i<=rm;i++)
 {
 	 for(j=0;j<=col;j++)
 	{
 		flag=0;	
 		if(countk(i,j)>1)
 		{
 			if(tm==0)
 			{
 				tableentry(i,j);
				rm=rm+1;
				for(l=0;l<=col;l++)
					unionly(l);
 			}	
 			else if(checknp(i,j))
 			{
 				tableentry(i,j);
				rm=rm+1;
				for(l=0;l<=col;l++)
					unionly(l);
			}
 			 else 
 			  {
 			  	flag=1; break;
 			  }	
 			
 		}	
 	
 }
 if(flag==1)
 	break;
}

 for(i=0;i<=rm;i++)
 {
	if(i==orgcount+1)
		printf("---------NEW STATES----------\n");
 	for(j=0;j<=col;j++)
 	{
 		for(l=0;l<=rm;l++)
			if(matrix[i][j][l]!='\0')
 				printf("%c,",matrix[i][j][l]);
 		printf(" ");
 	}
 	printf("\n");
 }		
return 0;
}
