#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;
   int n = 0;
   char ch; int pn=0;
   fp = fopen("cy1.c","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   do
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
         break ;
      }
	ch=(char)c;
	if(ch=='i')
	{
		c=fgetc(fp);ch=(char)c;
		if(ch=='f')
		pn++;
	}

	else if(ch=='s')
	{
		c=fgetc(fp);ch=(char)c;
		if(ch=='w')
		{
			c=fgetc(fp);ch=(char)c;
			if(ch=='i')
			{
				c=fgetc(fp);ch=(char)c;
				if(ch=='t')
				{
					c=fgetc(fp);ch=(char)c;
				  	if(ch=='c')
					{
						if(ch=='h')
						pn++;
					}
				}
			}	
		}
	}
	else if(ch=='f')
	{
		c=fgetc(fp);ch=(char)c;
		if(ch=='o')
			{
				c=fgetc(fp);ch=(char)c;
				if(ch=='r')
					pn++;
			}
	}
	else if(ch=='w')
	{
		c=fgetc(fp);ch=(char)c;
		if(ch=='h')
		{
			c=fgetc(fp);ch=(char)c;
			if(ch=='i')
			{
				c=fgetc(fp);ch=(char)c;
				if(ch=='l')
				{
					c=fgetc(fp);ch=(char)c;
				  	if(ch=='e')
					pn++;
				}
			}	
		}
	}
	else if(ch=='e')
	{
		c=fgetc(fp);ch=(char)c;
		if(ch=='l')
			{ 
				c=fgetc(fp);ch=(char)c;
				if(ch=='s')
				{
				  c=fgetc(fp);ch=(char)c;	
				  if(ch=='e')
				  {
    					pn++;
					c=fgetc(fp);ch=(char)c;
                                        c=fgetc(fp);ch=(char)c;
					if(ch=='i')
					{ c=fgetc(fp);ch=(char)c;
					  if(ch=='f');
					}				
				  }	
				}
			}	
	}
      //printf("%c", ch);
   }while(1);
	 printf("%d\n", pn);
   fclose(fp);
   return(0);
}
