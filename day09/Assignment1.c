#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
//int ret;
int signum,pid;
//printf("enter signal number : ");
//scanf("%d",&signum);
//printf("enter process id : ");
//scanf("%d",&pid);
signum=atoi(argv[1]);
printf("%d\n",signum);
pid=atoi(argv[2]);
printf("%d\n",pid);


if(kill(pid, signum) == 0)
{

	printf("successful\n");
}

else
{
 	perror("kill");
	exit(EXIT_FAILURE);

}
return 0;


}
