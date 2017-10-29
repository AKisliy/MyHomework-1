#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const int NUMBER_OF_SYMBOL = 930000;
    const char *SEPARATORS = {"|!?.,;/*-+{}[]\'@#$%^&()=~1234567890<>№_` "};
    char stringArray[NUMBER_OF_SYMBOL];
    char* wordArray[NUMBER_OF_SYMBOL];
    char* str;
    int count = 0;
    
    printf("Enter string:\n");
    gets(stringArray);
    
    str = strtok(stringArray, SEPARATORS);
 
    while (str != NULL) {
        wordArray[count] = str;
        count++;
        str = strtok(NULL, SEPARATORS);
    }
    
    printf("Words of the string:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", wordArray[i]);
    }
    
    printf("Number of words - %d", count);
    return 0;
}


