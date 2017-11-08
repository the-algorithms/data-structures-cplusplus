//
//  110.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/7/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

// 4.6 Building a Linked List: Adding a New Item at the Head
#include "header.h"

void Program2(){
    int n = 1;
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
