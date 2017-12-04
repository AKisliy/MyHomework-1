#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

#define SIZE_ARRAY 100

void sortA(char* a){
    int temp = 0;
    int length = strlen(a);
    bool exit = false;

    while (!exit){
        exit = true;
        if(a[0] == '-'){
            for (int i = 1; i < length - 1; i++){
                if(a[1] > a[2] && a[2] == '0'){
                   for (int i = 3; i < length - 1; i++){
                       if (a[i] > a[i + 1]){
                           temp = a[i];
                           a[i] = a[i + 1];
                           a[i + 1] = temp;
                           exit = false;
                        }
                   }
                   break;
                }

                if (a[i] > a[i + 1]){
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    exit = false;
                }
            }
        } else {
            for (int i = 0; i < length - 1; i++){
                if (a[i] < a[i + 1]){
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    exit = false;
                }
            }
        }
    }
}

void sortB(char* b){
    int temp = 0;
    int length = strlen(b);
    bool exit = false;

    while (!exit){
        exit = true;
        if(b[0] == '-'){
            for (int i = 1; i < length - 1; i++){
                if (b[i] < b[i + 1]){
                    temp = b[i];
                    b[i] = b[i + 1];
                    b[i + 1] = temp;
                    exit = false;
                }
            }
        } else {
            for (int i = 0; i < length - 1; i++){
                if(b[0] > b[1] && b[1] == '0'){
                   for (int i = 2; i < length - 1; i++){
                       if (b[i] > b[i + 1]){
                           temp = b[i];
                           b[i] = b[i + 1];
                           b[i + 1] = temp;
                           exit = false;
                        }
                   }
                   break;
                }

                if (b[i] > b[i + 1]){
                    temp = b[i];
                    b[i] = b[i + 1];
                    b[i + 1] = temp;
                    exit = false;
                }
            }
        }
    }
}

int main() {
    char* charA = new char[SIZE_ARRAY];
    char* charB = new char[SIZE_ARRAY];
    int intA = 0;
    int intB = 0;
    cout << "Enter a: ";
    cin >> charA;
    cout << "Enter b: ";
    cin >> charB;

    cout << endl;

    sortA(charA);
    sortB(charB);

    cout << charA << endl;
    cout << charB << endl;

    intA = atoi(charA);
    intB = atoi(charB);

    cout << (intA - intB) << endl;
    return 0;
}
