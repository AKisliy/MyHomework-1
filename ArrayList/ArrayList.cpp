#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INITIA_SIZE 5
using namespace std;

class ArrayList {
private:
    int* array;
    int size;
    int allocSize;
public:
    ArrayList(){
        array = new int[INITIA_SIZE];
        size = 0;
        allocSize = INITIA_SIZE;
    }
  
    void addToList(int item) {
        if(size < allocSize) {
            array[size] = item;
            size++;
        } else {
            int* newArray = new int[allocSize * 2];
            allocSize = allocSize * 2;
            
            for(int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            
            delete array;
            array = newArray;
            array[size] = item;
            size++;
        }
    }
    
    void setToList(int index, int item) {
        if(size < allocSize) {
            size++;
            for(int i = size - 1; i != index - 1; i--) {
                array[i] = array[i - 1];
            }
            array[index] = item;
        }
    }
    
    int get(int index) {
        cout << array[index] << endl;
        return array[index];
    }
           
    void removeSelectedItem(int index) {
        if (index < size) {
            while (index < size) {
                array[index] = array[index + 1];
                index++;
            }
            size--;
        }
    }
    
    void trimToSize() {
        int* newArray = new int[size];
        
        for(int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        
        delete array;
        array = newArray;
        
        for(int i = 0; i < size; i++) {
            cout << newArray[i];
            cout << " ";
        }
        cout << endl;
    }

    void displayTheList() {
        for(int i = 0; i < allocSize; i++) {
            cout << array[i];
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayList* list = new ArrayList();
    list->addToList(0);
    list->addToList(1);
    list->addToList(2);   
    list->addToList(3);   
    list->addToList(4);
    list->addToList(5);
    list->addToList(6);
    list->displayTheList();
    list->setToList(4,0);
    list->displayTheList();
    list->get(6);
    list->removeSelectedItem(4);
    list->displayTheList();
    list->trimToSize();
    delete list;
}
