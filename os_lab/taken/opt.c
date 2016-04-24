#include<stdio.h>
struct page
{
    int name;
    int lstused;
}frame[10];
int size;
void status()
{
    int i;
    printf("\n");
    for(i=0;i<size;++i)
    {
        if(frame[i].lstused==-1)
            printf(" - ");
        else
            printf(" %d ",frame[i].name);
    }
}
int main()
{
    int i,j,n=0,pg[40],flag,min,count=0;;
    FILE *f;
    f=fopen("log.txt","r");
    printf("\n");
    while(!feof(f))
    {
        fscanf(f,"%d ",&pg[n]);
        printf("%d ",pg[n]);
        n++;
    }
    printf("\n\n\nEnter the Frame size:");
    scanf("%d",&size);
    printf("\n\n");
    for(i=0;i<size;++i)
    {
        frame[i].lstused=-1;
    }
    printf("Status\t\tPage\t\tInfo");
    status();
    i=0;
    while(i<n)
    {
        flag=0;
        for(j=0;j<size;++j)
        {
            if(frame[j].lstused==-1)
            {
                frame[j].name=pg[i];
                frame[j].lstused=i;
                status();
                printf("\t%d",pg[i]);
                printf("\t Page Fault(Empty Frame)");
                flag=1;
                count++;
                break;
            }
        }
        if(flag==0)
        {
            for(j=0;j<size;++j)
            {
                if(frame[j].name==pg[i])
                {
                    frame[j].lstused=i;
                    status();
                    printf("\t%d",pg[i]);
                    printf("\t Page Hit");
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            min=frame[0].lstused;
            for(j=1;j<size;++j)
            {
                if(min>frame[j].lstused)
                    min=frame[j].lstused;
            }
            for(j=0;j<size;++j)
            {
                if(min==frame[j].lstused)
                {
                    frame[j].name=pg[i];
                    frame[j].lstused=i;
                    status();
                    printf("\t%d",pg[i]);
                    printf("\t Page Fault by replacement");
                    count++;
                    break;
                }
            }
        }
        i++;
    }
    printf("\n\n\nPage Fault:%d\nPage Hit:%d\n",count,(n-count));
    return 0;
}