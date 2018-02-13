// gcc create.c -o create
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void main(){
	char a[10][10]={"Deon","Georgy","Mani"};
	int fd = open("abc.data",O_RDWR|O_CREAT);
	int sz = write(fd,a,100);
}