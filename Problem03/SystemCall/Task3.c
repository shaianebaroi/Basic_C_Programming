#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
    
    int status;
    pid_t a = fork();
    pid_t b = fork();
    pid_t c = fork();
    
    //CHILD PROCESS
    if (a == 0 | b == 0 | c == 0) {
        printf("Child here! \n");
        
        
        pid_t childid = getpid();
        //printf("The PID of this child is: %d \n", childid);
        
        if (childid % 2 != 0){
            
            //GRANDCHILD PROCESS 
            pid_t d = fork();
            
            if (d == 0) {
                printf("Grandchild here! \n");
            }
            
            else if (d > 0) {
                wait(&status);
                //printf("Child here! \n");
            }
            
            else {
                perror("Error!");
            }          
        }
    }
    
    //PARENT PROCESS
    else if (a > 0 | b > 0 | c > 0) {
        wait(&status);
        printf ("Parent here! \n");
    }
    
    else {
        perror("Error! \n");
    }

    return 0;
}
