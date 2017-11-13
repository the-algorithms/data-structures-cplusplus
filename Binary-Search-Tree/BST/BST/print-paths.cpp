//
//  print-paths.cpp
//  BST
//
//  Created by Parvez Kose on 11/12/17.
//  Copyright © 2017 Parvez Kose. All rights reserved.
//

#include <stdio.h>


 
 /*
 Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.
 */
/*
void printArray(int ints[], int len);
void printPathsRecur(Node*, int, int);
*/
/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
 */
/*
void printPaths(struct Node* root);
 
void printPathsRecur(struct Node* root, int path[], int pathLen) {
    if (root==NULL) return;
    
    // append this node to the path array
    path[pathLen] = root->data;
    pathLen++;
    
    // it's a leaf, so print the path that led to here
    if (root->left==NULL && root->right==NULL) {
        printArray(path, pathLen);
    }
    else {
        // otherwise try both subtrees
        printPathsRecur(root->left, path, pathLen);
        printPathsRecur(root->right, path, pathLen);
    }
}

// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");
}

void printPaths(struct Node* root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}

*/
