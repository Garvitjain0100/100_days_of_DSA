#include<stdio.h>
#include<stdlib.h>
struct node {
    int coef;
    int expo;
    struct node* next;
};
struct node* head = NULL;

struct node* createnode(int var,int pow) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    newnode->coef = var;
    newnode->expo = pow;
    newnode->next = NULL;

    return newnode;
}

void  insertatend(int var,int pow) {
    struct node* newnode = createnode(var,pow);

    if (head == NULL){
        head = newnode;
        return;
    }

    struct node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

}

void printlist(){

    struct node* temp = head;

    while(temp != NULL){
        if(temp->expo == 0) {
            if (temp->next == NULL) {
                printf("%d ",temp->coef);
            } else {
                printf(" %d + ",temp->coef);
            }
        } else {
            if(temp->next == NULL) {
                printf("%dX^%d ",temp->coef,temp->expo);
            } else {
                printf("%dX^%d + ",temp->coef,temp->expo);
            }
        }
        
        
        temp = temp->next;
    }

}

int main () {
    int n,var,pow;
    printf("Enter the number of node for polynomial linked list:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent respectively for %d term of polynomial:",i+1);
        scanf("%d %d",&var,&pow);
        insertatend(var,pow);
    }

    printlist();

}