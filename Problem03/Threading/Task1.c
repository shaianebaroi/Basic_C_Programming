#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h> 

int var = 0;
void* block3 (void* arg)
{
	var++;
}

int main()
{
	pthread_t thread [6];
	for (int i = 1; i < 6; i++)
	{
		pthread_create(&thread[i], NULL, block3, NULL);
		pthread_join(thread[i], NULL);
		printf("thread-%d running \n", i);
		printf("thread-%d closed \n", i);
	} 
}
