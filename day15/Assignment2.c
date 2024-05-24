#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<string.h>

struct array{
	int *arr;
	int size;
};
void sigint_handler(int sig)
{
	printf("SIGINT caught...\n");
	if(gettid() == getpid())	
		_exit(0); 				
	else						
		pthread_exit(NULL);
}

void* thread_func(void* param)
{
	int i,j,temp,size;
	struct array *ptr = (struct array*)param;

	for(i=1; i<=ptr->size; i++)
	{	
		for(j=0;j<(ptr->size-i);j++)
		{
			if(ptr->arr[j]>ptr->arr[j+1])
			{
				temp=ptr->arr[j];
				ptr->arr[j]=ptr->arr[j+1];
				ptr->arr[j+1]=temp;
			}
    	}
	}
	return NULL;
}
int main()
{
	int i,ret;
	struct array a1;
    int arr1[10]={10,20,40,30,70,60,90,80,50,11};
	a1.arr=arr1;
	a1.size=10;
	pthread_t t1;
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT,&sa,NULL);
	if(ret < 0)
	{
		perror("sigaction() failed");
		_exit(1);
	}

	ret = pthread_create(&t1,NULL,thread_func,&a1);
	
	for(i=0; i<10 ; i++)
	{
		printf("a1.arr[%d] = %d\n",i,a1.arr[i]);
		sleep(1);
	}
	pthread_kill(t1,SIGINT);
 	printf("press enter to exit......\n");
	getchar();
	return 0;
}
