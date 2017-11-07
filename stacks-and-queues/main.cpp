//
// Implementing a Queue Using an Array

#include <stdio.h>
#define MaxQ 10
#include <queue.h>
int main()
{
    int n;
    Queue Q = initQueue();
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while (n > 0)
    {
        enqueue(Q, n % 10);
        n = n / 10;
    }
    printf("\nDigits in reverse order: ");
    while (!empty(Q))
        printf("%d", dequeue(Q));
    printf("\n");
}