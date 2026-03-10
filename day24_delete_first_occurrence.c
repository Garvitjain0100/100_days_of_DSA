/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer. */
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node* createnode(int value) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;

}

struct node* insertatend(struct node* head,int value) 
{
    struct node* newnode = createnode(value);

    if (head == NULL) 
    return newnode;

    struct node* temp = head;

    while (temp->next != NULL) 
    temp = temp->next;

    temp->next = newnode;

    return head;
}

void deleteoccurrence(struct node** head,int key)
{
    struct node* temp = *head;
    struct node* prev = NULL;

   if(temp != NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    return;

    prev->next = temp->next;
    free(temp);
}


int main () {
    struct node* head = NULL;
    int n,value;
    printf("Enter the number of nodes:");
    scanf("%d",&n);

    printf("Enter the element for linked list:");
    for(int i = 0 ;i<n;i++)
    {
        scanf("%d",&value);
        head= insertatend(head,value);
    }

    int key;
    printf("Enter the element to delete occurrence:");
    scanf("%d",&key);
    deleteoccurrence(&head,key);

    struct node* temp =head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

}
