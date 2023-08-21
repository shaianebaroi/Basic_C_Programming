#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char *val;
    int array[argc];
    
    for(int count = 1; count < argc; count++){
        val = argv[count];
        array[count - 1] = (int)(*val - '0');
    }
    
    //SORTING ALGORITHM
    for(int count = argc - 1; count >= 0; count--){
    	for(int count2 = 0; count2 < count; count2++){
    		if(array[count2] < array[count2 + 1]){
    			int temp = array[count2 + 1];
    			array[count2 + 1] = array[count2];
    			array[count2] = temp;
    		}
    	}
    }
    
    //PRINTING IN DESCENDING ORDER
    for(int count = 0; count < argc - 1; count++){
        printf("%d ", array[count]);
    }
    
    printf ("\n");
    
    return 0;
}

