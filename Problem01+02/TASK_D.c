#include <stdio.h>
#include <string.h>

int main() {
    
    //TAKING THE PASSWORD AS INPUT
    char email[50];
    printf("Enter Email: ");
    scanf("%s", email);
    char old_domain[] = "@kaaj.com";
    char new_domain[] = "@sheba.xyz";
    
    //CALCULATING THE SIZE OF THE EMAIL ARRAY
    int email_size = sizeof(email) - 1;
    //printf("%d\n", email_size);
    
    //CALCULATING THE SIZE OF THE OLD DOMAIN ARRAY
    int old_domain_size = sizeof(old_domain) - 1;
    //printf("%d\n", old_domain_size);
    
    //CALCULATING THE SIZE OF THE OLD DOMAIN ARRAY
    int new_domain_size = sizeof(new_domain) - 1;
    //printf("%d\n", new_domain_size);
    
    //LOOP FOR MATCHING EMAIL STRING WITH DOMAIN STRING
    int count = 0;
    int old_matches = 0;
    int new_matches = 0;
    
    while (count < email_size)
    {
      //printf("%c", email[count]);
      if (email[count] == '@'){
        //printf("\nfound @\n");
        break;
      }
      ++count;
    }
    
    //STORING THIS INDEX WHERE THE DOMAIN STARTS
    int count2 = count;
        
    //MATCHING WITH OLD DOMAIN
    while (count < email_size){
      for (int count3 = 0; count3 < old_domain_size; ++count3) 
      { 
        //printf("%c\n", email[count]);
        //printf("%c\n", old_domain[count3]);
        
        if (email[count] == old_domain[count3]){
          ++old_matches;
          ++count;
        }
        else {
          //MATCHING WITH NEW DOMAIN
          --count;
          for (int count4 = 0; count4 < new_domain_size; ++count4) 
          { 
            //printf("%c\n", email[count]);
            //printf("%c\n", new_domain[count4]);
            
            if (email[count] == new_domain[count4]){
              ++new_matches;
              ++count;
            }
            else {
              goto print;  
            }
          }
        }
      }
    }
    
    print: 
      if (old_matches == old_domain_size) {
        printf("Email address is outdated\n");
      }
      else {
        
        if (new_matches == new_domain_size) {
          printf("Email address is okay\n");
        }
        else {
          printf("Error!\n"); 
        }
      }
    return 0;
  }
