// gcc create.c -o create
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	char *c[]= (char *) calloc(100,sizeof(char[10]));;
	int fd = open("abc.txt",O_RDWR|O_CREAT);
	int sz = read(fd, &c, 100);
	printf("%s\n",c[0]);
	// printf("fd = %d\n",fd);
}