#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#include"head.h"

 main()
{
	void *shared_mem= (void *)0;
	int shm_id;  char buff[50];
	struct user_st *new_st;
	
	shm_id=shmget((key_t)1234,sizeof(struct user_st),0666|IPC_CREAT);
	shared_mem=shmat(shm_id,(void *)0,0);
	new_st=(struct user_st *)shared_mem;
	new_st->written=0;
	while(1)
	{
		if(new_st->written)
		{
			printf("you wrote ::  %s",new_st->word);
			printf("\n");
			if(strncmp(new_st->word,"end",3)==0)
				{break;}
			printf("enter some text ::");
			scanf("%s",buff);
			strncpy(new_st->word,buff,50);
			printf("\n");
			new_st->written=0;
			if(strncmp(new_st->word,"end",3)==0)
				break;
			sleep(2);
				
		}
		
	}
	shmdt(shared_mem);
	shmctl(shm_id,IPC_RMID,0);
	exit(1);
}
