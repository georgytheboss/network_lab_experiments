

//gcc sharedmem_output.c -o sharedmem_output

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(int argc,char *argv[]){
	char *shm,*shm2;
	int shmid;
	key_t key;
	key=IPC_PRIVATE;
	shmid=shmget(key,1000,0666|IPC_CREAT);
	printf("shared memory key= %d \n\n",shmid);
	shm=(char *)shmat(shmid,0,0);
	sprintf(shm,"running \n");
	printf("shared memcontents:PROCESS:%s",shm);
	}