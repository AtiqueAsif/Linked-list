#include <stdio.h>
#include <stdlib.h>

// Deleting from linked list

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void delete_at_start() {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete at start.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete at end.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteNodeAtGivenPosition(int position) {
    if (head == NULL) {
        printf("\nList is empty, nothing to delete.\n");
        return;
    }

    if (position == 0) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *prev = head;
    int count = 0;

    while (prev != NULL && count < position - 1) {
        prev = prev->next;
        count++;
    }

    if (prev->next == NULL) {
        printf("\nInvalid position!\n");
        return;
    }

    struct node *curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

void print_the_list() {
    struct node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(4);
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(1);

    printf("Before deletion:\n");
    print_the_list();

    //delete_at_start();
    //delete_at_end();
    deleteNodeAtGivenPosition(3);

    printf("\nAfter deletions:\n");
    print_the_list();

    return 0;
}
