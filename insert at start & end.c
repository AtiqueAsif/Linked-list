#include<stdio.h>
#include<stdlib.h>

// Only insert at beginning & insert at end and print

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
}

void insert_at_end(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else{
        struct node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print_the_list(){

    printf("Linked list: ");

    struct node *temp = head;
    while(temp != NULL){
        printf("%d | ",temp -> data);
        temp = temp -> next;
    }
}

int main(){

    insert_at_beginning(4);
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(1);

    print_the_list();

    insert_at_end(5);
    insert_at_end(6);
    insert_at_end(7);
    insert_at_end(8);

    printf("\n\nAfter insert at end\n");
    print_the_list();
    printf("\n");


    return 0;


}







