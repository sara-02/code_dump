#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#include"head.h"

 main()
{
	void *shared_mem=(void *)0;
	int shm_id;char bq[50];
	struct user_st *new_st;
	
	shm_id=shmget((key_t)1234,sizeof(struct user_st),0666|IPC_CREAT);
	shared_mem=shmat(shm_id,(void *)0,0);
	new_st=(struct user_st *)shared_mem;
	new_st->written=1;
	while(1)
	{
		if(new_st->written)
		{
			while(new_st->written)
				sleep(2);
		}       printf("you wrote:: %s\n",new_st->word);
			if(strncmp(new_st->word,"end",3)==0)
				break;
			printf("enter some text::");
			scanf("%s",bq);
			printf("\n");
			strncpy(new_st->word,bq,50);
			new_st->written=1;	
			if(strncmp(new_st->word,"end",3)==0)
				break;
			sleep(2);
			
		
	}
	shmdt(shared_mem);
	shmctl(shm_id, IPC_RMID,0);
	exit(1);
}
