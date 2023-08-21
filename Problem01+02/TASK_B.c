#include <stdio.h>
#include <string.h>

int main ()
{
    //TAKING INPUT INTO AN ARRAY
    char string[100];
    printf("Enter String: ");
    scanf("%[^\n]%*c", string);
    //printf("%s\n", string);
    
    //CALCULATING THE SIZE OF THE ARRAY
    int size = 0;
    while (string[size] != '\0'){
        ++size;
    }
    //printf("%d\n", size);
    
    //LOOP FOR SPLITTING THE STRING AND INSERTING INTO ARRAY
    int count = 0; 
    char *p = strtok (string, " "); 
    char *array[size];
    int words = 0;
    
    while (p != NULL)
    {
        array[count++] = p;
        p = strtok (NULL, " ");
        words++;
    }
    
    //printf("%d", words);
    int count2 = 0;
    for (count2 = 0; count2 < words; ++count2) {
        printf("%s ", array[count2]);
    }
    printf("\n");
    return 0;
}
