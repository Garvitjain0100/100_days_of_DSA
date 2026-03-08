#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int countnodes(struct node* head){
    int count_nodes = 0;
    struct node* temp= head;
    while (temp != NULL) {
        count_nodes++;
        temp = temp->next;
    }

    return count_nodes;
}

int main () {
struct node* head = NULL;
struct node* second = NULL;
struct node* third = NULL;
struct node* four = NULL;
struct node* five = NULL;

head = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node)); 
third = (struct node*)malloc(sizeof(struct node));
four = (struct node*)malloc(sizeof(struct node));
five = (struct node*)malloc(sizeof(struct node));

head->data = 10;
head->next = second;

second->data = 20;
second->next = third;

third->data = 30;
third->next = four;

four->data = 40;
four->next = five;

five->data = 50;
five->next = NULL;

printf("Number of nodes = %d",countnodes(head));

return 0;

}