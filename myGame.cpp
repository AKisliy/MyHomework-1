#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
    int randVaule;
    int num;
    char selector;

    for(;;){
        srand(time(NULL));
        randVaule = rand() % 10;

        for(int i = 0; i < 3; i++){
            for(;;){
                printf("Enter positive number: ");
                int newNum = scanf("%d", &num);
				
                if(newNum){
                } else {
                    printf("Oops, you enter not number!\n");
                    fflush(stdin);
                    continue;
                }

                if(num < 0){
                    printf("Oops, your number is negative!\n");
                    continue;
                }
                break;
            }

            if(randVaule < num){
                printf("Smaller!\n");
            }

            if(randVaule > num){
                printf("Bigger!\n");
            }

            if(randVaule == num){
                printf("Winer\n");
		return 0;
            }   
        }

        printf("Continue(y/n): ");
        scanf("%s", &selector);
        if(selector == 'y'){
            return 0;
	} else continue;
    }
    return 0;
}
