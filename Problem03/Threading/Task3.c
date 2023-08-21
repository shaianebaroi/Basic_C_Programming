#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdbool.h>
#include<string.h>

int sum;
void *ascii_adder(void* arg) {
	char *username = arg;
	sum = 0;
	for (int count = 0; count < strlen(username); count++) {
		sum += username[count];
	}
	pthread_exit(&sum);
}

int main()
{	
	//CREATING THREE THREADS
	pthread_t thread[3];
	int total[3];
	int *ret[3];
	
	//ENTERING THREE NAMES FOR THREE THREADS
	for(int count = 0; count < 3; count++){
		char name[50];
		printf("Please enter the names of the users: \n");
		scanf("%s", name);
		
		pthread_create(&thread[count], NULL, (void *) ascii_adder, name);
		pthread_join(thread[count], (void**)&(ret[count]));
		
		total[count] = *ret[count];
		//printf("The ASCII count is: %d \n", total[count]);
	}
	
	if(total[0] == total[1] && total[1] == total[2]){
		printf("Youreka \n");
	}
	
	else if(total[0] == total[1] || total[0] == total[2] || total[1] == total[2]) {
		printf("Miracle \n");
	}
	else
	{
		printf("Hasta La Vista\n");
	}
	return 0;
}




