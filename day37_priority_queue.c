/* Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20 */

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;

    printf("Inserted %d\n", x);
}

void delete_min() {
    if (size == 0) {
        printf("-1 (Queue Empty)\n");
        return;
    }

    printf("Deleted: %d\n", pq[0]);

    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

void peek() {
    if (size == 0) {
        printf("-1 (Queue Empty)\n");
    } else {
        printf("Top element: %d\n", pq[0]);
    }
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                delete_min();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}