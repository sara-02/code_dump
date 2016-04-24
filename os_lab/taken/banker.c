#include<stdio.h>

void main()
{
    int available[10][10],need[10][10],allocation[10][10],max[10][10],n,m,i,j,a=0,k,l,request[10],flag,rqst;
    char ch,status[10],processes[10][10],r[10],req='n';
    FILE *fp;
    fp=fopen("process_file.txt","r+");
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&m);
    for(i=0;i<n;i++)
        fscanf(fp,"%s",&processes[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fscanf(fp,"%d",&allocation[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fscanf(fp,"%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    for(j=0;j<m;j++)
        fscanf(fp,"%d",&available[0][j]);
    for(i=0;i<n;i++)
        status[i]='f';
    
restart:
   
    for(k=0;k<n;k++)
    {
    for(i=0;i<n;i++)
    {
        ch='t';
        if(status[i]=='f')
        {
            for(l=0;l<m;l++)
                if(need[i][l]>available[a][l])
                    ch='f';
            if(ch=='t')
            {
                status[i]='t';
                a++;
                for(j=0;j<m;j++)
                {
                    available[a][j]=available[a-1][j]+allocation[i][j];
                }
                puts(processes[i]);
            }
        }
    }
    }
    
    
    printf("\nAllocation matrix is:\n");
    printf("          ");
    for(i=0;i<m;i++)
        printf("R%d ",i);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        
        printf("%7s  ",processes[i]);
        for(j=0;j<m;j++)
        {
            printf("%2d ",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\nMaximum matrix is:\n");
    printf("          ");
    for(i=0;i<m;i++)
        printf("R%d ",i);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        
        printf("%7s  ",processes[i]);
        for(j=0;j<m;j++)
        {
            printf("%2d ",max[i][j]);
        }
        printf("\n");
    }    
    printf("\nNeed matrix is:\n");
    printf("          ");
    for(i=0;i<m;i++)
        printf("R%d ",i);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        
        printf("%7s  ",processes[i]);
        for(j=0;j<m;j++)
        {
            printf("%2d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable matrix is:\n");
    printf("          ");
    for(i=0;i<m;i++)
        printf("R%d ",i);
    printf("\n\n");
    for(i=0;i<a;i++)
    {
        
        printf("%7s  ",processes[i]);
        for(j=0;j<m;j++)
        {
            printf("%2d ",available[i][j]);
        }
        printf("\n");
    }
    printf("         ");
    for(j=0;j<m;j++)
        printf("%2d ",available[a][j]);
    printf("\n");
    flag=1;
    for(i=0;i<n;i++)
        if(status[i]=='f')
            flag==0;
    if(flag==0)
        printf("System is not safe \n");
    else
        printf("System is safe )\n");
   /* printf("\nIs there any request?(y/n):");
    scanf("%c",&req);
    if(req=='y')
    {
        rqst=0;
        printf("\n\nProcessing Request...\nProcess number:");
        scanf("%d",&r);
        printf("Enter resource:")
        for(j=0;j<m;i++)
            scanf("%d",&request[j]);
        for(i=0;i<n;i++)
        {
            if(i==r)
               {
            for(j=0;j<m;j++)
            {
                if(request[j]>need[i][j] || request[j]>available[0][j])
                {
                    printf("Request not Granted...");
                    rqst=1;
                    exit(0);
                }
                a=i;
            }
               }
        }   
        if(rqst==0)
               {
                   for(j=0;j<m;j++)
                   {
                       allocation[a][j]+=request[j];
                       available[0][j]-=request[j];
                   }
               }
               a=0;
        goto restart;
    }*/
    
}