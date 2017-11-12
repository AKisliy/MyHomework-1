#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define ENG_LETTERS 26

char* getInputString(int size){
    char* array = (char*) malloc(size);
    printf("Enter string:\n");
    gets(array);
    return array;
}

void encrypt (int key, unsigned char* stringArray){
    
    int strLen = strlen(stringArray);
      
    for(int i = 0; i < strLen; i++){
                   
        if ((stringArray[i] >= 'A') && (stringArray[i] <= 'Z')){

            stringArray[i] = stringArray[i] + (key % ENG_LETTERS);
            

            if (stringArray[i] > 'Z'){
                stringArray[i] = 'A' + (stringArray[i] - 'Z') - 1;

            }
        }

        if ((stringArray[i] >= 'a') && (stringArray[i] <= 'z')){
            
            stringArray[i] = stringArray[i] + (key % ENG_LETTERS);

            if (stringArray[i] > 'z'){
                stringArray[i] = 'a' + (stringArray[i] - 'z') - 1;

            }
        }
    }
}

void decrypt(int key, unsigned char* stringArray){
    
    int strLen = strlen(stringArray);

    for(int i = 0; i < strLen; i++){
          
        if (stringArray[i] >= 'A' && stringArray[i] <= 'Z'){
            
            stringArray[i] = stringArray[i] - (key % ENG_LETTERS);
            
            if (stringArray[i] < 'A') {
                stringArray[i] = 'Z' - ('A' - stringArray[i]) + 1;

            }
        }
        
        if (stringArray[i] >= 'a' && stringArray[i] <= 'z'){
            
            stringArray[i] = stringArray[i] - (key % ENG_LETTERS);
            
            if (stringArray[i] < 'a') {
                stringArray[i] = 'z' - ('a' - stringArray[i]) + 1;

            }
        }
    }
}

void userChoice(int selector, unsigned char* stringArray, int key){
    const int ENCRYPT = 1;
    const int DECRYPT = 2;
    
    if(selector == ENCRYPT){
        
        encrypt(key, stringArray);
        
        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
    
    if(selector == DECRYPT){
        
        decrypt(key, stringArray);
        
        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
}

int main() {
    unsigned char* stringArray = getInputString(1000000);
    int selector;
    int key;

    printf("Please, enter key(integer): ");
    scanf("%d", &key);
    
    printf("If you want to encrypt this string enter (1), if you want to decrypt enter (2): ");
    scanf("%d", &selector);
    
    userChoice(selector, stringArray, key);
    
    free(stringArray);
    
    return 0;
}
