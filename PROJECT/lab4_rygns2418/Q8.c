	#include <stdio.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <time.h>
	#include <sys/time.h>
	
	int count;
	
	pthread_mutex_t mutex;
	
	void *threadfunc1(void *data)
	{
	int i;
	
	for (i=0;i<1000000;i++)
	{
	pthread_mutex_lock(&mutex);
	count++;
	pthread_mutex_unlock(&mutex);
	}
	}
	
	void* threadfunc2(void* data)
	{
	
	int i;
	pthread_mutex_lock(&mutex);
	for(i=0;i<1000000;i++)
	{count++;
	}
	
	pthread_mutex_unlock(&mutex);
	}
	
	
	int main()
	{
	
	struct timeval t1,t2;
	
	
	int thrid;
	pthread_t p_thread[2];
	int status;
	int a=1;
	
	gettimeofday(&t1,NULL);
	
	pthread_mutex_init(&mutex,NULL);
	count = 0;
	thrid = pthread_create(&p_thread[0],NULL,threadfunc1,(void*)&a);
	sleep(1);
	thrid = pthread_create(&p_thread[1],NULL,threadfunc2,(void*)&a);
	
	
	pthread_join(p_thread[0],(void *) &status);
	pthread_join(p_thread[1],(void *) &status);
	
	status = pthread_mutex_destroy(&mutex);
	
	gettimeofday(&t2,NULL);
	printf("count:%d (if count == 2000000, then counting success)\n\n",count);
	printf("init time : %ld\n",t1.tv_sec);
	printf("finit time : %ld\n\n",t2.tv_sec);
	long C = -(t1.tv_sec-t2.tv_sec);
	printf("running time : %ld\n\n\n",C);
	
	return 0;
	}
