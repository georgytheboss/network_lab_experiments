//gcc sharedmem_output.c -o sharedmem_output
//./sharedmem_output 123789

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(int argc, char *argv[]){
	char *shm;
	key_t key;
	key=atoi(argv[1]);
	shm=(char *)shmat(key,0,0);
	printf("shared memcontents:PROCESS2:%s",shm);
	printf("memid:%d",key);
	}
