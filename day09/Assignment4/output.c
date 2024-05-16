#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int ret1,ret2,ret3,ret4,ret5,ret6,err, s1,s2,s3,s4,s5,s6;

	ret1=fork();
	if(ret1==0)
	{
		err=execlp("gcc","gcc","-c","circle.c",NULL);
		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}

	else
	{
		waitpid(ret1,&s1,0);
		printf("child exit status: %d\n", WEXITSTATUS(s1));
	}

	ret2=fork();
	if(ret2==0)
	{
		err=execlp("gcc","gcc","-c","rectangle.c",NULL);
		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
	{
		waitpid(ret2,&s2,0);
		printf("child exit status: %d\n", WEXITSTATUS(s2));
	}

	ret3=fork();
	if(ret3==0)
	{
		err=execlp("gcc","gcc","-c","square.c",NULL);
		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
	{
		waitpid(ret3,&s3,0);
		printf("child exit status: %d\n", WEXITSTATUS(s3));
	}

	ret4=fork();
	if(ret4==0)
	{
		err=execlp("gcc","gcc","-c","main.c",NULL);
		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
	{
		waitpid(ret4,&s4,0);
		printf("child exit status: %d\n", WEXITSTATUS(s4));
	}

	ret5=fork();
	if(ret5==0)
	{
		err=execlp("gcc","gcc","-o","program.out","circle.o","square.o","rectangle.o","main.o",NULL);

		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
	{
		waitpid(ret5,&s5,0);
		printf("child exit status: %d\n", WEXITSTATUS(s5));
	}

	ret6=fork();
	if(ret6==0)
	{
		err=execlp("./program.out","./program.out", NULL);
		if(err < 0) 
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
	{
		waitpid(ret6,&s6,0);
		printf("child exit status: %d\n", WEXITSTATUS(s6));
	}	
  // }
return 0;

}
