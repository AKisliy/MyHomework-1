#include <iostream>
#include <stdio.h>

int main() 
{
    int height;
    
    printf("Enter number of floors: ");
    scanf("%d", &height);
    
//triangle(from min to max)    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    
    printf("\n");
    
//triangle(from max to min)   
    for(int i = height; i > 0; i--){
        for(int j = 0; j <= i-1; j++){
            printf("*");
        }
        printf("\n");
    }
    
    printf("\n");
    
//christmas tree    
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= height - i; j++){
            printf(" ");
	}	
 
	for (int j = 1; j <= i * 2 - 1; j++){
            printf("*");
	}			
        printf("\n");
    }
    for(int i = 1; i < height; i++){
            printf(" ");
    }
    printf("*");
}
