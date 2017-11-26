#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class ArrayList {
public:	
    ArrayList(int);
    int get(int index);
    void displayIntList();
    void addIntList(int item);
    void setIntList(int item, int index);
    void removeSelectedItem(int index);
private:
    int* array;
    int size;
};


ArrayList::ArrayList(int init){
    array = (int*)malloc(10*sizeof(int));
    array[0] = init;
    this->size = 1; 
}

int ArrayList::get(int index){
    cout << array[index];
}

void ArrayList::addIntList(int item){
    int* newArray = (int*)malloc((size+1)*sizeof(int));
    for(int i=0; i<size; i++){
        newArray[i] = array[i];
    }

    newArray[size] = item;
    array = newArray;
    size = size + 1;
}

void ArrayList::setIntList(int item, int index){
    array[index] = item;
}

void ArrayList::removeSelectedItem(int index){
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

void ArrayList::displayIntList(){
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
    }
    cout << endl;
}


int main(){
    ArrayList* list = new ArrayList(0);
    list->addIntList(15);
    list->addIntList(7);
    list->addIntList(3);   
    list->addIntList(12);   
    list->addIntList(25);
    list->displayIntList();
    list->setIntList(9,0);
    list->displayIntList();
    list->removeSelectedItem(3);
    list->displayIntList();
    list->get(3);
    delete list;
}
