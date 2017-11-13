/* Binary Tree */

#include <iostream>
#include <deque>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

// Basic Operations
Node* Insert(Node*, int);
Node* DeleteNode(Node*, int);
bool Search(Node*, int);


// Traversals
void visit(Node*);
void preOrder(Node*);
void inOrder(Node*);
void postOrder(Node*);

// More Operations
int size(Node*);
int FindHeight(Node*);

Node* FindMin(Node*);
Node* FindMax(Node*);


int maxValue(Node*);

int MaxDepth(Node*);
int MinDepth(Node*);

void BreadthFirstTraversal(Node*);

// main
int main (){
    
    char charArr[] = {5, 10, 3, 4, 1, 11, 22};
    Node* root = NULL;
    
    for (int i=0; i<strlen(charArr); i++) {
        root = Insert(root, charArr[i]);
    };

    cout << "MAX: " << maxValue(root) << endl;
    
    //Delete
    //root = DeleteNode(root, 10);
    
    /*int num = 1;
     while (num != 0) {
     cout << "Enter number to search: ";
     cin >> num;
     if(Search(root, num) == true) cout << "FOUND!!\n" << endl;
     else cout << "NOT FOUND..\n" <<  endl;
     }
    
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
    
    /* Traversing level-order.
     We visit every node on a level before going to a lower level.
     This is also called Breadth-first traversal.*/
    /*
    cout << "printing with Breadth-first traversal" << endl;
    BreadthFirstTraversal(root);
    
    Node* temp1 = FindMin(root);
    cout << "Min Value: " << temp1 -> data << endl;
    
    Node* temp2 = FindMax(root);
    cout << "Max Value: " << temp2 -> data << endl;
    
    cout << "Root: " << root -> data << endl;
    cout << "Height of BT " << FindHeight(root) << endl;
    
    cout << "BT MAX DEPTH " << MaxDepth(root) << endl;
    cout << "BT MIN DEPTH " << MinDepth(root) << endl;
    cout << "printing with Breadth-first traversal" << endl;
    
    cout<<"\n";
    */
    return 0;
}

int maxValue(Node* root)
{
    if (root == NULL)
        return 0;
    
    int max = root->data;
    for (Node* left = root; left != NULL; left = left->left)
    {
        if (left->data > max)
            max = left->data;
    }
    
    for (Node* right = root; right != NULL; right = right->right)
    {
        if (right->data > max)
            max = right->data;
    }
    
    return max;
}


Node* Insert(Node* root, int data) {
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
    else if (data == root->data)
        return true;
    else if (data < root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

/* Breadth first traversal using queue */
void BreadthFirstTraversal(Node* root)
{
    if (root == NULL) return;
    deque <Node*> queue;
    queue.push_back(root);
    
    while (!queue.empty()) {
        Node* p = queue.front();
        cout << p->data << " ";
        queue.pop_front();
        
        if (p->left != NULL)
            queue.push_back(p->left);
        if (p->right != NULL)
            queue.push_back(p->right);
    }
    cout << endl;
}


// Minimum Node / Value
Node* FindMin(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Maximum Node / Value
Node* FindMax(Node* root){
    while(root->right != NULL)
        root = root->right;
    return root;
}

// Iterative - Returns maximum valu


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

// Find height of a binary tree
int FindHeight(Node* root) {
    if (root == NULL)
        return 0;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int MaxDepth(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    int LeftDepth = MaxDepth(root->left); // Left subtree
    int RightDepth = MaxDepth(root->right); // Right subtree
    
    return (LeftDepth > RightDepth) ? LeftDepth + 1 : RightDepth + 1;
}

int MinDepth(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    int LeftDepth = MaxDepth(root->left);
    int RightDepth = MaxDepth(root->right);
    
    return (LeftDepth < RightDepth) ? LeftDepth + 1 : RightDepth + 1;
}

