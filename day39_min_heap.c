/* Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p] > h->arr[i]) {
            swap(&h->arr[p], &h->arr[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(MinHeap *h, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < h->size && h->arr[l] < h->arr[smallest])
            smallest = l;

        if (r < h->size && h->arr[r] < h->arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(MinHeap *h, int x) {
    if (h->size == MAX) return;

    h->arr[h->size] = x;
    heapifyUp(h, h->size);
    h->size++;
}

int extractMin(MinHeap *h) {
    if (h->size == 0) return -1;

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);

    return root;
}

int peek(MinHeap *h) {
    if (h->size == 0) return -1;
    return h->arr[0];
}

int main() {
    MinHeap h;
    h.size = 0;

    int choice, x;

    while (1) {
        printf("\n1.Insert  2.ExtractMin  3.Peek  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &x);
                insert(&h, x);
                break;

            case 2:
                printf("%d\n", extractMin(&h));
                break;

            case 3:
                printf("%d\n", peek(&h));
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}