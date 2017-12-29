#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buff2[1048576];

int main(int argc, char **argv)
{
	int utime;
	int stime;

	char *new_cpu_usage;

        char fname2[30];
        sprintf(fname2,"/proc/%s/stat",argv[1]);


	FILE *fp2 = fopen(fname2,"r");
         if(fp2==NULL)
         return printf("Process not found\n");


         fgets(buff2,1048576,fp2);

	new_cpu_usage = strtok(buff2," ");

	for(int i=1;i<14;i++)
	{
	new_cpu_usage = strtok(NULL," ");
	}


	printf("sentence %s\n",new_cpu_usage); //utime
	utime = atoi(new_cpu_usage);
	printf("integer %d\n",utime);

	new_cpu_usage = strtok(NULL," ");
	printf("sentence %s\n",new_cpu_usage); // stime
	stime = atoi(new_cpu_usage);
	printf("integer %d\n\n",stime);
	

 fclose(fp2);

return 0;

}
