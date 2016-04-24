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
	char buff[100];
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	while(1)
	{
		printf("enter the text:");
		fgets(buff,100,stdin);
		new_st.msg_ty=1;
		strcpy(new_st.word,buff);
		msgsnd(msgid,(void *)&new_st,100,0);
		if(strncmp(buff,"end",3)==0)
			break;

	}
	exit(1);
}
