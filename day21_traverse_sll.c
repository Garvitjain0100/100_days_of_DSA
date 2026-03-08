/* Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50 */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertatend(struct node* head,int value) {
 struct node* newnode = malloc(sizeof(struct node));
 newnode->data = value;
 newnode->next = NULL;
 
 if (head == NULL) 
    return newnode;

 struct node* temp = head;
 
 while (temp->next != NULL)
    temp = temp->next;

 temp->next = newnode;

 return head;
}

void display (struct node* head) {
    printf("Singly linked list:");
    while (head !=NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main () {
    int n,x;
    struct node* head = NULL;
    printf("Enter the number of nodes to create linked list:");
    scanf("%d",&n);

    for (int i = 0;i < n; i++){
        printf("Enter %d values of linked list:",i+1);
        scanf("%d",&x);
        head = insertatend(head,x);
    }

    display(head);

    return 0;
}