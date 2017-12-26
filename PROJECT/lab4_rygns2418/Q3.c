#include <stdio.h>

int main()
{

	int pid = fork();
	
	if(pid==0)
	{
	printf("child (this should be first)\n\n");
	}
	else
	{
	sleep(1);
	printf("parent (this should be secondary)\n\n");
	}

return 0;

}
