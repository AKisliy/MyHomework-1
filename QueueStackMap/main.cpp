#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int* getSize(int size){
    int* array = (int*) malloc(size);
    return array;
}

class Queue{
public:
    int q[20];
    int* first;
    int* last;

    Queue(){
        first = q;
        last = q;
    }

    void put(int value){
        *last = value;
        last++;
    }

    int get(){
        int data = *first;
        first++;
        return data;
    }

    bool isVoid(){
        return first == last;
    }
};

class Stack{
public:
    int stack[20];
    int* top;
    int counter;

    Stack(){
        top = stack;
        counter = 0;
    }

    void put(int value){
        *top = value;
        top++;
        counter++;
    }

    int get(){
        if (*top == 0){
            top--;
        }

        int value = *top;
        top--;
        counter--;
        return value;
    }

    bool isVoid(){
        return counter == 0;
    }
};

class Map{
public:
    int* array = getSize(10000000);

    int hash(char* str){
        int strLength = strlen(str);
        int a = 2;
        int b = 1;
        int hash = 0;
        for(int i = 0; i < strLength; i++) {
            hash = hash + a + str[i];
            a = a + b;
        }

        return hash;
    }

    int get(char* str){
        return array[hash(str)];
    }

    void put(char* str, int value){
        array[hash(str)] = value;
    }
};

int main(){
    //Queue
    cout << "-----Queue-----" << endl;
    Queue queue;
    cout << "Queue is void? - " << queue.isVoid() << endl;
    queue.put(5);
    queue.put(7);
    queue.put(1);
    queue.put(8);

    cout << queue.get() << endl;
    cout << queue.get() << endl;
    cout << queue.get() << endl;
    cout << "Is queue void? - " << queue.isVoid() << endl;
    cout << "---------------" << endl;

    //Stack
    cout << "-----Stack-----" << endl;
    Stack stack;
    cout << "Is stack void? - " << stack.isVoid() << endl;
    stack.put(14);
    stack.put(18);
    stack.put(43);
    stack.put(5);
    stack.put(23);
    stack.put(35);
    stack.put(8);
    stack.put(49);

    cout << stack.get() << endl;
    cout << stack.get() << endl;
    cout << stack.get() << endl;
    cout << stack.get() << endl;
    cout << stack.get() << endl;
    cout << stack.get() << endl;
    cout << "Is stack void? - " << stack.isVoid() << endl;
    cout << "---------------" << endl;

    //Map
    cout << "------Map------" << endl;
    Map map;
    map.put("oleg", 15);
    map.put("hello", 33);
    map.put("tanya", 24);

    cout << map.get("tanya") << endl;
    cout << map.get("oleg") << endl;
    cout << "---------------" << endl;

    return 0;
}

