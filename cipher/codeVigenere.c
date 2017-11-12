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

char* getInputKey(int size){
    char* array = (char*) malloc(size);
    printf("Enter key:\n");
    gets(array);
    return array;
}

void encrypt (unsigned char* keyArray, unsigned char* stringArray){
    
    int keyLen = strlen(keyArray);
    int strLen = strlen(stringArray);
        
    for (int i=keyLen; i < strLen; i++){
        keyArray[i]=keyArray[i]+keyArray[i%keyLen];
    }
    
    for(int i = 0; i < strLen; i++){
        
        if (stringArray[i] >= 'A' && stringArray[i] <= 'Z'){
            
            stringArray[i] = stringArray[i] + (keyArray[i] % ENG_LETTERS);

            if (stringArray[i] > 'Z'){
                stringArray[i] = 'A' + (stringArray[i] - 'Z') - 1;

            }
        }

        if (stringArray[i] >= 'a' && stringArray[i] <= 'z'){

            stringArray[i] = stringArray[i] + (keyArray[i] % ENG_LETTERS);

            if (stringArray[i] > 'z'){
                stringArray[i] = 'a' + (stringArray[i] - 'z') - 1;
            }
        }
    }
}

void decrypt(unsigned char* keyArray, unsigned char* stringArray){
    
    int keyLen = strlen(keyArray);
    int strLen = strlen(stringArray);
    
    for (int i=keyLen; i < strLen; i++){
        keyArray[i]=keyArray[i]+keyArray[i%keyLen];
    }

    for(int i = 0; i < strLen; i++){
          
        if (stringArray[i] >= 'A' && stringArray[i] <= 'Z'){
            
            stringArray[i] = stringArray[i] - (keyArray[i] % ENG_LETTERS);
            
            if (stringArray[i] < 'A') {
                stringArray[i] = 'Z' - ('A' - stringArray[i]) + 1;

            }
        }
        
        if (stringArray[i] >= 'a' && stringArray[i] <= 'z'){
            
            stringArray[i] = stringArray[i] - (keyArray[i] % ENG_LETTERS);
            
            if (stringArray[i] < 'a') {
                stringArray[i] = 'z' - ('a' - stringArray[i]) + 1;
            }
        }
    }
}

void userChoice(int selector, unsigned char* stringArray, unsigned char* keyArray){
    const int ENCRYPT = 1;
    const int DECRYPT = 2;
    
    if(selector == ENCRYPT){
        
        encrypt(keyArray, stringArray);
        
        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
    
    if(selector == DECRYPT){
        
        decrypt(keyArray, stringArray);
        
        for(int i = 0; i < strlen(stringArray); i++){
            printf("%c", stringArray[i]);
        }
    }
}

int main() {
    unsigned char* stringArray = getInputString(1000000);
    int selector;
    unsigned char* keyArray = getInputKey(1000000);
    
    printf("If you want to encrypt this string enter (1), if you want to decrypt enter (2): ");
    scanf("%d", &selector);
    
    userChoice(selector, stringArray, keyArray);
    
    return 0;
}