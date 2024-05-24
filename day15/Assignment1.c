#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<string.h>
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
	int i,j,temp;;
	int *arr = (int*)param;

	for(i=0; i<10 ; i++)
	{	
		for(j=i+1;j<10;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
        }
	}
	return NULL;
}

int main()
{
	int i,ret;
	int arr[10]={10,20,40,30,70,60,90,80,50,11};
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

	ret = pthread_create(&t1,NULL,thread_func,arr);
	
	for(i=0; i<10 ; i++)
	{
		printf("arr[%d] = %d\n",i,arr[i]);
		sleep(1);
	}
	pthread_kill(t1,SIGINT);	
	printf("press enter to exit......\n");
	getchar();
	return 0;
}
