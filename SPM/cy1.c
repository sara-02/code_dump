#include <stdio.h>
#include <stdlib.h>
#define rrt fscanf(fp,"%c",&ch)
int main()
{

  FILE *fp;
  int pn=0; char ch;
  fp=fopen("try.c","r");
  if(fp==NULL)
  {
	exit(0);
}	 	
  while(fscanf(fp,"%c",&ch)!=EOF)
  {
	if(ch=='i')
	{
		rrt;
		if(ch=='f')
		pn++;
	}

	else if(ch=='s')
	{
		rrt;
		if(ch=='w')
		{
			rrt;
			if(ch=='i')
			{
				rrt;
				if(ch=='t')
				{
					rrt;
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
		rrt;
		if(ch=='o')
			{
				rrt;
				if(ch=='r')
					pn++;
			}
	}
	else if(ch=='w')
	{
		rrt;
		if(ch=='h')
		{
			rrt;
			if(ch=='i')
			{
				rrt;
				if(ch=='l')
				{
					rrt;
				  	if(ch=='e')
					pn++;
				}
			}	
		}
	}
	else if(ch=='e')
	{
		rrt;
		if(ch=='l')
			{ 
				rrt;
				if(ch=='s')
				{
				  rrt;	
				  if(ch=='e')
				  {
    					pn++;
					rrt;
                                        rrt;
					if(ch=='i')
					{ rrt;
					  if(ch=='f');
					}				
				  }	
				}
			}	
	}
  }

  printf("pn=%d\n",pn);			
  return 0;

}
