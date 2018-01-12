//
//  ll-last-node.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/10/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include "header.h"

// 4.2.3 Finding the Last Node in a Linked List
NodePtr getLastnode(NodePtr head) {
    if (head == NULL) return head;
    while (head -> next != NULL) {
        head = head -> next;
    }
    return head;
}

void Program6(){
    NodePtr top = CreateNodeList(4);
    printList(top);
    
    NodePtr lastNode = getLastnode(top);
    cout << lastNode -> num << " :The last node" << endl;
}
