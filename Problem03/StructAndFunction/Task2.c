# include <stdio.h>   

void perfect_number_checker(int num) {   
    
    //printf ("%d", num);
    int count;
    int sum = 0;   
    
    for(count = 1 ; count < num ; count++) {   
        if(num % count == 0) {
            sum = sum + count;
        }
    }
    
    if (sum == num) {
        printf("%d \n", num);
    }
}

int main(){
    
    //ENTERING THE RANGE TO CHECK FOR PERFECT NUMBERS
    int lowerlimit;
    printf("Please enter the first number: ");
    scanf("%d", &lowerlimit);
    
    int upperlimit;
    printf("Please enter the second number: ");
    scanf("%d", &upperlimit);
    
    for(int count2 = lowerlimit; count2 < upperlimit; count2++){
        perfect_number_checker(count2);
    }
    
    return 0;
}
    
