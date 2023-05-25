#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    struct node* prev;
    int data;
    struct node* next;
};
struct LinkedList{
    struct node* head;
    struct node* tail;
};
struct LinkedList list = {NULL, NULL};



struct LinkedList enqueue(struct LinkedList list, int value){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;


    if (list.head == NULL){
        list.head = temp;
        list.tail = temp;
    } else {
        temp->prev = list.tail;
        list.tail->next = temp;
        list.tail = temp;
    }

    return list;
}

struct LinkedList dequeue(struct LinkedList List){
    if(list.head == NULL){
        printf("The list is empty");
        return list;
    }

    if(list.head->next == NULL){
        free(list.head);
        list.head = NULL;
        list.tail = NULL;
    } else {
        list.tail = list.tail->prev;
        free(list.tail->next);
        list.tail->next = NULL;
    }
    return list;
}

bool empty(struct LinkedList list){
    return (list.head == NULL);
}