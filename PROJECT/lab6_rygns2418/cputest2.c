#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

pthread_mutex_t mutex;

char buff2[1048576];



void *threadfunc2(void* data) // cpu usage
{

pthread_mutex_lock(&mutex);

  while(1){

        int totaltime;
        int utime;
        int stime;

        char *new_cpu_usage;

        FILE *fp2 = fopen(data,"r");

         fgets(buff2,1048576,fp2);

        new_cpu_usage = strtok(buff2," ");

        for(int i=1;i<14;i++)
        {
        new_cpu_usage = strtok(NULL," ");
        }

        utime = atoi(new_cpu_usage);

        new_cpu_usage = strtok(NULL," ");

        stime = atoi(new_cpu_usage);

        totaltime = 10*(utime+stime);

        printf("total time %d milisecond \n\n",totaltime);
        fclose(fp2);

        sleep(1);
        pthread_mutex_unlock(&mutex);
	}
 }

int main(int argc, char **argv)
{
        char fname2[30];

        sprintf(fname2,"/proc/%s/stat",argv[1]);
 

        pthread_t p_thread[2];

        pthread_mutex_init(&mutex,NULL);

        pthread_create(&p_thread[1],NULL,threadfunc2(fname2),NULL);
       
         pthread_join(p_thread[1],NULL);


        return 0;


}

