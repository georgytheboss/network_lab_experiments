// ;gcc create.c -o create
#include <stdio.h>
#include <fcntl.h>

void main(){
	char *c = (char *) calloc(100,sizeof(char));
	int fd = open("abc.txt",O_RDWR|O_CREAT);
	// printf("%c\n",fd[0] );
	// printf("fd = %d\n",fd);
}