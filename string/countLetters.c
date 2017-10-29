#include <stdio.h>
#include <stdlib.h>


int main() {
    char stringArray[100];
    char charsArray[26] = {"qwertyuiopasdfghjklzxcvbnm"};
    char lettersArray[26] = {0};
    int countCharsArray[26] = {0};
    int count = 0;
    int numberOfDuplicateLetters;
    
    gets(stringArray);
    
    for(int k = 0, i = 0; i < 26; k++, i++){
        count = 0;
        
        for(int j = 0; j < strlen(stringArray); j++){
            
            if(stringArray[j] == charsArray[i]){
                count++;
            }
        }
        
        if(count > 0){
            lettersArray[k] = charsArray[i];
            countCharsArray[k] = count;
            numberOfDuplicateLetters++;
        }
    }
    
    for(int i = 0 ; i < 26; i++) {
        
        for(int j = 0 ; j < 26 - i ; j++) {
            
            if(countCharsArray[j] < countCharsArray[j+1]) {
                int sortNumerOfLeters = countCharsArray[j];
                char sortLetters = lettersArray[j];
                countCharsArray[j] = countCharsArray[j+1];
                lettersArray[j] = lettersArray[j+1];
                countCharsArray[j+1] = sortNumerOfLeters;
                lettersArray[j+1] = sortLetters;
            }
        }
    }
    
    for(int i = 0; i < numberOfDuplicateLetters; i++){
        printf("%d - %c\n", countCharsArray[i], lettersArray[i]);
    }
    
    return 0;
}

