// gcc create.c -o create
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	char *c= (char *) calloc(100,sizeof(char));;
	int fd = open("abc.data",O_RDWR|O_CREAT);
	int sz = read(fd, c, 100);
	sz = read(fd, c, 100);
	printf("%s\n",c);
	// printf("fd = %d\n",fd);
}