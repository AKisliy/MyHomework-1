#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class ArrayList {
private:
    int* array;
    int size;
public:	
    ArrayList(int init){
        array = (int*)malloc(10*sizeof(int));
        array[0] = init;
        this->size = 1;
    }
    int getIndex(int index){
        cout << array[index];
    }
    
    void displayIntList(){
        for(int i=0; i<size; i++){
            cout << array[i];
            cout << endl;
        }
        cout << endl;
    }
    
    void addIntList(int item){
        int* newArray = (int*)malloc((size+1)*sizeof(int));
        for(int i=0; i<size; i++){
            newArray[i] = array[i];
        }
        
        newArray[size] = item;
        array = newArray;
        size = size + 1;
    }
    
    void trimToSize(int item){
        int* newArray = (int*)malloc(item);
        for(int i=0; i<item; i++){
            newArray[i] = array[i];
        }
        
        array = newArray;
        size = item;
    }
        
    void setIntList(int item, int index){
        array[index] = item;
    }
    
    void removeSelectedItem(int index){
        int* newArray = (int*)malloc((size-1)*sizeof(int));
        //From Beginning
        for(int i=0; i<index; i++){
            newArray[i] = array[i]; 
        }
        //From next Index  
        for(int i=index; i<=size-1; i++){
            newArray[i] = array[i+1];
        }
    
        array = newArray;
        size = size - 1;
    }

};

int main(){
    ArrayList* list = new ArrayList(0);
    list->addIntList(15);
    list->addIntList(7);
    list->addIntList(3);   
    list->addIntList(12);   
    list->addIntList(25);
    list->displayIntList();
    list->trimToSize(5);
    list->displayIntList();
    list->setIntList(9,0);
    list->displayIntList();
    list->removeSelectedItem(3);
    list->displayIntList();
    list->getIndex(1);
    
//    for(int i = 0; i <= 100; i++){
//        list->addIntList(i);
//    }
//    list->displayIntList();
    delete list;
}
