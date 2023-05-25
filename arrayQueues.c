#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int queue[256];
int count = 0;

void enqueue(int value){
    queue[count] = value;
    count++;
}

int dequeue(){
    if (count == 0){
        printf("Queue is empty");
        return -1;
    }
    int result = queue[0];
    
    for (int i = 0; i < count - 1; i++){
        queue[i] = queue[i + 1];
    }

    count--;
    return result;
}