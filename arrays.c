#include <stdio.h>

int capacity(int array[]);
int at(int array[], int *length, int index);
void push(int array[], int* length, int element);
void insert(int array[], int *length, int index, int item);
void prepend(int array[], int *length, int item);
int pop(int array[], int *length);
void delete(int array[], int *length, int index);
void remove(int array[], int *length, int item);
int find(int array[], int *length, int item);

int main() {
    int array[]= {1,2,3,4,5};
    int length = 5;
    at(array, &length, 4);
    push(array, &length, 6);
    insert(array, &length, 4, 25);
    prepend(array, &length, 0);
    pop(array, &length);
    delete(array, &length, 3);
    remove(array, &length, 25);
    find(array, &length, 5);

}


int at(int array[], int *length, int index){

    if (index < 0 || index >=length){
        printf("Index is out of bounds\n");
        return -1;
    }
    int result = array[index];
    if (result == 0){
        printf("Array element is empty\n");
        return -1;
    }

    return result;
}

void push(int array[], int* length, int element){
    array[*length] = element;
    (*length)++;

}

void insert(int array[], int *length, int index, int item){
    if (index < 0 || index > *length){
        printf("Invalid Index\n");
        return -1;
    }

    for (int i = *length; i > index; i--){
        array[i] = array[i-1];
    }
    array[index] = item;
    (*length)++;
}

void prepend(int array[], int *length, int item){
    for (int i = *length; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = item;
    (*length)++;
}

int pop(int array[], int *length){
    if (*length == 0){
        printf("Array is empty");
        return -1;
    }

    int result = array[*length -1];
    (*length)--;
    return result;
}

void delete(int array[], int *length, int index){
    if (*length == 0){
        printf("Array is empty");
        return -1;
    }

    if(index < 0 || index >= *length){
    printf("Invalid index");
    return -1;
    }

    for (int i = index; i < *length -1; i++){
        array[i] = array[i+1];
    }
    (*length)--;
}

void remove(int array[], int *length, int item){
    for(int i = 0; i < *length; i++){
        if (array[i] == item){
            delete(array, length, i);
        }
    }
}

int find(int array[], int *length, int item){
    for(int i = 0; i < *length; i++){
        if (array[i] == item){
            return i;
        }
    }
}