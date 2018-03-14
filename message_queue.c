#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>

void main(){
	int msgid,p,i,f=0;
	char buf[50];
	struct mymsg{
		long mtype;
		char mtext[50];
		}msg,msg2;

	msgid=msgget(IPC_PRIVATE,0777|IPC_CREAT);
	if(msgid==2){
		printf("Fail");
		exit(2);
		}
	p=fork();
	if(p==-1){
		printf("Fork");
		exit(1);
		}
	while(1){
		if(p==0){
			sleep(1);
			printf("\nChild: ");
			fgets(msg.mtext,50,stdin);
			msg.mtype=1;
			msgsnd(msgid,&msg,50,0);
			sleep(1);
			msgrcv(msgid,&msg2,50,0,IPC_NOWAIT);
			printf("\nCHILD->PARENT : %s\n", msg2.mtext);
			sleep(1);
			printf("Parent:");
			fgets(msg2.mtext,50,stdin);
			msg2.mtype=2;
			msgsnd(msgid,&msg2,50,0);
			sleep(1);
			msgrcv(msgid,&msg,50,0,IPC_NOWAIT);
			printf("\nParent->Child : %s",msg.mtext);
			}
		}
	}
 