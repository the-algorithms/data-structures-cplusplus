//
//  ll1.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/7/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include "header.h"

// 4.4 Building a Linked List: Adding New Item at the Tail
void Program1() {

    int n = 1;
    NodePtr top, np, last;
    
    top = nullptr;
    last = nullptr;
    
    while (n != 0) {
        cout << "enter number: ";
        cin >> n;
        
        if (n != 0) {
            np = makeNode(n);    //create a new node containing n
            if (top == nullptr) { //set top if first node
                top = np;
                last = np;
            } else {
                last -> next = np; //set last -> next for other nodes
                last = np; //update last to new node
            }
        }
    } // end of while
    printList(top);
}
