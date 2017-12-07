#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

#define SIZE_ARRAY 100

void sortA(char* stringOfA) {
    char temp;
    int length = strlen(stringOfA);

    if(stringOfA[0] == '-') {                                                   // if the number is negative,
        for (int i = length - 1; i >= 0; i--) {                                 // we begin sorting with
            for (int j = 1; j < i; j++) {                                       // 1 element
                if (stringOfA[1] > stringOfA[2] && stringOfA[2] == '0') {       // if 2 element '0', we begin sorting with
                    for (j = 3; j < i; j++) {                                   // 3 element, so that                 
                        if (stringOfA[j] > stringOfA[j + 1]) {                  // the sorted number does not begin with 0
                            temp = stringOfA[j];
                            stringOfA[j] = stringOfA[j + 1];
                            stringOfA[j + 1] = temp;
                        }
                    }
                    break;
                }

                if (stringOfA[j] > stringOfA[j + 1]) {
                    temp = stringOfA[j];
                    stringOfA[j] = stringOfA[j + 1];
                    stringOfA[j + 1] = temp;
                }
            }
        }
    } else {
        for (int i = length - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (stringOfA[j] < stringOfA[j + 1]) {
                    temp = stringOfA[j];
                    stringOfA[j] = stringOfA[j + 1];
                    stringOfA[j + 1] = temp;
                }
            }
        }
    }
}

void sortB(char* stringOfB) {
    char temp;
    int length = strlen(stringOfB);

    if(stringOfB[0] == '-') {                                                   // if the number is negative,
        for (int i = length - 1; i >= 0; i--) {                                 // we begin sorting with
            for (int j = 1; j < i; j++) {                                       // 1 element
                if (stringOfB[j] < stringOfB[j + 1]) {
                    temp = stringOfB[j];
                    stringOfB[j] = stringOfB[j + 1];
                    stringOfB[j + 1] = temp;
                }
            }
        }
    } else {
        for (int i = length - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if(stringOfB[0] > stringOfB[1] && stringOfB[1] == '0') {        // if 1 element '0', we begin sorting with
                    for (j = 2; j < i; j++) {                                   // 2 element, so that
                        if (stringOfB[j] > stringOfB[j + 1]) {                  // the sorted number does not begin with 0
                           temp = stringOfB[j];
                           stringOfB[j] = stringOfB[j + 1];
                           stringOfB[j + 1] = temp;
                        }
                    }
                    break;
                }

                if (stringOfB[j] > stringOfB[j + 1]) {
                    temp = stringOfB[j];
                    stringOfB[j] = stringOfB[j + 1];
                    stringOfB[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    char* stringOfA = new char[SIZE_ARRAY];
    char* stringOfB = new char[SIZE_ARRAY];
    int intOfA = 0;
    int intOfB = 0;
    int result = 0;
    
    cout << "Enter a: ";
    cin >> stringOfA;
    cout << "Enter b: ";
    cin >> stringOfB;

    cout << endl;

    sortA(stringOfA);
    sortB(stringOfB);

    cout << stringOfA << endl;
    cout << stringOfB << endl;

    intOfA = atoi(stringOfA);
    intOfB = atoi(stringOfB);
    
    result = intOfA - intOfB;

    cout << result << endl;
    
    delete stringOfA;
    delete stringOfB;
    
    return 0;
}
