#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main()
{
	int  file = open("memofile.txt",O_WRONLY);

	printf("%d\n",file);


     int pid = fork ();
	if(pid==0)
	{
	printf("printed in child\n");
	write(file,"child writing\n\n",sizeof("child writing"));
	}
	else
	{
	printf("printed in parent");
	write(file,"parent writing\n\n",sizeof("parent writing"));
	}
return 0;
}
