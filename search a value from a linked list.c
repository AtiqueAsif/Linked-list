#include<stdio.h>
#include<stdlib.h>

// search a value from a linked list

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


// search function
void search_a_value(int search){
    struct node *temp = head;
    while (temp != NULL){
        if(temp -> data == search){
          printf("FOUND!!\n");
          return;
        }
        temp = temp -> next;
    }
    printf("NOT FOUND!!\n");

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

    search_a_value(5);
    search_a_value(0);

    return 0;

}

