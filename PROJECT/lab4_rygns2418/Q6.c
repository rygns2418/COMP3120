#define BUFSIZ 30
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main()
{

	char buffer[BUFSIZ];//make buffer space
	int fd[2];
	int state;
	pid_t pid;
	pid_t pid2;

	pipe(fd);

	pid = fork();

	int childstate =0;

	if(pid==-1)
	{
		printf("ERRor");
	}
	else if(pid==0)
	{
		read(fd[0],buffer,BUFSIZ);
		printf("your input is %d", *buffer);
	}
	else
	{
		pid2 = fork();

		if(pid2==0)
		{int A;
		scanf("%d",&A);

			write(fd[1],&A,25);

		}
		else
		{
		wait();
		close(0);
		}
	}
		return 0;
}
