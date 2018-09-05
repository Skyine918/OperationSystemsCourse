//
// Created by trov on 05.09.2018.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct List_Node {
    int value;
    struct List_Node* next;
} L_Node;

typedef struct Linked_List {
    L_Node* head;
    unsigned int size;
} LinkedList;

LinkedList* init_list() {

    LinkedList* list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;

    return list;
}

void insert_node(LinkedList* list, int value, int position) {
    L_Node* new = malloc(sizeof(L_Node));
    new->value = value;

    if (list->size == 0) {
        list->head = new;
        list->size++;

        new->next = NULL;

    } else if (position == 0) {
        new->next = list->head;
        list->head = new;
        list->size++;
    } else if (position == list->size + 1) {
        L_Node* curr = list->head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = new;
        list->size++;
    } else if (position <= list->size && position > 0) {
        L_Node* curr = list->head;
        for (int i = 0; i < position - 1; ++i) {
            curr = curr->next;
        }
        L_Node* prev = curr;
        L_Node* next = curr->next;

        prev->next = new;
        new->next = next;

        list->size++;
    } else {
        printf("Wrong position %d\n", position);
    }
}

void delete_node(LinkedList* list, int position) {

    if (list->size == 0) {
        printf("List is empty");
    } else if (position == 1) {
        L_Node* temp = list->head;
        list->head = list->head->next;
        list->size--;

        free(temp);

    } else if (position == list->size && list->size != 1) {
        L_Node* curr = list->head;
        while (curr->next->next != NULL) curr = curr->next;
        L_Node* temp = curr->next;
        curr->next = NULL;
        list->size--;
        free(temp);
    } else if (position <= list->size && position > 0) {
        L_Node* curr = list->head;
        for (int i = 0; i < position - 1; ++i) {
            curr = curr->next;
        }
        L_Node* prev = curr;
        L_Node* next = curr->next;

        prev->next = next;
        free(curr);

        list->size--;
    } else {
        printf("Wrong Position [%d] \n", position);
    }
}

void print_list(LinkedList* list) {
    L_Node* curr = list->head;
    while (curr != NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
}

int main() {

    //list has elements starting from 1 (not 0)
    // if set 0 when insert, then it will push before all elements
    // if set size+1 when insert, then add in the end

    LinkedList* list;
    list = init_list();

    insert_node(list, 5, 3);
    insert_node(list, 4, 1);
    insert_node(list, 3, 3);

    print_list(list);

    delete_node(list, 3);

    print_list(list);

    delete_node(list, 4);
    delete_node(list, -6);
    delete_node(list, 2);
    delete_node(list, 1);
    delete_node(list, 0);


    print_list(list);

    return 0;
}
