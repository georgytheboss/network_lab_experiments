// gcc create.c -o create
#include <stdio.h>
#include <fcntl.h>

void main(){
	int fd = creat("abc.data",S_IRWXU);
	// printf("fd = %d\n",fd);
}