#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *f;
	int start,curstate; char ch; int flag=0; int i=0; 
	int col,fcol,stop[30]; char choice; int len;
	int matrix[30][30]; int k,j=0; char instr[30]; 
	f=fopen("values.txt","r");
	if(f==NULL)
	{
		printf("FILE NOT PRESENT");
		exit(0);
	}
	 ch = fgetc(f);
    while (ch != EOF)
    {
        //printf ("%c", ch);
        if(flag==0)
        {
        	start=ch-48;
        	//printf("Start %d\n",start);
        	flag=1;
        }
        else if(flag==1)
        {	flag=2;
        }
        else if(flag==2)
        {
        	ch=fgetc(f);
        	stop[i]=ch-48;
        	//printf("Final %d--\n",stop[i]);
        	i++;
        	ch=fgetc(f);
        	while(ch!='\n')
        	{
        		if(ch!=',' && ch!=' ')
        		{
        			stop[i]=ch-48;
        			//printf("Final %d--\n",stop[i]);
        			i++;
        		}	
        		//printf("final %c--",ch);
        		ch=fgetc(f);
        	
        	}
        	flag=3;
        	fcol=i;
        	//printf("stop cols =%d\n",fcol);
        	i=0;
        }
        else if(flag==3)
        {
        	if(ch=='\n')
        	{
        		i++;
        		col=j-1;
        		j=0;
        		//printf("\n");
        	}
        	else if(ch=='-')
        		{
        			ch=getc(f);
        			matrix[i][j]=ch-48;
        			matrix[i][j]*=-1;
        			//printf("DFA**%d**",matrix[i][j]);
        			j++;

        		}
        	else if(ch!=' '&& ch!=(char)13)
        	{
        			
        		matrix[i][j]=ch-48;
        		//printf("DFA**%d**",matrix[i][j]);
        		j++;	
        	}	
        	
        }	
        ch = fgetc(f);
    }
    //printf("ROWS=%d\n",i);
    //printf("COLS=%d\n",col);
    fclose(f);

    /*for(k=0;k<=i;k++)
    {
    	for(j=0;j<=col;j++)
    		printf("%d",matrix[k][j]);
    	printf("\n");
    }
    */
	
	curstate=start;
	//printf("Enter 0 to exit:: ");
	//choice=getchar();
	while(1)
	{
		flag=0;	
		curstate=start;
		printf("Enter the string:: ");
		scanf("%s",instr);
		len=strlen(instr);
		//printf("len=%d\n",len);
		for(k=0;k<len;k++)
		{
			if((instr[k]-97)>col)
			{
				printf("REJECTED\n");
				flag=-1;
				break;
			}
			if(matrix[curstate][instr[k]-97]==-1)
			{
				continue;
			}	
			curstate=matrix[curstate][instr[k]-97];
		}
		if(flag!=-1)
		{
			for(k=0;k<fcol;k++)
		{
			if(curstate==stop[k])
			{
				printf("ACCEPTED\n");
				flag=1;
				break;
			}	
		}
		}	
		
		if(flag==0)
		{
			printf("REJECTED\n");
		}
		/*printf("Enter 0 to exit:: ");
		 fflush(stdin);
		choice=getchar();
	*/}
return 0;
}
