#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<errno.h>
#include<string.h>

struct user_st
{
	long int msg_ty;char word[100];
};
int main()
{
	struct user_st new_st;
	int msgid;
	long int ms_rc=0;
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	while(1)
	{
		msgrcv(msgid,(void *)&new_st,100,ms_rc,0);
		
		printf("you wrote ::%s",new_st.word);
		if(strncmp(new_st.word,"end",3)==0)
			break;

	}
	msgctl(msgid,IPC_RMID,0);
	exit(1);
}
