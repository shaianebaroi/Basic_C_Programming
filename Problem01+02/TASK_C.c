#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    //TAKING THE PASSWORD AS INPUT
    char password[15];
    printf("Enter Password: ");
    scanf("%s", password);
    

    //CALCULATING THE SIZE OF THE ARRAY
    int size = sizeof(password) - 1;
    //printf("%d\n", size);
    
    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;
    
    char specialchar[] = "_$#@"; 
    
    int count = 0;
    for (count = 0; count < size; ++count) { 
        //printf("%c", password[count]);
        char index = password[count];
        
        //CHECKING FOR UPPERCASE
        if (isupper(index)) {
            //printf ("Upper yes. \n");
            ++uppercase;
        }
        
        //CHECKING FOR LOWERCASE
        else if (islower(index)) {
            //printf ("Lower yes. \n");
            ++lowercase;
        }
        
        //CHECKING FOR DIGIT
        else if (isdigit(index)) {
            //printf ("Number yes. \n");
            ++digit;
        }
        
        //CHECKING FOR SPECIAL CHARACTERS
        else if(strchr(password, '_') != NULL || strchr(password, '$') != NULL || strchr(password, '#') != NULL || strchr(password, '@') != NULL) {
            //printf("special yes. \n");
            ++special;
        }

    }
    
    if (uppercase < 1) {
            printf("Uppercase Missing\n");
        }
        
    if (lowercase < 1) {
        printf("Lowercase Missing\n");
    }
        
    if (digit < 1) {
        printf("Digit Missing\n");
    }
        
    if (special < 1) {
        printf("Special Character Missing\n");
    }
        
    if (uppercase >=1 && lowercase >= 1 && digit >=1 && special >= 1) {
        printf("OK\n");
    }
    
    return 0;
}
