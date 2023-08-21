#include <stdio.h>

int main() {
    //TAKING THE SAMPLE AS INPUT
    char sample[50];
    printf("Enter Sample: ");
    scanf("%s", sample);
    
    //CALCULATING THE SIZE OF THE ARRAY
    int count = 0;
    int size = 0;
    while (sample[count] != '\0'){
        ++size;
        ++count;
    }
    //printf("%d\n", size);
    
    //DECLARING TWO POINTERS:
    //ONE POINTER WILL TRAVERSE FROM THE BEGINNING
    //ONE POINTER WILL TRAVERSE FROM THE END
    int status = 1;
    char *start;
    char *end = &sample[size] - 1;
    for (start = sample; start < &sample[size/2]; start++){
        //printf("%c", *start);
        if (*start == *end){
            --end;
            status = 1;
        }
        else {
            status = 0;
            printf ("Not a palindrome\n");
            break;
        }
    }
    if (status == 1) {
        printf ("Palindrome\n");
    }
    
    return 0;
}

