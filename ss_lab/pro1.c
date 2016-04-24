#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/shm.h>
#include"head1.h"

int main()
{   
	void * shared_mem=(void *)0;
	int shm_id;int i;
	struct user_st *new_st;
	
	shm_id=shmget((key_t)1234,sizeof(struct user_st),0666|IPC_CREAT);
	shared_mem=shmat(shm_id,(void *)0,0);
	new_st=(struct user_st *)shared_mem;
	new_st->f1=1;
	new_st->f2=0;new_st->f3=0;new_st->f4=0;
	
	while(1)
	{
		if(new_st->f4==1)
		{
			for(i=0;i<new_st->n;i++)
				printf("%d\n",new_st->arr[i]);
			new_st->f2=1;
			break;
		}
		if(new_st->f1==1)
		{
			printf("enter the number of elements");
			scanf("%d",&i);
			new_st->n=i;
			new_st->f1=0;new_st->f2=1;
		}
	}
	shmdt(shared_mem);
	shmctl(shm_id,IPC_RMID,0);
	return 1;
}
	
	

