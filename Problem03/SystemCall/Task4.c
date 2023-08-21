#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(){

	char *array[] = {"/","1","2","3","4","5",NULL};
	int status;
	pid_t pid = fork();
	
	//CHILD PROCESS
	if(pid == 0) { 
		//SORTING HERE
		execv("./sort", array); 
		//printf("Child here! \n");
	}
	
	//PARENT PROCESS
	else if (pid > 0) { 
		wait(&status);
		//ODD-EVEN HERE
		execv("./oddeven", array); 
		//printf("Parent here! \n");
	}
	
	//ERROR
	else {
		printf("Fork failed! \n");
		exit(1);
	}
	
}
