#include<stdio.h>
int frame[50];
int size;
void print(int n)
{
    int i;
    for(i=0;i<size;++i)
    {
        if(i<n)
        printf(" %d ",frame[i]);
        else
            printf(" - ");
    }
}
int main()
{
    FILE *p;
    int pg,n=0,i,rep_point=0,count=0;
    p=fopen("log.txt","r");
    if(p==NULL)
    {
        printf("\nCould not open the log file so exiting.");
    }
    else
    {
        printf("\nEnter the frame size:");
        scanf("%d",&size);
        printf("\nPage\t\t\t");
        for(i=0;i<size;++i)
            printf(" ");
        printf("Frame");
        while(!feof(p))
        {
            fscanf(p,"%d ",&pg);
            printf("\n %d\t\t\t",pg);
            for(i=0;i<n;++i)
            {
                if(pg==frame[i])
                {
                    print(n);
                    printf("\t\tPage Hit");
                    break;
                }
            }
            if(i==n)
            {
                print(n);
                printf("\t\tPage Fault");
                count++;
                if(n<size)
                {
                    frame[n]=pg;
                    n++;
                }
                else
                {
                    frame[rep_point]=pg;
                    rep_point++;
                    if(rep_point>=size)
                        rep_point=0;
                }
            }
        }
    }
    printf("\n\n\nTotal number of page fault is:%d",count);
    printf("\n");
    return 0;
}