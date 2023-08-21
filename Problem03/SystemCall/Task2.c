#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void main() {
    pid_t pid, pid2;
    int status;
    
    pid = fork();
    
    
    //CHILD PROCESS
    if (pid == 0) { 
        pid2 = fork();
        
        if(pid2 == -1){
        printf("fork failed \n");
        exit(1);
        }
        
        //GRANDCHILD PROCESS
        if (pid2 == 0) { 
            printf("I am grandchild \n");
        }
        
        //CHILD PROCESS
        else {
            wait(&status);
            printf("I am child \n");
        }
    }
    
    //PARENT PROCESS
    else if (pid > 0) {
        wait(&status);
        printf("I am parent \n");
    }
    
    //FORK FAILED
    else {
        printf("fork failed \n");
        exit(1);
    }
    
}
