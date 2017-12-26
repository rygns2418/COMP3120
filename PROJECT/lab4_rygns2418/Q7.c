#include <stdio.h>
#include <sys/time.h>

int main(void)
{

	int i = 0;
	struct timeval time1,time2,result;

	gettimeofday(&time1,NULL);
	while(1)
	{

	if(i==500000000)
	break;

	i++;
continue;
	}

gettimeofday(&time2,NULL);

printf("init time : %ld\n",time1.tv_sec);
printf("finit time : %ld\n\n",time2.tv_sec);
printf("running time : %ld",time2.tv_sec-time1.tv_sec);


}
