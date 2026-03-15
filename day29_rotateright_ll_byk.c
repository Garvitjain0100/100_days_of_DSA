#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

struct node* createnode(int value) {
    struct node* newnode =(struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
    }

    newnode->data = value;
    newnode->next = NULL;
    
    return newnode;
}

void insertatend (int value) {
    struct node* newnode = createnode(value);

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct node* temp = head;

    while(temp->next != NULL) 
        temp = temp->next;

    temp->next = newnode;
}

void rotateright(int k,int n) {
    if (head == NULL || head->next == NULL)
        return;
    
    struct node* temp = head;
    
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = head;

    int steps = n-k;

    temp = head;

    for (int i = 1; i< steps;i++)
        temp = temp->next;

    head = temp->next;

    temp->next = NULL;
}

void printlist(struct node* head) {
    struct node* temp = head;

    while (temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    } 

    printf("NULL\n");

}

int main () {
    int n,k,value;

    printf("Enter the number of node for linked list:");
    scanf("%d",&n);

    printf("Enter the element for linked list:");
    for (int i = 0; i < n; i++) {
        scanf("%d",&value);
        insertatend(value);
    }

    printf("Element of linked list before rotation are:");
    printlist(head);

    printf("Enter the position to rotate linked list:");
    scanf("%d",&k);

    if(k > n) k = k % n;

    rotateright(k,n);

    printf("Element of linked list after kth rotation are:");
    printlist(head);

    return 0;
}