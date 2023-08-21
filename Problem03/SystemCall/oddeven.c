#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
	char *val;
    int array[argc];
    for(int count = 1; count < argc; count++){
        val = argv[count];
        array[count - 1] = (int)(*val - '0');
    }
    
    //ODD-EVEN ALGORITHM
    for(int count = 0; count < argc - 1; count++){

		if(array[count] % 2 == 0){
			printf("%d is even. \n", array[count]);
		}
		else{
			printf("%d is odd. \n", array[count]);
		}
    }
    return 0;
}
