#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

#define ARRAY_SIZE 100

void swap(char* xp, char* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int lengthNumber, char* str, char number){
    for (int i = lengthNumber - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            switch (number) {
            case 'A':
                if (str[j] < str[j + 1]) {
                    swap(&str[j], &str[j + 1]);
                }
                break;
            case 'B':
                if (str[j] > str[j + 1]) {
                    swap(&str[j], &str[j + 1]);
                }
                break;
            default:
                break;
            }

        }
    }
}

void sortNegativeNumber(int lengthNumber, char* str, char number){
    for (int i = lengthNumber - 1; i >= 0; i--) {
        for (int j = 1; j < i; j++) {
            switch (number) {
            case 'B':
                if (str[j] < str[j + 1]) {
                    swap(&str[j], &str[j + 1]);
                }
                break;
            case 'A':
                if (str[j] > str[j + 1]) {
                    swap(&str[j], &str[j + 1]);
                }
                break;
            default:
                break;
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
        sortNegativeNumber(lengthNumber, stringOfNumberA, 'A');
        return;
    }

    sort(lengthNumber, stringOfNumberA, 'A');

}

void sortB(char* stringOfNumberB) {
    int lengthNumber = strlen(stringOfNumberB);

    /*
     * checking the number B on negativity,
     * if the number negatively calls a function that sorts the number without the minus sign
     */
    if(stringOfNumberB[0] == '-') {
        sortNegativeNumber(lengthNumber, stringOfNumberB, 'B');
        return;
    }

    sort(lengthNumber, stringOfNumberB, 'B');
}

int main() {
    char* stringOfNumberA = new char[ARRAY_SIZE];
    char* stringOfNumberB = new char[ARRAY_SIZE];
    int numberA = 0;
    int numberB = 0;
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

    numberA = atoi(stringOfNumberA);
    numberB = atoi(stringOfNumberB);

    result = numberA - numberB;

    cout << result << endl;

    delete stringOfNumberA;
    delete stringOfNumberB;

    return 0;
}

