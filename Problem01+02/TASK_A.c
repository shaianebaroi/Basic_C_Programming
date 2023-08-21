#include <stdio.h>
#include <string.h>

int subtraction(int first_num, int second_num){
    int result = first_num - second_num;
    printf ("%d\n", result);
}

int addition(int first_num, int second_num){
    int result = first_num + second_num;
    printf ("%d\n", result);
}

int multiplication(int first_num, int second_num){
    int result = first_num * second_num;
    printf ("%d\n", result);
}

int main ()
{
    //TAKING INPUTS
    int first_num;
    printf("Enter First Number: ");
    scanf("%d", &first_num);
    //printf("%d\n", first_num);
    
    int second_num;
    printf("Enter Second Number: ");
    scanf("%d", &second_num);
    //printf("%d\n", second_num);
    
    char operator_type[1];
    printf("Enter Operator: ");
    scanf("%s", operator_type);
    //printf("%s\n", operator_type);

    if (first_num > second_num) {
        subtraction(first_num, second_num);
    }
    
    else if (second_num > first_num){
        addition(first_num, second_num);
    }
    
    else if (second_num == first_num){
        multiplication(first_num, second_num);
    }
    
    return 0;
}
