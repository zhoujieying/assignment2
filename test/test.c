#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<linux/time.h>
int main(){
	struct timespec time;
	int y =2;
	y=syscall(326,&time);
	printf("syscall return value :%d\n",y);
	printf("Time= %d \n",time.tv_sec);

	return 0;
}
