#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

#define SIZE_ARRAY 100

void swap(char* xp, char* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortAscending(int lengthNumber, char* str){
    for (int i = 0; i < lengthNumber; i++) {
        for (int j = 0; j < lengthNumber - i; j++) {
            if (str[j] < str[j + 1]) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

void sortDescending(int lengthNumber, char* str){
    for (int i = lengthNumber - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (str[j] > str[j + 1]) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

void sortNegativeNumberB(int lengthNumber, char* str){
    for (int i = 0; i < lengthNumber; i++) {
        for (int j = 1; j < lengthNumber - i; j++) {
            if (str[j] < str[j + 1]) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

void sortNegativeNumberA(int lengthNumber, char* str){
    for (int i = lengthNumber - 1; i >= 0; i--) {
        for (int j = 1; j < i; j++) {
            if (str[j] > str[j + 1]) {
                swap(&str[j], &str[j + 1]);
            }
        }
    }
}

void sortA(char* stringOfNumberA) {
    int lengthNumber = strlen(stringOfNumberA);

    /*
     * checking the number A on negativity,
     * if the number negatively calls a function that sorts the number without the minus sign
     */
    if(stringOfNumberA[0] == '-') {
        sortNegativeNumberA(lengthNumber, stringOfNumberA);
        return;
    }

    sortAscending(lengthNumber, stringOfNumberA);

}

void sortB(char* stringOfNumberB) {
    int lengthNumber = strlen(stringOfNumberB);

    /*
     * checking the number B on negativity,
     * if the number negatively calls a function that sorts the number without the minus sign
     */
    if(stringOfNumberB[0] == '-') {
        sortNegativeNumberB(lengthNumber, stringOfNumberB);
        return;
    }

    sortDescending(lengthNumber, stringOfNumberB);
}

int main() {
    char* stringOfNumberA = new char[SIZE_ARRAY];
    char* stringOfNumberB = new char[SIZE_ARRAY];
    int numberOfA = 0;
    int numberOfB = 0;
    int result = 0;

    cout << "Enter A: ";
    cin >> stringOfNumberA;
    cout << "Enter B: ";
    cin >> stringOfNumberB;

    cout << endl;

    sortA(stringOfNumberA);
    sortB(stringOfNumberB);

    cout << stringOfNumberA << endl;
    cout << stringOfNumberB << endl;

    numberOfA = atoi(stringOfNumberA);
    numberOfB = atoi(stringOfNumberB);

    result = numberOfA - numberOfB;

    cout << result << endl;

    delete stringOfNumberA;
    delete stringOfNumberB;

    return 0;
}

