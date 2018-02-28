// queue_reader_writer.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
}message;

void main(){
	key_t key;
	int msgid;
	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Enter Data to be Transmitted: ");
	gets(message.mesg_text);
	msgsnd(msgid, &message, sizeof(message), 0);
	printf("Data send is: %s \n", message.mesg_text);
	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	printf("Data Received is: %s \n", message.mesg_text);
	msgctl(msgid, IPC_RMID, NULL);
	}