#include <stdio.h>
#include <string.h>

char buff[1048576];

int main(int argc, char **argv)
{
	char fname[128];



	sprintf(fname,"/proc/%s/status",argv[1]);
	FILE *fp = fopen(fname,"r");

	if(fp==NULL)
	 return printf("Process not found\n");

	while(fgets(buff,1048576,fp))
	{
	
       if(strstr(buff,"VmSize"))
	printf("%s\n",buff);
	}

	fclose(fp);
	return 0;


}
