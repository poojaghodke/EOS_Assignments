#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,cnt1,cnt2,res,num1,num2;
	char str[32];
	fd1 = open("/tmp/desd_fifo1",O_RDONLY);
	if(fd1 < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	printf("waiting for data........\n");

	cnt1= read(fd1,&num1,sizeof(num1));
	printf("num1 read:%d bytes %d\n",cnt1,num1);
	cnt2= read(fd1,&num2,sizeof(num2));
	printf("num2 read:%d bytes %d\n",cnt2,num2);
	close (fd1);
	
	res=num1+num2;
	fd2 = open("/tmp/desd_fifo2",O_WRONLY);
	if(fd2 < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	cnt1= write(fd2,&res,sizeof(res));
	printf("result is written:%d bytes\n",cnt1);
	close(fd2);
	return 0;
}
