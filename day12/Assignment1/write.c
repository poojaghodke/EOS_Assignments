#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,cnt1,cnt2,res;
	int num1,num2;
	fd1 = open("/tmp/desd_fifo1",O_WRONLY);
	if(fd1 < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	printf("enter two numbers : ");
	scanf("%d %d",&num1,&num2);

	cnt1= write(fd1,&num1,sizeof(num1));
	printf("num1 is written:%d bytes\n",cnt1 );
	
	cnt2= write(fd1,&num2,sizeof(num2));
	printf("num2 is written:%d bytes\n",cnt2 );

	close (fd1);
	
	fd2 = open("/tmp/desd_fifo2",O_RDONLY);
	if(fd2 < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	cnt1= read(fd2,&res,sizeof(res));
	printf("result is written:%d\n",res );
	close(fd2);
	return 0;
}
