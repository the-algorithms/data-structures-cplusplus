 //
 //  BST Implementation.cpp
 //  BST
 //
 //  Created by Parvez Kose on 11/11/17.
 //  Copyright © 2017 Parvez Kose. All rights reserved.
 //
 
 #include <stdio.h>
 #include <iostream>
 using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* GetNewNode(int data) {
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to insert in BST; return address of root node
BSTNode* Insert(BSTNode* root, int data) {
    if (root == NULL) { // empty tree
        root = GetNewNode(data);
    }
    else if (data < root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BSTNode* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}
int main(int argc, const char * argv[]) {
    
    
    BSTNode* root = NULL;
    
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 212);
    
    int num;
    cout << "enter number to search\n";
    cin >> num;
    if (Search(root, num) == true) cout << "FOUND\n";
    else cout << "NOT FOUND\n";
    
    return 0;
}
