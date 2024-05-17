#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int arr1[2],arr2[2],ret,ret1,ret2,res,s;
	int num1, num2;
	ret1 = pipe(arr1);
	ret2 = pipe(arr2);
	if(ret < 0) {
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		// child -- writer process
		close(arr1[0]);
		printf("child: enter two numbers: ");
		scanf("%d %d", &num1,&num2);
		ret1 = write(arr1[1], &num1, sizeof(num1));
		printf("child: num1 written in pipe: %d bytes\n", ret1);
		ret1 = write(arr1[1], &num2, sizeof(num2));
		printf("child: num2 written in pipe: %d bytes\n", ret1);
		close(arr1[1]); 
		
		close(arr2[1]);
		ret2 = read(arr2[0], &res, sizeof(res));
		printf("child: result read from pipe: %d\n", res);
		close(arr2[0]);

	}
	else {
		// parent -- reader process
		close(arr1[1]);
		printf("parent: waiting for data...\n");
		ret1 = read(arr1[0], &num1, sizeof(num1));
		printf("parent: num1 read from pipe: %d bytes -- %d\n", ret1, num1);
		ret1 = read(arr1[0], &num2, sizeof(num2));
		printf("parent: num2 read from pipe: %d bytes -- %d\n", ret1, num2);
		close(arr1[0]);
		
		res=num1+num2;
		close(arr2[0]);
	    ret2 = write(arr2[1], &res, sizeof(res));
		printf("parent: result written in pipe: %d bytes\n", ret2);
		close(arr2[1]);
	}
	
		waitpid(-1, &s, 0);
	return 0;
}
