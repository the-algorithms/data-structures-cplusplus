//
//  header.h
//  Linked-List
//
//  Created by Parvez Kose on 11/7/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;


NodePtr makeNode(int);
void printList(NodePtr);

// Create a New Node
NodePtr makeNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof (Node));
    np -> num = n;
    np -> next = nullptr;
    return np;
}

// Get Random Digits
int getRandomNum() {
    return rand() % 10 + 1;
}

// Generate a new Node Linked List
NodePtr CreateNodeList(int size) {
    int num;
    NodePtr np, top, last;
    top = nullptr;
    last = nullptr;
    
    for (int i=0; i<size; i++) {
        num = getRandomNum();

        np = makeNode(num);
        
        if ( top == nullptr) {
            
            top = np;
            last = np;
            
        } else {
        
            last -> next = np;
            last = np;

        }
    }
    return top;
}

// Print List numbers
void printList(NodePtr np) {
    while (np != nullptr) {  // as long as there's a node
        cout <<  np -> num;
        cout << ", ";
        np = np -> next;  // go on to the next node
    }
     cout << endl;
}

#endif /* header_h */
