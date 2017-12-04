#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std ;


class Node {
public:
    Node* nextNode;
    int data;

    Node(int data){
        this->data = data;
    }
};

class LinkedList {
public:
    Node* firstNode = NULL;
    Node* prevNode = NULL;
    Node* tempNode = NULL;
    int sizeOfList = 0;
    int counter = 0;
    
    void add(int n, Node* node = NULL) {
        if(node == NULL){
            node = new Node(n);
            firstNode = node;
            return;
        }
        
        if(node->nextNode != NULL){
            add(n, node->nextNode);
            return;
        }
        
        Node* newNode = new Node(n);
        node->nextNode = newNode;
        sizeOfList++;
    }

    void set(int n, int index, Node* node) {
        if (index < 0 || index > sizeOfList) {
            cout << "Error! Index not found" << endl;
            return;
        }

        if(counter == 0){
            tempNode = new Node(n);
            tempNode->data = n;
        }

        if(index == 0){
            tempNode->nextNode = firstNode;
            firstNode = tempNode;
            counter = 0;
            return;
        }

        if(counter == index - 1){
            tempNode->nextNode = node->nextNode;
            node->nextNode = tempNode;
            counter = 0;
            return;
        }

        counter++;
        node = node->nextNode;
        set(n, index, node);
        sizeOfList++;
    }

    void get(int index, Node* node, int counter = 0) {
        if (index < 0 || index > sizeOfList){
            cout<< "Error! Index not found!"<<endl;
            return;
        }

        if (index == counter) {
            cout << node->data;
        } else {
            counter++;
            get(index, node->nextNode, counter);
        }
    }

    void remove(int index, Node* node, int counter = 0){
        if (firstNode == NULL) {
            cout << "List is empty" << endl;
        }

        if (index < 0 || index > sizeOfList){
            cout << "Error! Index not found!" << endl;
            return;
        }

        if (index == 0){
            firstNode = firstNode->nextNode;
            return;
        } else if (counter == index-1){
            prevNode = node;
        }
        
        if (counter == index){
            prevNode->nextNode = node->nextNode;
            delete node;
            return;
        }
        
        node = node->nextNode;
        counter++;
        remove(index, node, counter);
    }

    void show(Node* node) {
        cout<<node->data<<endl;
        if (node->nextNode != NULL){
            show(node->nextNode);
        }
    }
};

int main(){
    LinkedList l;
    
    cout << "------------- Add of new nodes --------------" << endl;
    l.add(5, l.firstNode);
    l.add(74, l.firstNode);
    l.add(6, l.firstNode);
    l.add(84, l.firstNode);
    l.show(l.firstNode);
    cout << "---------------------------------------------\n" << endl;

    cout << "------- Add of new node in the 3 index ------" << endl;
    l.set(40, 3, l.firstNode);
    l.show(l.firstNode);
    cout << "---------------------------------------------\n" << endl;

    cout << "------- Delete of node in the 2 index -------" << endl;
    l.remove(2, l.firstNode);
    l.show(l.firstNode);
    cout << "---------------------------------------------\n" << endl;

    cout << "----- Get the value of the 2 index node -----" << endl;
    l.get(2,l.firstNode);
    cout << "\n---------------------------------------------" << endl;
        
    return 0;
}

