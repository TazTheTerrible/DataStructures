#include <stdio.h>
#include <stdlib.h>

// Define the Node datatype with the pointer 'next' pointing to another node
struct Node {
    int data;
    struct Node* next;
};

//Create a node. Data is passed in as a parameter and set to that node's data variable, and the pointer, next, is set to null
struct Node * createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void insertAtBeginning(struct Node** headRef, int data){
    struct Node* newNode = createNode(data);
    newNode-> next = *headRef;
    *headRef = newNode;
};

void insetAtEnd(struct Node** headRef, int data){
    struct Node* newNode = createNode(data);
    if(*headRef == NULL){
        *headRef = newNode;
    } else {
        struct Node* currNode = *headRef;
        while (currNode->next != NULL){
            currNode = currNode-> next;
        }
        currNode->next = newNode;
    }
};

void deleteNode(struct Node** headRef, int data){
    struct Node* currNode = *headRef;
}