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

    //CHILD PROCESS
    if (a == 0) {
        pid_t childid = getpid();
        printf ("Child Process ID: %d \n", childid);
        //printf("The PID of this child is: %d \n", childid);
        
        pid_t b = fork();
        pid_t c = fork();
        if (b == 0 | c == 0) {
            pid_t grandchildid = getpid();
            printf ("Grandchild Process ID: %d \n", grandchildid);
            //printf ("Grandchild here! \n");
        }
        else if (b > 0 | c > 0) {
            wait(&status);
            //printf("Child here! \n");
        }

        else {
            perror("Error!");
        }          
        
    }
    
    //PARENT PROCESS
    else if (a > 0) {
        wait(&status);
        pid_t parentid = getpid();
        printf ("Parent Process ID: %d \n", parentid);
        //printf ("Parent here! \n");
    }
    else {
        perror("Error! \n");
    }

    return 0;
}
