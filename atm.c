#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int const NUMBER_OF_ACCOUNTS = 5000;
    int const ADMIN_PIN = 1234;
    int const MIN_PINCODE_VALUE = 1000;
    int const MAX_PINCODE_VALUE = 9999;
    int const CHECK_BALANCE = 1;
    int const TOP_UP_THE_BALANCE = 2;
    int const WITHDRAW_CASH = 3;
    int const EXIT = 4;
    int const NUMBER_OF_ATTEMPTS = 3;
    int pincode[NUMBER_OF_ACCOUNTS];
    int client[NUMBER_OF_ACCOUNTS];
    int password;
    
    srand(time(NULL));
    
    for(int i = 0; i < NUMBER_OF_ACCOUNTS; i++){
        pincode[i] = 1000 + rand() % 8999;  // pin codes range from 1000 to 9999
    }
     
    for(int j = 0; j < NUMBER_OF_ACCOUNTS; j++){
        client[j] = rand() % 1000;  // customer balance range from 0 to 1000
    }
    
    for(int k = 0; k < NUMBER_OF_ATTEMPTS; k++){
        for(;;){
            printf("Enter pin-code: ");
            int newPincode = scanf("%d", &password);
       
            if(newPincode){
                if((password < MIN_PINCODE_VALUE) || (password > MAX_PINCODE_VALUE)){
                printf("You entered an incorrect pin code\n");
                continue;
                }
            }else {
                printf("You entered an incorrect pin code\n");
                scanf("%*[^\n]");
                continue;
            }
        break;
        }
        
        if(password == ADMIN_PIN){
            char selector;
            for(int j = 0; j < NUMBER_OF_ACCOUNTS; j++){
                printf("%d\n", client[j]);
            }
            
            printf("Do you want to clear customers balance(y/n): ");
            scanf("%s", &selector);
            
            if(selector == 'y'){
                for(int j = 0; j < NUMBER_OF_ACCOUNTS; j++){
                    client[j] = 0;
                    printf("%d\n", client[j]);
                }
                k -= 1;  //reset the number of attempts
                continue;
            } else{
                k -= 1;  //reset the number of attempts
                continue;
            }
        }
        
        for(int i = 0; i < NUMBER_OF_ACCOUNTS; i++){
            if(password == pincode[i]){
                for(;;){
                    int selector;
                    int operation;
                    
                    printf("\tSelect an action\t\n");
                    printf("Check balance(1)\n");
                    printf("Top up the balance(2)\n");
                    printf("Withdraw cash(3)\n");
                    printf("Exit(4)\n");
                    scanf("%d", &selector);
                    
                    if(selector == CHECK_BALANCE){
                        printf("On your account: %d\n", client[i]);
                    }
                    
                    if(selector == TOP_UP_THE_BALANCE){
                        printf("Enter the sum: ");
                        scanf("%d", &operation);
                        client[i] = client[i] + operation;
                    }  
                    
                    if(selector == WITHDRAW_CASH){
                        printf("Enter the sum: ");
                        scanf("%d", &operation);
                        if(operation <= client[i]){
                            client[i] = client[i] - operation;
                        } else printf("There are not enough funds on your account\n");
                    }
                    
                    if(selector == EXIT){
                        return 0;
                    }
                }
            }   
        }
    } 
    return 0;
}

