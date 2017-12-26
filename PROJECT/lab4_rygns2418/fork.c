#include <stdio.h>

int main(void)
{
	int X=100;

	int pid = fork();

	if (pid == 0){

		X=123123;

		printf("This is being printed from child process\n");
		printf("Variable X's value is %d",X);
	}
	else{
		X = 321321321;
		printf("This is being printed in parent process\n:");
	printf("- the proces identifier (pid) of the child is %d \n", pid);
		printf("Variable X's value is %d",X);
	}

	return 0;

}
