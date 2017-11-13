/* Deleting a node from Binary search tree */
#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Basic Operations
    Node* Insert(Node*, char);
    Node* DeleteNode(Node*, int data);
    bool Search(Node*, int);
    int size(Node*);
    Node* FindMin(Node*);

// Traversals
void visit(Node*);
void preOrder(Node* root);
void inOrder(Node*);
void postOrder(Node*);

// Find Min/Max
int FindMinAll(Node*);
int FindMinAll(Node*);

// More Operations
//

int main (){
    
    char charArr[] = {5, 10, 3, 4, 1, 11, 12};
    Node* root = NULL;
    
    for (int i=0; i<strlen(charArr)-1; i++) {
        root = Insert(root, charArr[i]);
    };
    
    //Delete
    //root = DeleteNode(root, 10);
    
    /*int num = 1;
    while (num != 0) {
        cout << "Enter number to search: ";
        cin >> num;
        if(Search(root, num) == true) cout << "FOUND!!\n" << endl;
        else cout << "NOT FOUND..\n" <<  endl;
    }*/
    
    cout << "**Total Nodes**: " << size(root) << endl;
    cout << "\n";
    //Print Nodes in Pre Order
    cout<<"The Pre-Order Traversal: ";
    preOrder(root);
    cout<<"\n";
    
    //Print Nodes in In Order
    cout<<"The In-Order Traversal: ";
    inOrder(root);
    cout << endl;
    
    //Print Nodes in Post Order
    cout<<"The Post-Order Traversal: ";
    postOrder(root);
    cout << endl;
    
    
    cout<<"The Post-Order Traversal: ";
    root = FindMin(root);
    cout << "Min Value: " << root -> data << endl;

    cout<<"\n";
    return 0;
}

Node* Insert(Node* root, char data) {
    if(root == NULL){
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);
    
    return root;
}

Node* DeleteNode(Node* root, int data) {
   
    if (root == NULL) return root;
    else if (data < root->data) root->left = DeleteNode(root->left, data);
    else if (data > root->data) root->right = DeleteNode(root->right, data);
    else { // Wohoo!! Found you..
        
        Node* temp;
        // case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        
        //case 2: One child
        else if (root->left == NULL) {
            temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            temp = root;
            root = root->left;
            delete temp;
        }
        
        //case 3: Two child
        else {
            temp = FindMin(root->right);    //Find minimum in right subtree
            root->data = temp->data;    //Replace: Copy value in target node
            root->right = DeleteNode(root->right, temp->data);  //Delete duplicate from the right subtree
        }
        
    }
    return root;
}

// Look up
bool Search(Node* root, int data){
    if(root == NULL) return false;
    else if (data == root->data) return true;
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

// Minimum Node / Value
Node* FindMin(Node* root){
    while(root->left != NULL) root = root->left;
    return root;
}

// Maximum Node / Value
Node* FindMax(Node* root){
    while(root->right != NULL) root = root->right;
    return root;
}

// Counting
int size(Node* root) {
    if(root == NULL)
        return (0);
    else
        return (size(root->left) + 1 + size(root->right));
}

// Visit Node and Print
void visit(Node* root) {
    if(root != NULL)
        cout << root->data << " ";
}

// Pre-Order Traversal
void preOrder(Node* root){
    // N L R
    if(root != NULL) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// In-Order Traversal
void inOrder(Node* root){
    // L N R
    if(root != NULL){
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

// Post-Order Traversal
void postOrder(Node* root){
    // L R N
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        visit(root);
    }
}

