#include<stdio.h>
int burst[10],arr[10],wait[10],priority[10],n;
char process[10][10];
int bur[10],burst_total=0,waiting_total=0,turn=0,min;

int main()
{
    FILE *fp;
    int i,time=0,j,k,flag;
    fp=fopen("pp1.txt","r");
    
    fscanf(fp,"%d",&n);
    printf("The number of processes = %d\n",n);
    
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s %d %d %d",process[i],&burst[i],&arr[i],&priority[i]);
        wait[i]=0;
        bur[i]=burst[i];
    }
    min=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    
    printf("\n---------------------------------");
    printf("\nPROCESS\tBURST\tARRIVAL\tPRIORITY");
    printf("\n---------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf(" %s\t  %d  \t  %d\t  %d\n",process[i],burst[i],arr[i],priority[i]);
    }
    printf("---------------------------------\n");
    
    i=-1,j=0,flag=0,k=0;
    
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    
    while(1)
    {
        
        for(j=0;j<n;j++)
                if(j!=i&&burst[j]!=0&&arr[j]<=time&&priority[j]<priority[i])
                {
                    i=j;
                }
        
        if(burst[i]==0)
            for(i=0;i<n;i++)
                if(burst[i]!=0)
                    break;
        
        for(j=0;j<n;j++)
        {
            if(i!=j&&burst[j]!=0)
                wait[j]++;
        }
        
        if(burst[i]!=0)
        {
            burst[i]--;
            printf("  %s ",process[i]);
        }
        flag=1;
        
        for(k=0;k<n;k++)
        {
            if(burst[k]!=0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            break;
        
        time++;
    }
    
    /*for(i=0;i<n;i++)
        printf("%s %d %d\n",process[i],wait[i],burst[i]);
    */
    
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    
    for(i=0;i<=time+1;i++)
    {
        printf("%2d   ",i);
    }
    
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    
    for(i=0;i<n;i++)
    {
        burst_total+=bur[i];
        waiting_total+=(wait[i]-arr[i])+min;
    }
    turn=waiting_total+burst_total;
    
    printf("\n\nAverage waiting time = %0.2f\n",(float)waiting_total/n);
    printf("Average turn around time = %0.2f\n",(float)turn/n);
    
    return 1;
    printf("Average waiting time = %f\n",(float)waiting_total/n);
}