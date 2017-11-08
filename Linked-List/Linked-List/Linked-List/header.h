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

#endif /* header_h */
