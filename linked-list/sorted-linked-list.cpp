// 4.8 Building a Sorted Linked List
//
// The insertion of a new node in its proper position in the list is delegated to
// the function addInPlace. This function returns a pointer to the top of the modified list.
//
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

int main()
{
    void printList(NodePtr);
    NodePtr addInPlace(NodePtr, int);
    int n;
    NodePtr top = NULL;
    if (scanf("%d", &n) != 1)
        n = 0;
    while (n != 0)
    {
        top = addInPlace(top, n);
        if (scanf("%d", &n) != 1)
            n = 0;
    }
    printList(top);
} //end main
NodePtr addInPlace(NodePtr top, int n)
{
    // This functions inserts n in its ordered position in a (possibly empty)
    // list pointed to by top, and returns a pointer to the new list
    NodePtr np, curr, prev, makeNode(int);
    np = makeNode(n);
    prev = NULL;
    curr = top;
    while (curr != NULL && n > curr->num)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
    { //new number must be added at the top
        np->next = top;
        return np; //the top of the list has changed to the new node
    }
    np->next = curr;
    prev->next = np;
    return top; //the top of the list has not changed
} //end addInPlace
NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
} // end makeNode
void printList(NodePtr np)
{
    while (np != NULL)
    { // as long as there's a node
        printf("%d\n", np->num);
        np = np->next; // go on to the next node
    }
} //end printList
