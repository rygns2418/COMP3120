#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 30

int main(int argc, char *argv[])
{
	int fd1[2], fd2[2];
	char buffer[BUFSIZE];
	pid_t pid;

	if(pipe(fd1)==-1||pipe(fd2)==-1)
	{
	puts("pipe() error");
	exit(1);
	}

	pid = fork();
	if(pid==-1)
	{
	puts("fork() error");
	exit(1);
	}
	else if(pid==0)
	{
	write(fd1[1], "connection complete!!\n\n",25);
	read(fd2[0], buffer, BUFSIZE);
	printf("Output of child process : %s \n\n", buffer);
	}
	else
	{
	read(fd1[0]),buffer,BUFSIZE);
	printf("Output of parent process : %s \n\n", buffer);
	write(fd2[1],"very good",25);
	sleep(1);
	}
return 0;
}
