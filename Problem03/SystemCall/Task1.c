#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int fd;
    fd = open("output1.txt", O_CREAT | O_RDWR, 0666);
    
    char input[80];
    while (fd != -1){
    
    	printf("Please input strings: ");  
    	scanf("%s", input);
    	//printf("The input enterred is: %s \n", input);	
    	
	char str1[] = "-1";
	int result = strcmp(input, str1);
	//printf ("%d", result);
	
	if (result == 0){
		break;
	}
	
	char space[] = "\n";
	write (fd, &input, strlen(input));
	write(fd, space, strlen(space));
    }
    return 0;
}

