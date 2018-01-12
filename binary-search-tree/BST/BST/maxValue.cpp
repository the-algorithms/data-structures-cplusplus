//
//  maxValue.cpp
//  BST
//
//  Created by Parvez Kose on 11/13/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <stdio.h>

struct nodeBST {
    int data;
    nodeBST* pLeft;
    nodeBST* pRight;
};

int maxValue(nodeBST* root)
{
    if (root == NULL)
        return 0;
    
    int max = root->data;
    for (nodeBST* left = root; left != NULL; left = left->pLeft)
    {
        if (left->data > max)
            max = left->data;
    }
    
    for (nodeBST* right = root; right != NULL; right = right->pRight)
    {
        if (right->data > max)
            max = right->data;
    }
    
    return max;
}
