// Program P4.2

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

//ADD NEW NUMEBR TO THE HEAD OF THE LIST
int main() {
    
    void printList(NodePtr);
    NodePtr makeNode(int);
    
    int n;
    NodePtr top, np;
    top = nullptr;
    
    while (n != 0) {
        
        cout << "enter number: ";
        cin >> n;
        
        if (n != 0) {
            np = makeNode(n);    //create a new node containing n
            np -> next = top;
            top = np;
        }
    } // end of while
    printList(top);
}

NodePtr makeNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof (Node));
    np -> num = n;
    np -> next = nullptr;
    return np;
}

void printList(NodePtr np) {
    while (np != nullptr) {  // as long as there's a node
        cout <<  np -> num;
        cout << " " << endl;
        np = np -> next;  // go on to the next node
    }
}
