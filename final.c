#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void main(){
	int fd, size, n=0,i=0;
	char value[10],buf[10];
	fd = creat("abc.data",S_IRWXU);
	// char a[10][10]={"Deon","Georgy","Mani"};
	fd = open("abc.data",O_RDWR|O_CREAT);
	// int sz = write(fd,a,100);
	printf("Enter the number of names: ");
	scanf("%d",&size);
	printf("Enter the %d names:\n",size);
	
	while(size>0){
		scanf("%s",value);
		write(fd, value, strlen(value));
		write(fd,"\n",strlen("\n"));
		size--;
		}

	lseek(fd,0,SEEK_SET);
	printf("\nThe names starting with 'S' are as follows:\n");
	while(read(fd,&buf[i],1)==1){
		if(buf[i]=='\n'){
			if(buf[0]=='s' || buf[0]=='S'){
				printf("%s\n",buf );
				// n++;
				}
			i=0;
			continue;
			}
		i++;
		}
	}