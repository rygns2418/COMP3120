#include <stdio.h>
#include <stdlib.h>

int main()
{

int pid=fork();

	if(pid==0)//child
	{
	int A = wait();
	printf("child process\n\n");
	printf("wait() returns %d\n\n",A);
	}
	else
	{
	
	printf("parent process\n\n");
	
	}

return 0;

}
