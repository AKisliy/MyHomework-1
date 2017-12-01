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
        if(size <= allocSize) {
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
        cout << size << " ";
        cout << endl;
    }
    
    void setToList(int index, int item) {
        if(size == allocSize){
            int* newArray = new int[allocSize * 2];
            allocSize = allocSize * 2;
            
            for(int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            
            delete array;
            array = newArray;
        }
        
        if(index <= size){
            size++;
            for(int i = size - 1; i != index - 1; i--) {
                array[i] = array[i - 1];
            }
            array[index] = item;
        }              
    }
    
    int get(int index) {
        if(index < 0 || index > size){
                cout << "Error! Index not found" << endl;
            } else cout << array[index] << endl;
        
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
        
        allocSize = size;
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
    list->setToList(0,1);
    list->setToList(1,1);
    list->setToList(2,1);
    list->setToList(3,1);
    list->displayTheList();
    list->get(4);
    list->removeSelectedItem(4);
    list->displayTheList();
    list->trimToSize();
    list->displayTheList();
    delete list;
}
