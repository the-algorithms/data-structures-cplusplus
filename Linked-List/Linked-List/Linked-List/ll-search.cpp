//
//  ll-search-node.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/10/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include "header.h"

//4.2.2 Searching a Linked List
NodePtr searchNode(NodePtr head, int key) {
    while (head != NULL && head -> num != key) {
        head = head -> next;
    }
    return head;
}

void Program5(){
    NodePtr searchNode(NodePtr head, int key);
    
    // Generate a Linked List of Nodes
    NodePtr top = CreateNodeList(8);
    
    // Print all newly created Linked List
    printList(top);
    
    // Search for a specific number;
    int specific = rand() % 10 ;;
    
    NodePtr checkItem  = searchNode(top, specific);
    if (checkItem != NULL){
        cout << specific << " found!!" << endl;
    } else {
        cout << "not found.." << endl;
    }
}
