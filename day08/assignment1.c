#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
int main()
{
	int ret,i,s;

	for(i=0;i<5;i++)
	{
		ret= fork();
		printf("child[%d] is created\n",i);
		if(ret==0)
		{
			for(int j=1;j<=5;j++)
			{
				printf("%d\n",j);
				sleep(1);
			}
			_exit(0);
		}

	}

	for(i=0;i<5;i++)
	{
		int child_pid = wait(&s);
		printf("child_pid[%d]=%d\n",i,child_pid);

	}
return 0;
}
