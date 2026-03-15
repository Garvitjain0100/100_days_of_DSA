/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop. */
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* createnode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newnode->data = value;
    newnode->next= NULL;

    return newnode;
}

void insertatend(int value){
struct node* newnode = createnode(value);

if (head == NULL) {
    head = newnode;
    newnode->next = head;
    return;
}

struct node* temp = head;

while(temp->next != head)
    temp = temp->next;

temp->next = newnode;
newnode->next=head;

}

void printlist(struct node* head) {
    struct node* temp = head;

    printf("Element of circular linked list are:");

    if(head == NULL)
        return;

    do{
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != head);

}

int main () {
    int n,value;
    printf("Enter the number of nodes for circular linked list:");
    scanf("%d",&n);

    printf("Enter the element for circular linked list:");
    for (int i = 0;i < n; i++) {
        scanf("%d",&value);
        insertatend(value);
    }

    printlist(head);
}