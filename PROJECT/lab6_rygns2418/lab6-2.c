#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>




char buff[1048576];
char buff2[1048576];


void *threadfunc1(void* data) // check memory usage
{


 while(1){

         FILE *fp = fopen(data,"r");
      
        while(fgets(buff,1048576,fp))
        { 
        if(strstr(buff,"VmSize"))
                printf("%s\n",buff);
        }
        fclose(fp);

        sleep(1);
	}

}

void *threadfunc2(void* data) // cpu usage
{

        int totaltime;
        int utime;
        int stime;
        char *new_cpu_usage;

    while(1)
  {
        FILE *fp2 = fopen(data,"r");

         fgets(buff2,1048576,fp2);

        new_cpu_usage = strtok(buff2," ");

        for(int i=1;i<14;i++)
        {
        new_cpu_usage = strtok(NULL," ");
        }

        utime = atoi(buff2);

        new_cpu_usage = strtok(NULL," ");
        stime = atoi(buff2);

        totaltime = 10*(utime+stime);

        printf("CPU usage time : %d milisecond \n\n",totaltime);
        fclose(fp2);

        sleep(1);

  } 
        
 }


int main(int argc, char **argv)
{
        char fname[128];
	char fname2[30];

	sprintf(fname,"/proc/%s/status",argv[1]);
        sprintf(fname2,"/proc/%s/stat",argv[1]);
 

	pthread_t p_thread[2];

        pthread_create(&p_thread[0],NULL,threadfunc1,(void*)fname);
	pthread_create(&p_thread[1],NULL,threadfunc2,(void*)fname2);

         pthread_join(p_thread[1],NULL);
	 pthread_join(p_thread[0],NULL);


        return 0;


}
