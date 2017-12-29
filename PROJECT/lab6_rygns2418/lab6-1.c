
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


pthread_mutex_t mutex;

char buff[1048576];


void *threadfunc1(void* data) // check memory usage
{


while(1)
     {
	pthread_mutex_lock(&mutex);

         FILE *fp = fopen(data,"r");
         if(fp==NULL)
         return printf("Process not found\n");

        while(fgets(buff,1048576,fp))//printf memory usage
        { 
        if(strstr(buff,"VmSize"))
                printf("%s\n",buff);
        }
	fclose(fp);

	sleep(1);

	pthread_mutex_unlock(&mutex);
     }

}
int main(int argc, char **argv)
{
	char fname[128];
	sprintf(fname,"/proc/%s/status",argv[1]);

	pthread_t p_thread[2];

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&p_thread[0],NULL,threadfunc1(fname),NULL);

	pthread_join(p_thread[0],NULL);

	return 0;


}
