#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int main() {
    int pincode[N];
    int client[N];
    int pinc;
    int const ADMIN = 1234;
    int root = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i < N; i++){
        pincode[i] = 1000 + rand() % 8999;
    }
     
    for(int j = 0; j < N; j++){
        client[j] = rand() % 1000;
    }
    
    for(int k = 0; k < 3; k++){
        for(;;){
            printf("Enter pin-code: ");
            int newpinc = scanf("%d", &pinc);
       
            if(newpinc){
                if((pinc < 999) || (pinc > 9999)){
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
        
        if(pinc == ADMIN){
            for(int j = 0; j < N; j++){
                printf("%d\n", client[j]);
            }
            
            printf("Do you want to clear(1/0) ");
            scanf("%d", &root);
            
            if(root == 1){
                for(int j = 0; j < N; j++){
                    client[j] = 0;
                    printf("%d\n", client[j]);
                }
                k = -1;
                continue;
            } else{
                k = -1;
                continue;
            }
        }
        
        for(int i = 0; i < N; i++){
            if(pinc == pincode[i]){
                for(;;){
                    int selector;
                    int operation;
                    
                    printf("\tSelect an action\t\n");
                    printf("Check balance(1)\n");
                    printf("Top up the balance(2)\n");
                    printf("Withdraw cash(3)\n");
                    printf("Exit(4)\n");
                    scanf("%d", &selector);
                    
                    if(selector == 1){
                        printf("On your account: %d\n", client[i]);
                    }
                    
                    if(selector == 2){
                        printf("Enter the sum: ");
                        scanf("%d", &operation);
                        client[i] = client[i] + operation;
                    }  
                    
                    if(selector == 3){
                        printf("Enter the sum: ");
                        scanf("%d", &operation);
                        if(operation <= client[i]){
                            client[i] = client[i] - operation;
                        } else printf("There are not enough funds on your account\n");
                    }
                    
                    if(selector == 4){
                        return 0;
                    }
                }
            }   
        }
    } 
    return 0;
}

