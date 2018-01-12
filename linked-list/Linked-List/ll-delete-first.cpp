//
//  ll-del-first.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/10/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

//
//  ll-del-first.cpp
//  Linked-List
//
//  Created by Parvez Kose on 11/9/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include "header.h"

// Delete the first node in the linked list

void Program4(){
    
    int n;
    NodePtr np, top, last;
    top = nullptr;
    last = nullptr;
    
    /*
     // Generate a Linked List of Nodes
     NodePtr top = CreateNodeList(8);
     */
    
    //
    int arr[4] = {11, 22, 33, 44};
    
    for (n=0; n<sizeof(arr)/4; n++){
        np = makeNode(arr[n]);
        
        if(top == nullptr) {
            top = np;
            last = np;
        } else {
            last -> next = np;
            last = np;
        }
    }
    //
    
    printList(top);
    
    // delete the first node in the list
    NodePtr old = NULL;
    if(top -> next != nullptr){
        old = top;
        top = top -> next;
        free(old);
    }
    
    printList(top);
    
    // delete the last node in the list
    NodePtr target = top;
    while(target -> next != NULL ){
        
        target = target -> next;
        
        // set the new last node
        if(target -> next != NULL){
            last = target;
        }
    }
    
    cout << target -> num << " :target to delete" << endl;
 
    free(target);
    
    cout << last -> num << endl;
    
}

