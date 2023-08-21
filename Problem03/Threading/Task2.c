#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h> 

int var = 0;
int count = 0;
void* block3 (void* arg)
{
	var++;
}

int main()
{
	pthread_t thread[5];
	for (int i = 0; i < 5; i++)
	{
		pthread_create(&thread[i], NULL, block3, NULL);
		for (int j = 0; j < 5; j++){
			++count;
			printf("Thread %d prints %d. \n", i, count);
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		pthread_join(thread[i], NULL);
		//printf("Thread: %d has ended.\n", i);
	}
	return 0;
} 
